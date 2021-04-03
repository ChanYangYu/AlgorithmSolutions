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
		
		//total �ʱ갪 : ����� �ð� 
		total = info[0].second;
		//eat �ʱ갪 : �Դµ� �ɸ��� �ð� 
		eat = info[0].first;
		
		//�Դ½ð��� ���� �����ɸ��� �������� ��� 
		for(int i = 1; i < n; i++){
			total += info[i].second;
			eat -= info[i].second;
			
			eat = max(eat, info[i].first);
		}
		
		cout<<total + eat<<"\n";

	}
	return 0;
}
