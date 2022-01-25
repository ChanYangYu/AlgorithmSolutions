/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */

/*
  Ǯ��
   - �׵θ����� �����ϳ��� rotation ��Ű��,
     ���η� ���鼭 (x, y�� �밢������ �̵�) ���� rotation
*/

const rotate = (matrix) => {
    let n = matrix.length - 1;
    let y = 0, x = 0;
    let cur, next;
        
    while(n > 0){
        let ry = 0, rx = n;
        
        for(let i = 0; i < n; i++){
            // ù��° ���� �ٲ���� ��ġ�� ����
            next = matrix[y + ry][x + rx];
            matrix[y + ry][x + rx] = matrix[y][x];
            
            // �ι�° ���� �ٲ���� ��ġ�� ����
            cur = next;
            next = matrix[y + ry + rx][x + rx - ry];
            matrix[y + ry + rx][x + rx - ry] = cur;
            
            // ����° ���� �ٲ���� ��ġ�� ����
            cur = next;
            next = matrix[y + rx][x - ry];
            matrix[y + rx][x - ry] = cur;
            
            
            // ������ ���� ��ġ ����
            matrix[y][x] = next;
            
            ry++;
            rx--;
            x++;
        }
        
        // y, x �밢������ ���� ex) 0,0 -> 1,1 -> 2,2 ...
        y++;
        x = y;
        n -= 2;
    }
    
};
