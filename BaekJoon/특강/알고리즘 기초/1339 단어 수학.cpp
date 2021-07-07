#include <bits/stdc++.h>

using namespace std;
int ten_sqr[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
int a[26];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	
	cin>>n;
	for(int i = 0; i < n; i++){
		string str;
		
		cin>>str;
		
		int size = str.size();
		for(int j = 0; j < size; j++)
			a[str[j] - 'A'] += ten_sqr[size -1 - j]; 
	}
	
	priority_queue<pair<int, char> > pq;
	
	for(int i = 0; i < 26; i++){
		char alpha = 'A' + i;
		
		if(a[i] != 0)
			pq.push({a[i], alpha});
	}
	
	int num = 9;
	int res = 0;
	while(!pq.empty()){
		int sqr = pq.top().first;
		char alpha = pq.top().second;
		
		pq.pop();
		
		res += num * sqr;
		num--;
	}
	
	cout<<res;
	//결과 출력 

}

