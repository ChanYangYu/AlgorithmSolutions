function solution(clothes) {
    var answer = 1;
    const mp = {};

    clothes.forEach(([name, category]) => {
        if(mp[category]){
            mp[category].push(name);
        }
        else{
            mp[category] = [name];
        }
    });
    
    for(let category in mp){
        answer *= mp[category].length + 1;
    }
    return answer-1;
}