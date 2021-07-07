#include <bits/stdc++.h>
#define MAX 1000000000
#define ll long long 
using namespace std;
string w[51];
int ch[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "rt", stdin);
	
	int n, k;
	vector<char> req_char; 
	cin>>n>>k;
	
	if(k < 5){
		cout<<"0";
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		cin>>w[i];
		for(int j = 0; j < w[i].size(); j++){
			//접미사 접두사는 제외 
			if(w[i][j] == 'a' || w[i][j] == 'n' || w[i][j] == 't' || w[i][j] == 'i' || w[i][j] == 'c')
				continue;
			//접두사 접미사 이외에 문자인 경우 
			if(ch[w[i][j] - '0'] == 0){
				req_char.push_back(w[i][j]);
				ch[w[i][j] - '0'] = 1;
			}
		}
	}
	
	k -= 5;
	
	if(k >= req_char.size()){
		cout<<n;
		return 0;
	}
	
	vector<int> c(req_char.size(), 1);
	for(int i = 0; i < k; i++)
		c[i] = 0;
	cout<<req_char.size()<<" "<<k<<"\n";
	int cnt = 0;
	do{
		for(int i = 0; i < req_char.size(); i++){
			if(c[i] == 0)
				cout<<req_char[i]<<" ";
		}
		cout<<"\n";
		cnt++;
	}while(next_permutation(c.begin(), c.end()));
	cout<<cnt<<"\n";
	return 0;
}
