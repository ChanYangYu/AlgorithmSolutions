#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);

	int t;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		int n;
		priority_queue<int, vector<int>, greater<int> > pq;
		cin>>n;
		for(int i = 0; i < n; i++){
			int x;
			
			cin>>x;
			pq.push(x);
		}
		int res = 0;
		while(pq.size() > 1){
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			
			int c = a + b;
			res += c;
			
			pq.push(c);
			
		}
		
		cout<<res<<"\n";

	}
	return 0;
}
