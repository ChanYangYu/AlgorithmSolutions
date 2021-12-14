function solution(maps) {
    const dy = [-1,1,0,0];
    const dx = [0,0,-1,1];
    const n = maps.length;
    const m = maps[0].length;
    const ch = Array.from(Array(n),() => Array(m).fill(0));
    const q = [];
    
    q.push([0,0]);
    ch[0][0] = 1;
    
    while(q.length > 0){
        const [y, x] = q.shift();
        
        for(let i = 0; i < 4; i++){
            const yy = y + dy[i];
            const xx = x + dx[i];
            
            if(yy < 0 || yy >= n || xx < 0 || xx >= m)
                continue;
            if(ch[yy][xx] !== 0 || maps[yy][xx] === 0)
                continue;
            ch[yy][xx] = ch[y][x] + 1;
            q.push([yy, xx]);
        }
    }
    
    const answer = ch[n-1][m-1] !== 0 ? ch[n-1][m-1] : -1;
    return answer;
}