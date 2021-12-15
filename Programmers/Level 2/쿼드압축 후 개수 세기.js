const res = [0,0];
function recur(y, x, s, arr){
    if(s === 1){
        const number = arr[y][x];
        res[number]++;
        return number;
    }
    else{
        const cnt = [0,0];
        const newSize = s/2;
        for(let i = 0; i < 2; i++){
            for(let j = 0; j < 2; j++){
                const number = recur(y+(newSize*i), x+(newSize*j), newSize, arr);
                if(number !== -1){
                    cnt[number]++;
                }
            }
        }
        if(cnt[0] === 4){
            res[0] -= 3;
            return 0;
        }
        else if(cnt[1] === 4){
            res[1] -= 3;
            return 1;
        }
        else{
            return -1;
        }
    }
}

function solution(arr) {
    recur(0,0,arr.length, arr);
    return res;
}