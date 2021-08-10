#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
//	freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed;
	cout.precision(4);
    
    map<string, int> h;
	int cnt = 0;
	
	
    while(true){
    	char name[31];
    	cin.getline(name, sizeof(name));
    	
    	if(cin.eof() == true)
    		break;
    	
		h[name]++;
		cnt++;
	}
	
	map<string, int>::iterator it;
	
	for(it = h.begin(); it != h.end(); it++){
		double per = (double)it->second / (double)cnt;
		cout<<it->first<<" "<<per*100.0<<"\n";
	}
	
}
