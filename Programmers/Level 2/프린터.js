function solution(priorities, location) {
    var answer = 0;
    const check = new Array(100).fill(false);
    const queue = priorities.map((prio, idx) => [prio, idx]);
    const sortedPrio = [...queue].sort((a, b) => b[0] - a[0])
    
    
    while(queue.length > 0){
        const [prio, idx] = queue.shift();
        const highPrio = sortedPrio[0][0];
        
        if(prio < highPrio)
            queue.push([prio, idx]);
        else{
            check[idx] = true;
            answer++;
            
            if(idx === location)
                return answer;
        }
        
        while(sortedPrio.length > 0){
            const highIdx = sortedPrio[0][1];
            
            if(check[highIdx] === false)
                break;
            sortedPrio.shift();
        }
    }
    return answer;
}