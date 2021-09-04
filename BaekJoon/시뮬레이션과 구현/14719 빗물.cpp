#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int h, w;
	
	cin>>h>>w;
	
	priority_queue<int> pq[501];
	vector<int> hs;
	
	for(int i = 0; i < w; i++){
		int x;
		
		cin>>x;
		pq[i].push(x);
		hs.push_back(x);
		for(int j = 0; j < i; j++)
			pq[j].push(x);
	}
	
	queue<int> q;
	int start = hs[0];
	int res = 0;
	for(int i = 1; i < w; i++){
		if(start <= hs[i] || hs[i] == pq[i].top()){
			int min_h = min(start, hs[i]);
			
			while(!q.empty()){
				res += min_h - q.front();
				q.pop();
			}
			start = hs[i];
		}
		else
			q.push(hs[i]);
	}
	
	cout<<res;
	return 0;
}
