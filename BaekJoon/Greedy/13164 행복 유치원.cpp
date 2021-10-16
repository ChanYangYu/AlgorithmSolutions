#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    int s;
    int sum = 0;
    
    cin>>n>>k;
    cin>>s;
    priority_queue<int> pq;
    
    for(int i = 1; i < n; i++){
    	int c;
    	
    	cin>>c;
    	
    	pq.push(c-s);
    	sum += c-s;
    	s = c;
	}
	
	while(k-- > 1){
		sum -= pq.top();
		pq.pop();
	}
	
	cout<<sum;
    return 0;
}
