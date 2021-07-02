/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *cur = head;
        
        while(cur != NULL){
            if(cur->val == 987654321)
                return true;
            //check visit
            cur->val = 987654321;
            cur = cur->next;
        }
        return false;
    }
};
