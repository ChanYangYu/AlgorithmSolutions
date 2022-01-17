/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
const moveZeroes = (nums) => {
    // const zeros = nums.filter((val) => val === 0);
    // const notZeros = nums.filter((val) => val !== 0);
    let cnt = 0;
    let len = nums.length;
    
    for(let i = 0; i < len; i++){
        let num = nums.shift();
        
        if(num === 0)
            cnt++;
        else
            nums.push(num);
    }
    
    for(let i = 0; i < cnt; i++)
        nums.push(0);
};