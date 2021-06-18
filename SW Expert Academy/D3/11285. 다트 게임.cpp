#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int test;
	
	cin>>test;
	for(int t = 1; t <= test; t++){
		int n;
		
		cin>>n;
		
		int score = 0;
		for(int i = 0; i < n; i++){
			int x, y;
			
			cin>>x>>y;
			
			int dis = x*x + y*y;
			
			int p = 10;
			for(; p >= 1; p--){
				int r = 20 * (11 - p);
				
				r = r*r;
				if(dis <= r)
					break;
			}
			
			if(p == 0)
				continue;
			else
				score += p;
		}
		cout<<"#"<<t<<" "<<score<<"\n";
	}
	return 0;
}
