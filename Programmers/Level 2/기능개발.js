const solution = (progresses, speeds) => {
    const answer = [];
    let days = 0;
    
    while(progresses.length > 0){
        // 가장 첫번째 프로세스 선택
        const speed = speeds.shift();
        let progress = progresses.shift() + speed * days;
        
        // 프로세스 완료될때까지 day 카운팅
        if(progress < 100){
            while(progress < 100){
                days++;
                progress += speed;
            }
        }
        
        // 첫번째 프로세스 하나만 완료된 상태
        let cnt = 1;
        
        // 다음 프로세스 중 완료된 하위 프로세스 체크
        while(progresses.length > 0){
            const nextProgress = progresses[0] + speeds[0] * days;
            
            if(nextProgress < 100){
                break;
            }
            else{
                cnt++;
                progresses.shift();
                speeds.shift();
            }
        }
        
        // 배포된 기능 배열에 저장
        answer.push(cnt);        
    }
    return answer;
}