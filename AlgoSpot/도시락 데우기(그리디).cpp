#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
	return a.first > b.first;
}
int main() {
	cin.tie(0);
	//freopen("input.txt", "rt", stdin);

	int t;
	
	cin>>t;
	
	for(int k = 0; k < t; k++){
		int total;
		int eat;
		int n;
		
		cin>>n;
		vector<pair<int, int> > info(n);
		
		for(int i = 0; i < n; i++)
			cin>>info[i].second;
		for(int i = 0; i < n; i++)
			cin>>info[i].first;
		
		sort(info.begin(), info.end(), comp);
		
		//total 초깃값 : 데우는 시간 
		total = info[0].second;
		//eat 초깃값 : 먹는데 걸리는 시간 
		eat = info[0].first;
		
		//먹는시간이 가장 오래걸리는 순서부터 배급 
		for(int i = 1; i < n; i++){
			total += info[i].second;
			eat -= info[i].second;
			
			eat = max(eat, info[i].first);
		}
		
		cout<<total + eat<<"\n";

	}
	return 0;
}
