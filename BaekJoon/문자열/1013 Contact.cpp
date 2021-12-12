#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  regex re("^((100+1+)|01)+$");
  
  cin>>n;
  
  for(int i = 0; i < n; i++){
  	string s;
  	
  	cin>>s;
  	if(regex_match(s, re)) cout<<"YES\n";
  	else cout<<"NO\n";
  }
  
}