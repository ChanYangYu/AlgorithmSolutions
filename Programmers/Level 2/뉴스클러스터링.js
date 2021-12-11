function solution(str1, str2) {
    var answer = 0;
    const s1 = str1.toUpperCase();
    const s2 = str2.toUpperCase();
    
    const set1 = [];
    const set2 = [];
    
    for(let i = 0; i < s1.length-1; i++){
        if(s1[i] < 'A' || s1[i] > 'Z')
            continue;
        if(s1[i+1] < 'A' || s1[i+1] > 'Z')
            continue;
        set1.push(s1[i]+s1[i+1]);
    }
    
    for(let i = 0; i < s2.length-1; i++){
        if(s2[i] < 'A' || s2[i] > 'Z')
            continue;
        if(s2[i+1] < 'A' || s2[i+1] > 'Z')
            continue;
        set2.push(s2[i]+s2[i+1]);
    }
    
    if(set1.length === 0 && set2.length === 0)
        return 65536;
    
    set1.sort();
    set2.sort();
    
    const n = [];
    const u = [];
    
    let j = 0;
    for(let i = 0; i < set1.length; i++){
        while(j < set2.length && set1[i] > set2[j]) j++;
        if(set1[i] === set2[j]){
            n.push(set1[i]);
            j++;
        }
    }
    
    j = 0;
    for(let i = 0; i < set1.length; i++){
        while(j < set2.length && set1[i] > set2[j]){
            u.push(set2[j]);
            j++;
        }
        
        if(set1[i] === set2[j]){
            u.push(set1[i]);
            j++;
        }
        else{
            u.push(set1[i]);
        }
    }
    
    while(j < set2.length){
        u.push(set2[j]);
        j++;
    }
    
    answer = Math.floor(n.length/u.length * 65536);
    return answer;
}