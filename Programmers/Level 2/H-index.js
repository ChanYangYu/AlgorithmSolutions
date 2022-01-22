function solution(citations) {
    var answer = 0;
    const sum = new Array(10001).fill(0);
    
    citations.forEach(num => sum[num]++);
    
    let cnt = 0;
    for(let i = 10000; i >= 0; i--){
        sum[i] += cnt;
        if(sum[i] >= i){
            return i;
        }
        cnt = sum[i];
        
    }
}