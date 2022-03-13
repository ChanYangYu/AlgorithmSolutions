function solution(n) {
    const arr = Array.from(Array(n+1), () =>  new Array(2));
    let answer = [];
    let cnt = n;
    let floor = 0;
    let cur = 1;
    
    while(cnt > 0){
        for(let i = 0; i < cnt; i++){
            floor++;
            if(arr[floor][0] === undefined)
                arr[floor][0] = [];
            arr[floor][0].push(cur);
            cur++;
        }
        cnt--;
        for(let i = 0; i < cnt; i++){
            if(arr[floor][0] === undefined)
                arr[floor][0] = [];
            arr[floor][0].push(cur);
            cur++;
        }
        cnt--;
        
        for(let i = 0; i < cnt; i++){
            floor--;
            if(arr[floor][1] === undefined)
                arr[floor][1] = [];
            arr[floor][1].push(cur);
            cur++;
        }
        cnt--;
    }
    
    for(let i = 1; i <= n; i++){
        answer = [...answer, ...arr[i][0]];
        
        if(arr[i][1] === undefined)
            continue;
        while(arr[i][1].length > 0){
            answer.push(arr[i][1].pop());
        }
    }
    return answer;
}