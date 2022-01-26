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
    Ǯ��
    1. ���� ���� ��尡 k�� �̻����� Ȯ��
    2. k�� �̸��̸� Ž�� ����
    3. tmp�� ���� ������ ����
    4. k�� ������ �̵��ϸ鼭 ������ number�� ����
    5. tmp����k�� ������ �̵��ϸ鼭, number�� �ִ� �� pop�Ͽ� val ������Ʈ
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