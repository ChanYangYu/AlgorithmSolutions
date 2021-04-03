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
		
		//초깃값 세팅 
		total = info[0].second;
		eat = info[0].first;
		
		//먹는시간이 가장 오래 걸리는 순으로 데운다. 
		for(int i = 1; i < n; i++){
			total += info[i].second;
			eat -= info[i].second;
			
			eat = max(eat, info[i].first);
		}
		
		cout<<total + eat<<"\n";

	}
	return 0;
}
