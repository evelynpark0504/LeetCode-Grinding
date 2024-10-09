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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        if (l1->next==nullptr&&l2->next==nullptr) {
            if (l1->val + l2->val < 10) {
                l1->val = l1->val + l2->val;
            } else {
                l1->val = l1->val + l2->val - 10;
                l1->next = new ListNode(1);
            }
            return l1;
        }

        ListNode *ans = new ListNode();
        ListNode *curr = ans;

        while (l1 && l2) {
            curr->next = new ListNode();
            curr = curr->next;

            if (l1->val + l2->val + carry < 10) {
                curr->val = l1->val + l2->val + carry;
                carry = 0;
            } else {
                curr->val = l1->val + l2->val + carry - 10;
                carry = 1;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1!=nullptr) {
            while(l1) {
                curr->next = new ListNode();
                curr = curr->next;
                if (l1->val + carry < 10) {
                    curr->val = l1->val + carry;
                    carry = 0;
                } else {
                    curr->val = l1->val + carry - 10;
                    carry = 1;
                }
                l1=l1->next;
            }
        }

        if (l2!=nullptr) {
            while(l2) {
                curr->next = new ListNode();
                curr = curr->next;
                if (l2->val + carry < 10) {
                    curr->val = l2->val + carry;
                    carry = 0;
                } else {
                    curr->val = l2->val + carry - 10;
                    carry = 1;
                }
                l2=l2->next;
            }
        }

        if (carry!=0) {
            curr->next = new ListNode(1);
            curr = curr->next;
        }

        return ans->next;
    }
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;  // Initialize carry to 0
        ListNode* ans = new ListNode(0);  // Dummy node to start the result linked list
        ListNode* curr = ans;  // Pointer to track the current position in the result list
        
        // Traverse both lists until both are NULL
        while (l1 != nullptr || l2 != nullptr) {
            int x = (l1 != nullptr) ? l1->val : 0;  // Get l1's value, or 0 if l1 is NULL
            int y = (l2 != nullptr) ? l2->val : 0;  // Get l2's value, or 0 if l2 is NULL
            int sum = x + y + carry;  // Sum of l1's value, l2's value, and carry
            
            carry = sum / 10;  // Update carry
            curr->next = new ListNode(sum % 10);  // Create a new node with the digit
            
            curr = curr->next;  // Move the current pointer to the next node
            
            // Move to the next node in both lists
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        // After the loop, if there's any remaining carry, add a new node
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }
        
        return ans->next;  // Return the next node of the dummy node, which is the head of the result list
    }
};