#include<bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int pre_cnt[32001];
vector<int> child[32001];

int main(int argc, char** argv)
{
	int n, m;

	cin>>n>>m;
	
	for(int i = 0; i < m; i++){
		int a, b;
		
		cin>>a>>b;
		
		child[a].push_back(b);
		pre_cnt[b]++;
	}
	
	priority_queue<int, vector<int>, greater<int> > pre;
	
	for(int i = 1; i <= n; i++){
		if(pre_cnt[i] == 0)
			pre.push(i);
	}
	
	while(!pre.empty()){
		int number = pre.top();
		
		cout<<number<<" ";
		pre.pop();
		
		for(int i = 0; i < child[number].size(); i++){
			int c = child[number][i];
			
			pre_cnt[c]--;
			
			if(pre_cnt[c] == 0){
				pre.push(c);
			}
		}
	}
	return 0;
}
