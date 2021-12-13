function solution(n, edge) {
    const q = [];
    const ch = Array(n+1).fill(0);
    const mapping = {};
    
    edge.forEach(([a, b]) =>{
        if(mapping[a] === undefined)
            mapping[a] = [b];
        else
            mapping[a].push(b);
        
        if(mapping[b] === undefined)
            mapping[b] = [a];
        else
            mapping[b].push(a);
    })
    
    q.push([1,1]);
    ch[1] = 1;
    
    while(q.length > 0){
        const [idx, cnt] = q.shift();
        
        mapping[idx].forEach((next) =>{
            if(ch[next] === 0){
                ch[next] = cnt+1;
                q.push([next, cnt+1]);
            }
        })
    }
    
    const mx = ch.reduce((prev, cur) => (prev < cur) ? cur : prev);
    const answer = ch.reduce((prev, cur) => (cur === mx) ? prev+1 : prev, 0);
    return answer;
}