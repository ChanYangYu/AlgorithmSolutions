/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    const size = needle.length;
    
    for(let i = 0; i <= haystack.length-size; i++){
        if(needle === haystack.slice(i, i+size)){
            return i;
        }
    }
    
    return -1;
};