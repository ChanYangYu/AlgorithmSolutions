function solution(record) {
    var answer = [];
    const mp = {};
    
    record.forEach((str) => {
        const [cmd, id, name] = str.split(' ');
        
        if(cmd !== 'Leave')
            mp[id] = name;
    });
    
    record.forEach((str) => {
        const [cmd, id, name] = str.split(' ');
        
        if(cmd === 'Enter')
            answer.push(`${mp[id]}님이 들어왔습니다.`);
        else if(cmd === 'Leave')
            answer.push(`${mp[id]}님이 나갔습니다.`);
    })
    return answer;
}