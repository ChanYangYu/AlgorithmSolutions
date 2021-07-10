#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int eratos[1001];
bool ch[1001];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt",stdin);
	cin.tie(0);
    cout.tie(0);
    
    int n, k;
    
    cin>>n>>k;
    
    int cnt = 0;
    for(int i = 2; i <= n; i++){
    	if(ch[i] == 0){
    		cnt++;
    		if(cnt == k){
    			cout<<i;
    			return 0;
			}
			ch[i] = 1;
			for(int j = i*i; j <= n; j+=i){
				if(ch[j] == 0){
					cnt++;
					if(cnt == k){
						cout<<j;
						return 0;
					}
					ch[j] = 1;
				}
			}
		}
	}
	return 0;
}
