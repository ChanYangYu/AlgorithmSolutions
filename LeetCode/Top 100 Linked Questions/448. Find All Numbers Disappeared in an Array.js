/**
 * @param {number[]} nums
 * @return {number[]}
 */
 var findDisappearedNumbers = function(nums) {
    const check = new Array(nums.length+1).fill(false);
    const ret = [];
    
    nums.forEach(val => check[val] = true);
    
    for(let i = 1; i <= nums.length; i++){
        if(check[i] === false)
            ret.push(i);
    }
    
    return ret;
    
};