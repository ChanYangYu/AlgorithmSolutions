function solution(s) {
    const answer = [];
    const tupples = s.slice(1, s.length-1).split(/},/).map((str) => str.replace(/[{}]/g,'').split(','));
    const sorted = tupples.sort((a, b) => a.length - b.length);
    const hit = {};
    sorted.forEach((set) =>{
        set.forEach((val)=> {
            if(hit[val] === undefined){
                hit[val] = true;
                answer.push(Number(val));
            }
        })
    })
    return answer;
}