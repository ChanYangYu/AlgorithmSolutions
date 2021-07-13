#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    cin.tie(0);
    //freopen("input.txt","rt",stdin);
    multiset<int> pq;
    multiset<int>::iterator iter;
	int n;
	
	cin>>n;
	for(int i = 0; i < n; i++){
		int x;
		
		cin>>x;
		
		if(x == 0){
			if(pq.empty())
				cout<<"0\n";
			else{
				iter = pq.end();
				iter--;
				cout<<*iter<<"\n";
				pq.erase(iter);
			}
		}
		else
			pq.insert(x);
	} 
	
    return 0;
}
