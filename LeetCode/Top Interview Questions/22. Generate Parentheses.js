/**
 * @param {number} n
 * @return {string[]}
 */


const solve = (res, cur, str, cnt) => {
    if(cnt === 0){
        while(cur > 0){
            str += ')';
            cur--;
        }
        res.push(str);
        return;
    }
    
    solve(res, cur + 1, str + '(', cnt-1);
    
    if(cur > 0) 
        solve(res, cur - 1, str + ')', cnt);
}

const generateParenthesis = (n) => {
    const res = [];
    
    solve(res, 0, '', n);
    
    return res;
};