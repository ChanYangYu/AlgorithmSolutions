/**
 * @param {string[]} strs
 * @return {string}
 */
const longestCommonPrefix = (strs) => {
    const minStr = strs.reduce((prev, cur) => (prev.length > cur.length) ? cur : prev);
    let answer = "";
    
    for(let i = 0; i < minStr.length; i++){
        const cur = minStr[i];
        
        if(strs.some(str => str[i] !== cur))
            return answer;
        answer += cur;
    }
    
    return answer;
};