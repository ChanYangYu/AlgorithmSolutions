#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
ll facto[21];
int ch[21];
vector<int> res;
vector<int> per;
int n;

void first_solve(int pos, ll k){
	if(pos == n+1){
		for(int i = 0; i < res.size();i++)
			cout<<res[i]<<" ";
		return; 
	}
	for(int i = 1; i <= n; i++){
		if(ch[i] == 0){
			if(k > facto[n-pos])
				k -= facto[n-pos];
			else{
				ch[i] = 1;
				res.push_back(i);
				first_solve(pos+1, k);
			}
		}
	}
}

void second_solve(int pos, ll k){
	if(pos == n+1){
		cout<<k+1;
		return;
	}
	
	for(int i = 1; i <= n; i++){
		if(ch[i] == 0){
			if(per[pos-1] == i){
				ch[i] = 1;
				second_solve(pos+1, k);
			}
			else{
				k += facto[n-pos];
			}
		}
	}	
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt",stdin);
	cin.tie(0);
    cout.tie(0);
	
	cin>>n;
	
	facto[0] = 1;
	for(ll i = 1; i <= n; i++)
		facto[i] = facto[i-1]*i;
	
	int num;
	
	cin>>num;
	
	if(num == 1){
		ll k;
		
		cin>>k;
		first_solve(1, k);
	}
	else{
		for(int i = 0; i < n; i++){
			int x;
			
			cin>>x;
			
			per.push_back(x);
		}
		
		second_solve(1,0);
	}
	return 0;
}
