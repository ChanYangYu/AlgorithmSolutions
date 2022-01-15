/**
 * @param {string} s
 * @return {number}
 */

const solve = (cur, s, cache) =>{
    if(cur === s.length) return 1;
    
    if(cache[cur] !== -1) return cache[cur];

    if(s[cur] === '0') return 0;
    
    cache[cur] = solve(cur+1, s, cache);
    
    if(cur+1 < s.length){
        const num = Number(s.slice(cur, cur+2));
        
        if(num <= 26) cache[cur] += solve(cur+2, s, cache);
    }
    
    return cache[cur];
}

const numDecodings = (s) => {
    const cache = new Array(101).fill(-1);
    return solve(0, s, cache);
};