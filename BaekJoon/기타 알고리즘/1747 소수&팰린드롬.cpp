#include <bits/stdc++.h>

using namespace std;

bool check[2000001];


bool is_pelindrome(int num){
	string str = to_string(num);
	int s = 0;
	int e = str.size() - 1;
	
	while(s <= e){
		if(str[s] != str[e]){
			return false;
		}
		s++;
		e--;
	}
	
	return true;
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	int n;
 	
 	cin>>n;
 	
 	check[1] = true;
 	for(int i = 2; i <= 1002; i++){
 		if(check[i] == false){
			 for(int j = i * i; j <= 2000000; j += i){
 				check[j] = true;
			}
			
		}
	}
	
	for(int i = n; i <= 2000000; i++){
		if(check[i] == false && is_pelindrome(i)){
			cout<<i;
			break;
		}
	}
    return 0;
}
