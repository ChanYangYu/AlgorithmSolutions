#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int main(int argc, char** argv)
{
	int n;
	vector<pii> t;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		int a, b, c;
		
		cin>>a>>b>>c;
		
		t.push_back({b,c});
	}
	
	sort(t.begin(), t.end());
	
	int res = 0;
	priority_queue<int, vector<int>, greater<int> > pq;
	
	for(int i = 0; i < n; i++){
		int s = t[i].first;
		int e = t[i].second;
		
		while(!pq.empty()){
			if(pq.top() > s)
				break;
			pq.pop();
		}
		pq.push(e);
		
		int size = pq.size();
		res = max(res, size);
	}
	
	cout<<res;
    return 0;
}
