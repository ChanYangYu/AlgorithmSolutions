#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	string s;
	bool is_pell = true;
	bool all_same = true;
	
	cin>>s;
	
	int start = 0;
	int end = s.size() -1;
	char first = s[0];
	
	while(start <= end){
		if(s[start] != s[end]){
			is_pell = false;
			break;
		}
		else if(s[start] != first){
			all_same = false;
		}
		start++;
		end--;
	}
	
	if(!is_pell){
		cout<<s.size(); 
	}
	else if(all_same){
		cout<<"-1";
	}
	else{
		cout<<s.size() - 1;
	}
    return 0;
}
