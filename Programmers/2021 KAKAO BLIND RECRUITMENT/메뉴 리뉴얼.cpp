#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> h;
int max_course[11];

//course���� ���� �� �ִ� ���ջ���
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
    
    //���� orders ���ڿ� ����
    for(int i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());
    
    //orders�� ���� �� �ִ� course�� ������ �����Ͽ� h�� ����
    for(int i = 0; i < orders.size(); i++){
        for(int j = 0; j < course.size(); j++)
            if(course[j] <= orders[i].size())
                make_comb(course[j], 0, orders[i], "");
    }
    
    unordered_map<string, int>::iterator it;
    priority_queue<pair<int, string> > pq;
    
    //h�� ������ 2�� �̻��� ��Ʈ �켱����ť�� ����
    for(it = h.begin(); it != h.end(); it++){
        if(it->second >= 2)
            pq.push({it->second, it->first});
    }
    
    //�켱����ť���� ���̽�Ų ������ ��Ʈ�� ������,
    //course���� �޴��� ���� ���̽�Ų �޴��� ��� answer�� ����
    while(!pq.empty()){
        int cnt = pq.top().first;
        string s = pq.top().second;
        
        pq.pop();
        
        if(max_course[s.size()] <= cnt){
            max_course[s.size()] = cnt;
            answer.push_back(s);
        }
    }
    
    //���������� ��������
    sort(answer.begin(), answer.end());
    return answer;
}
