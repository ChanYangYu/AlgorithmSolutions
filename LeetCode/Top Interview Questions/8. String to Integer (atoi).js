/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    const mn = -(2**31);
    const mx = 2**31 -1;
    let res = '';
    let idx = 0;
    
    while(s[idx] === ' '){
        idx++;
    }
    if(s[idx] === '-' || s[idx] === '+'){
        res += s[idx];
        idx++;
    }
    
    while(s[idx] >= '0' && s[idx] <= '9'){
        res += s[idx];
        idx++;
    }
    
    if(res.length === 1 && (res[0] === '-' || res[0] === '+')){
        return 0;
    }
    
    const ret = Number(res);
    
    if(mx < res){
        return mx;
    }
    else if(mn > res){
        return mn;
    }
    else{
        return ret;
    }
    
};