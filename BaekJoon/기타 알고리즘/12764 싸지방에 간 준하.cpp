#include <bits/stdc++.h>
using namespace std;

int use[100001]; 
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int n;
	vector<pair<int, int> > v;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		int s, e;
		
		cin>>s>>e;
		v.push_back({s,e});
	}
	
	sort(v.begin(), v.end());
	
	//computer -> 종료시각, 사용컴퓨터 번호
	priority_queue<pair<int, int> > computer;
	//현재 빈 컴퓨터 번호
	priority_queue<int> wait;
	
	//컴퓨터 최대 개수 
	int mx = 1;
	
	//O(2N)
	for(int i = 0; i < n; i++){
		int start = v[i].first;
		int end = v[i].second;
		
		//이미 종료된 컴퓨터가 있거나 끝나는 시간의 컴퓨터가 있으면 
		while(!computer.empty() && -(computer.top().first) <=  start){
			//최소 우선순위 큐 이므로 -처리 
			wait.push(-(computer.top().second));
			computer.pop();
		}
		
		if(!wait.empty()){
			//가장 빠른번호의 컴퓨터 번호 선택 
			int comp_num = -(wait.top());
			wait.pop();
			
			//컴퓨터 사용횟수 추가 
			use[comp_num]++;
			computer.push({-end, comp_num});
		}
		else{
			//현재 사용중인 컴퓨터개수 + 1번호 컴퓨터 사용 
			int comp_num = computer.size() + 1;
			
			//컴퓨터 사용횟수  
			use[comp_num]++;
			computer.push({-end, comp_num});
		}
		
		//최대 컴퓨터 사용상황인지 확인 
		if(mx < computer.size())
			mx = computer.size();
	}
	
	//최댓값 출력 
	cout<<mx<<endl;
	
	//사용량 출력 
	for(int i = 1; i <= mx; i++)
		cout<<use[i]<<" ";
	return 0;
}
