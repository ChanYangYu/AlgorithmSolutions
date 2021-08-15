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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> all;
        ListNode *answer = NULL;
        ListNode* cur = NULL;
        
        for(int i = 0; i < lists.size(); i++){
            ListNode* cur = lists[i];
            
            while(cur != NULL){
                all.push_back(cur->val);
                cur = cur->next;
            }
        }
        sort(all.begin(), all.end());
        
        for(int i = 0; i < all.size(); i++){
            ListNode* n = new ListNode(all[i]);
            
            if(cur == NULL){
                answer = n;
                cur = n;
            }
            else{
                cur->next = n;
                cur = n;
            }
        }
        return answer;
    }
};
