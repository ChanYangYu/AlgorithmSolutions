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

    //time = �ּ� ���۽ð�
    int time = 0;
    int res = 0;
    while(!job_queue.empty()){
        //�۾��� ������ ���� �ð����� �ƹ� �۾��� ���� ���
        if(ready_queue.empty()){
            //first job -> ready_queue�� �̵�
            int s = job_queue.top().start;
            int w = job_queue.top().work;
            job_queue.pop();

            ready_queue.push(Data2(s,w));
            //���� �ð��� ���� �۾����� �ð��� ū������ ��ü
            time = max(time, s);
        }
        //job_queue���� ���� �ð����� ������ �� �ִ� job -> ready_queue �� �̵�
        while(!job_queue.empty() && job_queue.top().start <= time){
            int s = job_queue.top().start;
            int w = job_queue.top().work;

            job_queue.pop();
            ready_queue.push(Data2(s,w));
        }
        
        //�ּ� ����ð� �۾� ����
        int s = ready_queue.top().start;
        int w = ready_queue.top().work;        
        ready_queue.pop();
        
        time += w;
        res += time - s;
        
    }
    
    //ready_queue�� ����ϴ� �۾��� �ִ� ���
    while(!ready_queue.empty()){
        //�ּ� ����ð� �۾� ����
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
