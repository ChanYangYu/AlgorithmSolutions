#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int p[5] = {1,2,3,4,5};
	int temp[5] = {1,1,0,0,0};
	freopen("input.txt", "rt", stdin);
	
	//줄세우기 
	do{
		for(int i = 0; i < 5; i++)
			cout<<p[i]<<" ";
		cout<<"\n";
	} while(next_permutation(p, p+5));
	
	sort(p, p+5);
	
	//조합
	do{
		for(int i = 0; i < 5; i++)
			if(temp[i] == 1)
				cout<<p[i]<<" ";
		cout<<"\n";
	} while(prev_permutation(temp,temp+5));
	return 0;
}
