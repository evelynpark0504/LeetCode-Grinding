/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(lists.size()) return NULL;
        priority_queue<ListNode*, vector<ListNode*>,Compare>mp;
        ListNode* temp = new ListNode(-1);
        ListNode* ans = temp;
        for(auto list:lists){
            if(list) mp.push(list);
        }
        while(!mp.empty()){
            auto node = mp.top();
            mp.pop();
            temp->next = node;
            temp = temp->next;
            if(node->next){
                mp.push(node->next);
            }
        }
        return ans->next;
    }
};