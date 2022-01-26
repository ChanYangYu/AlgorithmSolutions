/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */

/*
    풀이
    1. 먼저 남은 노드가 k개 이상인지 확인
    2. k개 미만이면 탐색 종료
    3. tmp에 현재 포인터 저장
    4. k번 앞으로 이동하면서 값들을 number에 저장
    5. tmp부터k번 앞으로 이동하면서, number에 있는 값 pop하여 val 업데이트
*/

const reverseKGroup = (head, k) => {
    let size = 0;
    let cur = head;
    let idx = 0;
    
    while(cur !== null){
        cur = cur.next;
        size++;
    }
    
    cur = head;
    while(cur !== null){
        const number = [];
        let tmp = cur;
        
        if(size - idx < k)
            break;
        
        for(let i = 0; i < k; i++){
            number.push(cur.val);
            cur = cur.next;
            idx++;
        }
        
        for(let i = 0; i < k; i++){
            tmp.val = number.pop();
            tmp = tmp.next;
        }
        
    }
    
    return head;
};