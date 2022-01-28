/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */

/*
    풀이 O(NlogN)
    1. 뒤에서 부터 한자릿씩 올라오면서 탐색
    2. 만약 현재 자릿수가 뒤의 자릿수 보다 작은 경우
        2-1. 자릿수를 교환한다.
        2-2. 이 후 자릿수들을 arr에 있는 값들로 덮어쓴다.
        2-3. 함수를 종료한다.
    3. 만약 없으면 가장 큰 값이므로 arr에 push한다.
    4. 반복문에서 없는 경우 가장 큰값이므로 오름차순 정렬한다.
    
*/

const binarySearch = (arr, target) => {
    let left = 0;
    let right = arr.length-1;
    let idx = -1;
    
    while(left <= right) {
        let mid = Math.floor((left + right) / 2);
        
        if(arr[mid] > target){
            idx = mid;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    
    return idx;
}

const nextPermutation = (nums) => {
    const n = nums.length;
    const cur = nums.join('');
    
    const arr = [nums[n-1]];
    
    for(let i = n-2; i >= 0; i--){
        const idx = binarySearch(arr, nums[i]);
        
        if(idx !== -1){
            const tmp = nums[i];
            nums[i] = arr[idx];
            arr[idx] = tmp;

            for(let k = i+1; k < n; k++){
                nums[k] = arr.shift();
            }
            return;
        }
        arr.push(nums[i]);
    }
    
    nums.sort((a, b) => a - b);
};