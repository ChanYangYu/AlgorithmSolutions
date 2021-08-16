/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> lst;
        unordered_map<Node*, int> ptr2idx;
        Node* cur = head;
        Node* prev = NULL;
        Node* new_head = NULL;
        
        int idx = 0;
        while(cur != NULL){
            Node* n = new Node(cur->val);
            if(prev != NULL)
                prev->next = n;
            if(new_head == NULL)
                new_head = n;
            
            ptr2idx[cur] = idx;
            lst.push_back(n);
            cur = cur->next;
            prev = n;
            idx++;
        }
        
        cur = head;
        idx = 0;
        while(cur != NULL){
            if(cur->random != NULL){
                int target = ptr2idx[cur->random];
                lst[idx]->random = lst[target];
            }
            
            cur = cur->next;
            idx++;
        }
        
        return new_head;
    }
};
