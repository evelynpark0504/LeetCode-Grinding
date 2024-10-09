import torch
import math

# Positional Encoding
class PositionalEncoding(torch.nn.Module):
    def __init__(self, d_model, max_len=5000):
        super(PositionalEncoding, self).__init__()
        pe = torch.zeros(max_len, d_model)
        position = torch.arange(0, max_len, dtype=torch.float).unsqueeze(1)
        div_term = torch.exp(torch.arange(0, d_model, 2).float() * (-math.log(10000.0) / d_model))
        pe[:, 0::2] = torch.sin(position * div_term)
        pe[:, 1::2] = torch.cos(position * div_term)
        pe = pe.unsqueeze(0).transpose(0, 1)
        self.register_buffer('pe', pe)

    def forward(self, x):
        return x + self.pe[:x.size(0), :]

# Scaled Dot-Product Attention
def scaled_dot_product_attention(query, key, value, mask=None):
    d_k = query.size(-1)
    scores = torch.matmul(query, key.transpose(-2, -1)) / math.sqrt(d_k)

    if mask is not None:
        scores = scores.masked_fill(mask == 0, -1e9)

    attention_weights = torch.nn.functional.softmax(scores, dim=-1)
    return torch.matmul(attention_weights, value), attention_weights

# Multi-Head Attention
class MultiHeadAttention(torch.nn.Module):
    def __init__(self, d_model, num_heads):
        super(MultiHeadAttention, self).__init__()
        assert d_model % num_heads == 0
        self.d_k = d_model // num_heads
        self.num_heads = num_heads
        
        self.linear_q = torch.nn.Linear(d_model, d_model)
        self.linear_k = torch.nn.Linear(d_model, d_model)
        self.linear_v = torch.nn.Linear(d_model, d_model)
        self.fc_out = torch.nn.Linear(d_model, d_model)

    def forward(self, query, key, value, mask=None):
        batch_size = query.size(0)

        # Linear projections
        query = self.linear_q(query).view(batch_size, -1, self.num_heads, self.d_k).transpose(1, 2)
        key = self.linear_k(key).view(batch_size, -1, self.num_heads, self.d_k).transpose(1, 2)
        value = self.linear_v(value).view(batch_size, -1, self.num_heads, self.d_k).transpose(1, 2)

        # Scaled dot-product attention
        attn_values, attention_weights = scaled_dot_product_attention(query, key, value, mask)

        # Concatenate heads
        attn_values = attn_values.transpose(1, 2).contiguous().view(batch_size, -1, self.num_heads * self.d_k)

        return self.fc_out(attn_values)

# Feed-Forward Network
class FeedForwardNetwork(torch.nn.Module):
    def __init__(self, d_model, d_ff):
        super(FeedForwardNetwork, self).__init__()
        self.fc1 = torch.nn.Linear(d_model, d_ff)
        self.fc2 = torch.nn.Linear(d_ff, d_model)

    def forward(self, x):
        return self.fc2(torch.nn.functional.relu(self.fc1(x)))

# Encoder Layer
class EncoderLayer(torch.nn.Module):
    def __init__(self, d_model, num_heads, d_ff, dropout=0.1):
        super(EncoderLayer, self).__init__()
        self.mha = MultiHeadAttention(d_model, num_heads)
        self.ffn = FeedForwardNetwork(d_model, d_ff)

        self.layernorm1 = torch.nn.LayerNorm(d_model)
        self.layernorm2 = torch.nn.LayerNorm(d_model)

        self.dropout = torch.nn.Dropout(dropout)

    def forward(self, x, mask):
        attn_output = self.mha(x, x, x, mask)
        out1 = self.layernorm1(x + self.dropout(attn_output))
        ffn_output = self.ffn(out1)
        out2 = self.layernorm2(out1 + self.dropout(ffn_output))
        return out2

