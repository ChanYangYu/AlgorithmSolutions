/* 오답노트
    1. 로직에서 continue와 break을 잘못 사용하였다.
    2. down함수에서 pos를 --해야할것을 ++하여 오류가 발생하였다.
*/
const search = (m, n, board) => {
    const ch = Array.from(new Array(m), () => new Array(n).fill(0));
    const dy = [0,1,0,1];
    const dx = [0,0,1,1];
    
    let cnt = 0;
    for(let i = 0; i < m; i++){
        if(i+1 === m)
            break;
        for(let j = 0; j < n; j++){
            if(j+1 === n)
                break;
            if(board[i][j] === ' ')
                continue;
            const cur = board[i][j];
            let check = true;
            
            for(let k = 0; k < 4; k++){
                const yy = i + dy[k];
                const xx = j + dx[k];
                
                if(cur !== board[yy][xx]){
                    check = false;
                    break;
                }
            }
            if(check === false)
                continue;
            
            for(let k = 0; k < 4; k++){
                const yy = i + dy[k];
                const xx = j + dx[k];
                
                if(ch[yy][xx] === 0)
                    cnt++;
                ch[yy][xx] = 1;
            }
        }
    }
    
    for(let i = 0; i < m; i++){
        for(let j = 0; j < n; j++){
            if(ch[i][j] === 1){
                board[i][j] = ' ';
            }
        }
    }
    
    return cnt;
}

const down = (m, n, board) => {
    for(let j = 0; j < n; j++){
        let pos = -1;
        for(let i = m-1; i >= 0; i--){
            if(pos === -1 && board[i][j] === ' '){
                pos = i;
            }
            else if(pos !== -1 && board[i][j] !== ' '){
                board[pos][j] = board[i][j];
                board[i][j] = ' ';
                pos--;
            }
        }
    }
}

const solution = (m, n, board) => {
    let answer = 0;
    const boardArr = board.map((line) => line.split(''));
    
    while(true){
        const cnt = search(m, n, boardArr);
        if(cnt === 0)
            break;
        answer += cnt;
        down(m, n, boardArr);
    }
    return answer;
}