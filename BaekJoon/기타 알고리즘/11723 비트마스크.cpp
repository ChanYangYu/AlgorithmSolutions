#include <bits/stdc++.h>
using namespace std;
bool check[21];
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	int n;
	
	cin.tie(0);
	
	cin>>n;
	for(int i = 0; i < n; i++){
		string cmd;
		int idx;
		
		cin>>cmd;
		
		if(cmd == "all"){
			for(int j = 1; j <= 20; j++)
				check[j] = true;

			continue;
		}
		else if(cmd == "empty"){
			for(int j = 1; j <= 20; j++)
				check[j] = false;
			continue;
		}
		
		cin>>idx;
		if(cmd == "add" && !check[idx])
			check[idx] = true;
		else if(cmd == "remove" && check[idx])
			check[idx] = false;
		else if(cmd == "check"){
			if(check[idx])
				cout<<"1\n";
			else
				cout<<"0\n";
		}
		else if(cmd == "toggle")
			check[idx] = !check[idx];
		
	}
	return 0;
}
