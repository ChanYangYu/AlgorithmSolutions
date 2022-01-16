/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */

const dy = [-1,1,0,0];
const dx = [0,0,-1,1];
let check;
let b, w;
let m, n;

const backTracking = (y, x, idx) => {
    if(idx === w.length){
        return true;
    }
    
    for(let i = 0; i < 4; i++){
        const yy = dy[i] + y;
        const xx = dx[i] + x;
        
        if(yy < 0 || yy >= m || xx < 0 || xx >= n)
            continue;
        if(check[yy][xx])
            continue;
        if(b[yy][xx] !== w[idx])
            continue;
        check[yy][xx] = true;
        
        if(backTracking(yy, xx, idx+1))
            return true;
        check[yy][xx] = false;
    }
    
    return false;
}

const exist = (board, word) => {
    check = Array.from(new Array(7), () => new Array(7).fill(false));
    b = board;
    w = word;
    m = board.length;
    n = board[0].length;
    
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(w[0] !== b[i][j])
                continue;
            check[i][j] = true;
            if(backTracking(i, j, 1))
                return true;
            check[i][j] = false;
        }
    }
    
    return false;
};