#include <bits/stdc++.h>
using namespace std;
int ch[10];
int num[10];
char op[10];
vector<string> a;
int k;

void dfs(int n){
	if(n == k+1){
		string s ="";
		char c;
		for(int i = 0; i < k+1; i++){
			c = '0' + num[i];
			s = s + c;
		}
		a.push_back(s);
		return;
	}
	else{
		for(int i = 0; i < 10; i++){
			//이전값이 있을때 
			if(ch[i] == 0){
				//뽑히지 않은 수 일때 
				if(n > 0){
					if(op[n-1] == '>' && num[n-1] > i){
						num[n] = i;
						ch[i] = 1;
						dfs(n+1);
						ch[i] = 0;
					}
					if(op[n-1] == '<' && num[n-1] < i){
						num[n] = i;
						ch[i] = 1;
						dfs(n+1);
						ch[i] = 0;
					}
				}
				else{
					num[n] = i;
					ch[i] = 1;
					dfs(n+1);
					ch[i] = 0;
				}
			}
		}
	}
}

int main(void){
	cin>>k;
	int zero = 1;
	for(int i = 0; i < k; i++){
		cin>>op[i];
		zero *= 10;
	}
	
	dfs(0);
	
	sort(a.begin(), a.end());
	
	cout<<a[0]<<endl<<a[a.size()-1];
	
    return 0;
}
