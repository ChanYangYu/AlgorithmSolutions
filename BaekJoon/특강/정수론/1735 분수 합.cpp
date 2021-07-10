#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int gcd(int a, int b){
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main(){
    //ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a,b,c,d;
    
    cin>>a>>b>>c>>d;
    
    int up = a*d + b*c;
	int down = b*d;
	
	int g = gcd(up, down);
	
	cout<<(up/g)<<" "<<(down/g);
	
}
