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
    bool hasCycle(ListNode* head) {
        ListNode* curr = head;
        set<ListNode*> st;
        while(curr){
            if(st.contains(curr)){
                return true;
            } else{
                st.insert(curr);
            }
            curr = curr->next;
        }

        return false;
        
    }
};
