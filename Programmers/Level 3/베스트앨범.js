function solution(genres, plays) {
    var answer = [];
    
    const n = genres.length;
    const sum = {};
    const genreMap = {};
    
    for(let i = 0; i < n; i++){
        const genre = genres[i];
        const play = plays[i];
        
        if(sum[genre] === undefined){
            sum[genre] = play;
        }
        else{
            sum[genre] += play;
        }
        
        if(genreMap[genre] === undefined){
            genreMap[genre] = [[play, i]];
        }
        else{
            genreMap[genre].push([play,i]);
        }
    }
    
    const sumArray = [];
    for(let key in sum){
        sumArray.push([sum[key], key]);
    }
    sumArray.sort((a, b) => b[0] - a[0]);
    
    sumArray.forEach(([sum, key]) => {
        genreMap[key].sort((a, b) => b[0] - a[0]);
        
        if(genreMap[key].length === 1){
            answer.push(genreMap[key][0][1]);
        }
        else{
            answer.push(genreMap[key][0][1]);
            answer.push(genreMap[key][1][1]);
        }
    })
    return answer;
}