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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        ListNode* tmp = head;
        int sz = 0;
        
        while(tmp != NULL){
            sz++;
            tmp = tmp->next;
        }
        int target = sz - n;
        int idx = 0;
        while(cur != NULL){
            if(idx == target){
                if(prev == NULL)
                    head = head->next;
                else if(cur->next == NULL)
                    prev->next = NULL;
                else
                    prev->next = cur->next;
                break;
            }
            idx++;
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
