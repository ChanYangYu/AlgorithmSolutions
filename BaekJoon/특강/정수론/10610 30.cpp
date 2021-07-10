#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

bool comp(int a, int b){
	return a > b;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt",stdin);
	cin.tie(0);
    cout.tie(0);
    
    string s;
    
    cin>>s;
    
   	int zero = 0;;
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
    	int num = s[i] - '0';
    	
    	if(num == 0)
    		zero++;
    	sum += num;
	}
	
	if(sum % 3 == 0 && zero != 0){
		sort(s.begin(), s.end(), comp);
		cout<<s;
	}
	else
		cout<<"-1";
}
