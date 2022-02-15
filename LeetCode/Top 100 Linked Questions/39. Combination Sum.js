/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */

 let cand, tar, res;

 const combination = (sum, idx, state) => {
     if(idx === cand.length || sum > tar){
         return;
     }
     
     if(sum === tar){
         if(!res.some((arr) => arr.every((num, i) => num === state[i]))){
             res.push(state);
         }
         return;
     }
     
     combination(sum + cand[idx], idx, [...state, cand[idx]]);
     combination(sum + cand[idx], idx+1, [...state, cand[idx]]);
     combination(sum, idx+1, [...state]);
 }
 
 const combinationSum = (candidates, target) => {
     res = [];
     cand = candidates;
     tar = target;
     
     combination(0, 0, []);
     return res;
 };