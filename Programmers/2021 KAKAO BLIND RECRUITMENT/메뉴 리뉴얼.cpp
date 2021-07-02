#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> h;
int max_course[11];

//course개로 만들 수 있는 조합생성
void make_comb(int n, int start, string s, string res){
    if(n == res.size()){
        h[res]++;
        return;
    }
    
    if(n - res.size() > s.size() - start)
        return;
    for(int i = start; i < s.size(); i++)
        make_comb(n, i+1, s, res + s.substr(i, 1));
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    //들어온 orders 문자열 정렬
    for(int i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());
    
    //orders로 만들 수 있는 course개 조합을 생성하여 h에 저장
    for(int i = 0; i < orders.size(); i++){
        for(int j = 0; j < course.size(); j++)
            if(course[j] <= orders[i].size())
                make_comb(course[j], 0, orders[i], "");
    }
    
    unordered_map<string, int>::iterator it;
    priority_queue<pair<int, string> > pq;
    
    //h에 개수가 2개 이상인 세트 우선순위큐에 저장
    for(it = h.begin(); it != h.end(); it++){
        if(it->second >= 2)
            pq.push({it->second, it->first});
    }
    
    //우선순위큐에서 많이시킨 순으로 세트를 꺼낸후,
    //course개의 메뉴중 가장 많이시킨 메뉴인 경우 answer에 저장
    while(!pq.empty()){
        int cnt = pq.top().first;
        string s = pq.top().second;
        
        pq.pop();
        
        if(max_course[s.size()] <= cnt){
            max_course[s.size()] = cnt;
            answer.push_back(s);
        }
    }
    
    //사전순으로 정답정렬
    sort(answer.begin(), answer.end());
    return answer;
}
