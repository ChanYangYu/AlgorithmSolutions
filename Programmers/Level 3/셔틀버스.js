/*
 1. 초단위로 timetable 변경
 2. n-1개의 버스를 보내면서 대기큐에 있는 승객을 처리
 3. 마지막 버스에서 가장 마지막에 타는 경우 탐색
    - 좌석이 남는경우 버스도착 시간과 일치
    - 좌석이 안남는 경우 마지막에 타는사람보다 1분 앞선 시간(동일시간일 경우 마지막에 줄 서기 때문)
 4. 단위 변환후 출력
*/
function solution(n, t, m, timetable) {
    var answer = '';
    
    const times = timetable.map((time) => Number(time.slice(0,2))*60 + Number(time.slice(3,5)));
    const waitQueue = times.sort((a, b) => a-b);
    const start = 9*60;
    
    for(let i = 0; i < n-1; i++){
        const cur = start + i * t;
        let remain = m;
        
        while(remain > 0 && waitQueue.length > 0 && waitQueue[0] <= cur){
            waitQueue.shift();
            remain--;
        }
    }
    
    //last bus
    const cur = start + (n-1) * t;
    let remain = m;
    let last = -1;
    while(remain > 0 && waitQueue.length > 0 && waitQueue[0] <= cur){
        last = waitQueue.shift();
        remain--;
    }
    
    const res = (remain === 0) ? last-1 : cur;
    const hh = `0${Math.floor((res)/60)}`.slice(-2);
    const mm = `0${(res)%60}`.slice(-2);
    return hh+":"+mm;
}