# Encoder
class Encoder(torch.nn.Module):
    def __init__(self, d_model, num_heads, d_ff, num_layers, input_vocab_size, max_len, dropout=0.1):
        super(Encoder, self).__init__()
        self.embedding = torch.nn.Embedding(input_vocab_size, d_model)
        self.pos_encoding = PositionalEncoding(d_model, max_len)
        self.enc_layers = torch.nn.ModuleList([EncoderLayer(d_model, num_heads, d_ff, dropout) for _ in range(num_layers)])
        self.dropout = torch.nn.Dropout(dropout)

    def forward(self, x, mask):
        x = self.embedding(x)
        x = self.pos_encoding(x)
        x = self.dropout(x)

        for layer in self.enc_layers:
            x = layer(x, mask)

        return x

# Decoder Layer
class DecoderLayer(torch.nn.Module):
    def __init__(self, d_model, num_heads, d_ff, dropout=0.1):
        super(DecoderLayer, self).__init__()
        self.mha1 = MultiHeadAttention(d_model, num_heads)
        self.mha2 = MultiHeadAttention(d_model, num_heads)
        self.ffn = FeedForwardNetwork(d_model, d_ff)

        self.layernorm1 = torch.nn.LayerNorm(d_model)
        self.layernorm2 = torch.nn.LayerNorm(d_model)
        self.layernorm3 = torch.nn.LayerNorm(d_model)

        self.dropout = torch.nn.Dropout(dropout)

    def forward(self, x, enc_output, src_mask, tgt_mask):
        attn1 = self.mha1(x, x, x, tgt_mask)
        out1 = self.layernorm1(x + self.dropout(attn1))

        attn2 = self.mha2(out1, enc_output, enc_output, src_mask)
        out2 = self.layernorm2(out1 + self.dropout(attn2))

        ffn_output = self.ffn(out2)
        out3 = self.layernorm3(out2 + self.dropout(ffn_output))

        return out3

# Decoder
class Decoder(torch.nn.Module):
    def __init__(self, d_model, num_heads, d_ff, num_layers, target_vocab_size, max_len, dropout=0.1):
        super(Decoder, self).__init__()
        self.embedding = torch.nn.Embedding(target_vocab_size, d_model)
        self.pos_encoding = PositionalEncoding(d_model, max_len)
        self.dec_layers = torch.nn.ModuleList([DecoderLayer(d_model, num_heads, d_ff, dropout) for _ in range(num_layers)])
        self.fc_out = torch.nn.Linear(d_model, target_vocab_size)
        self.dropout = torch.nn.Dropout(dropout)

    def forward(self, x, enc_output, src_mask, tgt_mask):
        x = self.embedding(x)
        x = self.pos_encoding(x)
        x = self.dropout(x)

        for layer in self.dec_layers:
            x = layer(x, enc_output, src_mask, tgt_mask)

        return self.fc_out(x)

# Transformer Model
class Transformer(torch.nn.Module):
    def __init__(self, src_vocab_size, tgt_vocab_size, d_model=512, num_heads=8, d_ff=2048, num_layers=6, max_len=100, dropout=0.1):
        super(Transformer, self).__init__()
        self.encoder = Encoder(d_model, num_heads, d_ff, num_layers, src_vocab_size, max_len, dropout)
        self.decoder = Decoder(d_model, num_heads, d_ff, num_layers, tgt_vocab_size, max_len, dropout)

    def forward(self, src, tgt, src_mask, tgt_mask):
        enc_output = self.encoder(src, src_mask)
        output = self.decoder(tgt, enc_output, src_mask, tgt_mask)
        return output

# Masks for Padding
def create_padding_mask(seq):
    return (seq == 0).unsqueeze(1).unsqueeze(2)

def create_look_ahead_mask(size):
    mask = torch.triu(torch.ones(size, size), 1)
    return mask == 1

# Example Usage
src_vocab_size = 10000  # Example source vocabulary size
tgt_vocab_size = 10000  # Example target vocabulary size

transformer = Transformer(src_vocab_size, tgt_vocab_size)

src = torch.randint(0, src_vocab_size, (32, 10))  # Example source input (batch_size=32, sequence_length=10)
tgt = torch.randint(0, tgt_vocab_size, (32, 10))  # Example target input

src_mask = create_padding_mask(src)
tgt_mask = create_look_ahead_mask(tgt.size(1))

output = transformer(src, tgt, src_mask, tgt_mask)
print(output.shape)  # Output shape will be (batch_size, target_seq_len, target_vocab_size)
