#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    cin.tie(0);
    //freopen("input.txt","rt",stdin);
    
    //multiset
    multiset<int> ms;
    multiset<int>::iterator it;
	int n;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		int x;
		
		cin>>x;
		if(x == 0){
			if(ms.empty())
				cout<<"0\n";
			else{
				//���� �� iterator it�� ���� 
				it = ms.begin();
				cout<<*it<<"\n";
				ms.erase(it);
			}
		}
		else
			//multiset�� ���� 
			ms.insert(x);
	}
	 
    return 0;
}
