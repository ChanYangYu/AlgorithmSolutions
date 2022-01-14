/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    const str = s.toLowerCase();
    const word = s.toLowerCase().replace(/[^a-z0-9]/g, '');
    let left = 0;
    let right = word.length - 1;
    
    while(left <= right){
        if(word[left] !== word[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
};