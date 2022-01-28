/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    let cur = head;
    
    
    while(cur !== null){
        const first = cur;
        const second = cur.next;
        
        if(second === null)
            break;
        
        const tmp = first.val;
        first.val = second.val;
        second.val = tmp;
        
        cur = second.next;
    }
    
    return head;
};