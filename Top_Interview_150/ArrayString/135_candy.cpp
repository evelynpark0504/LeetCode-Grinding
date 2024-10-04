class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==1) return 1;

        vector<int> candies(n, 1);

        // Left to Right Pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to Left Pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Calculate the total candies
        int totalCandies = accumulate(candies.begin(), candies.end(), 0);
        return totalCandies;
    }
};