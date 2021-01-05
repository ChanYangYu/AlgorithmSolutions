#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int n;
	
	cin>>n;
	
	vector<int> a(n);
	//ch벡터 전체 무제한으로 초기화 
	vector<int> ch(n,987654321);
	//값 입력 
	for(int i = 0; i < n; i++)
		cin>>a[i];
	queue<int> q;
	ch[0] = 0;
	q.push(0);
	//BFS
	while(!q.empty()){
		int x = q.front();
		int jump = a[x];
		q.pop();
		
		for(int i = 1; i <= jump; i++){
			if(x+i < n){
				if(ch[x+i] > ch[x] + 1){
					ch[x+i] = ch[x] + 1;
					q.push(x+i);
				}
			}
		}	
	}
	//정답 출력 
	if(ch[n-1] == 987654321)
		cout<<"-1";
	else
		cout<<ch[n-1];
	
	return 0;
}

/* 100% 틀렸습니다. 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	int n;
	
	cin>>n;
	
	vector<int> a(n);
	vector<int> ch(n,0);
	for(int i = 0; i < n; i++)
		cin>>a[i];
	queue<int> q;
	
	q.push(0);
	while(!q.empty()){
		int x = q.front();
		int jump = a[x];
		q.pop();
		
		for(int i = 1; i <= jump; i++){
			if(x+i < n){
				if(ch[x+i] == 0 || ch[x+i] > ch[x] + 1){
					ch[x+i] = ch[x] + 1;
					q.push(x+i);
				}
			}
		}	
	}
	if(ch[n-1] == 0)
		cout<<"-1";
	else
		cout<<ch[n-1];
	
	return 0;
}
*/
