/**
 * @param {string[]} strs
 * @return {string[][]}
 */
const groupAnagrams = (strs) => {
    const mp = {};
    const res = [];
    strs.forEach(str => {
        const key = str.split('').sort().join('');
        
        if(mp[key] === undefined)
            mp[key] = [str];
        else
            mp[key].push(str);
    });
    
    for(let key in mp)
        res.push(mp[key]);
    return res;  
};