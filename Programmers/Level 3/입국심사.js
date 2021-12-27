function solution(n, times) {
    var answer = 0;
    let left = 0;
    let right = 1e19;
    
    
    while(left < right){
        const mid = Math.floor((left + right) / 2);
        let possible = 0;
        
        times.forEach((time) =>{
            possible += Math.floor(mid / time);    
        });
        
        if(possible >= n){
            right = mid;
        }
        else{
            left = mid+1;
        }
    }
    
    return left;
}