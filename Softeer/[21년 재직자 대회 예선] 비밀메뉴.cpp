#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int m, n, k;
	string key = "", cmd ="";
	cin>>m>>n>>k;

	for(int i = 0; i < m; i++){
		char s;

		cin>>s;
		key += s;
	}

	for(int i = 0; i < n; i++){
		char s;

		cin>>s;
		cmd += s;
	}

	if(cmd.find(key) != -1){
		cout<<"secret";
	}
	else{
		cout<<"normal";
	}
	return 0;
}
