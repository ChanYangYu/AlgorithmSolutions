/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */

/*
  풀이
   - 테두리부터 원소하나씩 rotation 시키고,
     내부로 들어가면서 (x, y를 대각선으로 이동) 내부 rotation
*/

const rotate = (matrix) => {
    let n = matrix.length - 1;
    let y = 0, x = 0;
    let cur, next;
        
    while(n > 0){
        let ry = 0, rx = n;
        
        for(let i = 0; i < n; i++){
            // 첫번째 원소 바꿔야할 위치로 변경
            next = matrix[y + ry][x + rx];
            matrix[y + ry][x + rx] = matrix[y][x];
            
            // 두번째 원소 바꿔야할 위치로 변경
            cur = next;
            next = matrix[y + ry + rx][x + rx - ry];
            matrix[y + ry + rx][x + rx - ry] = cur;
            
            // 세번째 원소 바꿔야할 위치로 변경
            cur = next;
            next = matrix[y + rx][x - ry];
            matrix[y + rx][x - ry] = cur;
            
            
            // 마지막 원소 위치 변경
            matrix[y][x] = next;
            
            ry++;
            rx--;
            x++;
        }
        
        // y, x 대각선으로 설정 ex) 0,0 -> 1,1 -> 2,2 ...
        y++;
        x = y;
        n -= 2;
    }
    
};
