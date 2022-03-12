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


var sortList = function(head) {
    const res = [];
    let cur, i;
    
    cur = head;
    while(cur !== null){
        res.push(cur.val);
        cur = cur.next;
    }  
    res.sort((a, b) => a - b);

    cur = head;
    i = 0;
    while(cur !== null){
        cur.val = res[i];
        i++;
        cur = cur.next;
    }
    
    return head;
};