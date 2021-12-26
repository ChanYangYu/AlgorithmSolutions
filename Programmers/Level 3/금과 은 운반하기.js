function solution(a, b, g, s, w, t) {
    let answer = -1;
    const size = g.length;
    let left = 0;
    let right = 2 * 1e9 * 2 * 1e5;
    
    while(left <= right){
        const mid = Math.floor((left + right) / 2);
        const state = {
            gold : 0,
            silver: 0,
            sum : 0, 
        }
        
        
        for(let i = 0; i < size; i++){
            let deliverCnt = Math.floor(mid / (2 * t[i]));
            
            if(mid % (2 * t[i]) >= t[i])
                deliverCnt++;
            state.gold += (w[i] * deliverCnt < g[i]) ? (w[i] * deliverCnt) : g[i];
            state.silver += (w[i] * deliverCnt < s[i]) ? (w[i] * deliverCnt) : s[i];
            state.sum += (w[i] * deliverCnt < g[i] + s[i]) ? w[i] * deliverCnt : g[i] + s[i];
        }
        
        if(state.gold >= a && state.silver >= b && state.sum >= a+b){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    
    
    return left;
}