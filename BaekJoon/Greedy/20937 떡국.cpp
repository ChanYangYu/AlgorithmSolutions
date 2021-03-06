#include <bits/stdc++.h>
using namespace std;
int sizes[50001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt", stdin);
	cin.tie(0);
	vector<int> bowl;
	int n;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		sizes[x]++;
	}
	
	for(int i = 50000; i >= 1; i--)
		if(sizes[i] != 0)
			bowl.push_back(sizes[i]);
	
	int cnt = 0;
	for(int i = 0; i < bowl.size(); i++){
		int num_bowl = bowl[i];
		
		num_bowl -= cnt;
		if(num_bowl > 0)
			cnt += num_bowl;
	}
	
	cout<<cnt;
	return 0;
}
