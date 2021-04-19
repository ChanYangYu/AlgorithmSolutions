#include <bits/stdc++.h>
using namespace std;

class Data{
  public :
    int start;
    int work;
    
    Data(int s, int w){
        start = s;
        work = w;
    }
    bool operator<(const Data &b) const{
        return this->start > b.start;
    }
};

class Data2{
    public :
    int start;
    int work;
    
    Data2(int s, int w){
        start = s;
        work = w;
    }
    bool operator<(const Data2 &b) const{
        return this->work > b.work;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<Data> job_queue;
    priority_queue<Data2> ready_queue;
    
    for(int i = 0; i < jobs.size(); i++){
        int s = jobs[i][0];
        int w = jobs[i][1];
        
        job_queue.push(Data(s,w));
    }

    //time = 최소 시작시간
    int time = 0;
    int res = 0;
    while(!job_queue.empty()){
        //작업은 있지만 현재 시간에는 아무 작업도 없는 경우
        if(ready_queue.empty()){
            //first job -> ready_queue로 이동
            int s = job_queue.top().start;
            int w = job_queue.top().work;
            job_queue.pop();

            ready_queue.push(Data2(s,w));
            //현재 시간과 다음 작업시작 시간중 큰값으로 대체
            time = max(time, s);
        }
        //job_queue에서 현재 시간에서 실행할 수 있는 job -> ready_queue 로 이동
        while(!job_queue.empty() && job_queue.top().start <= time){
            int s = job_queue.top().start;
            int w = job_queue.top().work;

            job_queue.pop();
            ready_queue.push(Data2(s,w));
        }
        
        //최소 수행시간 작업 수행
        int s = ready_queue.top().start;
        int w = ready_queue.top().work;        
        ready_queue.pop();
        
        time += w;
        res += time - s;
        
    }
    
    //ready_queue에 대기하는 작업이 있는 경우
    while(!ready_queue.empty()){
        //최소 수행시간 작업 수행
        int s = ready_queue.top().start;
        int w = ready_queue.top().work;        
        ready_queue.pop();
        
        time += w;
        res += time - s;
    }
    
    int n = jobs.size();
    answer = res / n;
    return answer;
}
