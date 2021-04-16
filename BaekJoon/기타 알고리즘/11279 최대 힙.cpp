#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    cin.tie(0);
    //freopen("input.txt","rt",stdin);
    priority_queue<int> pq;
	int n;
	
	cin>>n;
	for(int i = 0; i < n; i++){
		int x;
		
		cin>>x;
		
		if(x == 0){
			if(pq.empty())
				cout<<"0\n";
			else{
				cout<<pq.top()<<"\n";
				pq.pop();
			}
		}
		else
			pq.push(x);
	} 
	
    return 0;
}
