#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int n, m;
int ch[8];
int dup_ch[8][10001];
int res[8];
vector<int> nums;

void per(int cnt){
	if(cnt == m){
		for(int i = 0; i < m; i++)
			cout<<res[i]<<" ";
		cout<<"\n";
		return;
	}
	
	for(int i = 0; i < n; i++){
		if(ch[i] == 0 && dup_ch[cnt][nums[i]] == 0){
			ch[i] = 1;
			dup_ch[cnt][nums[i]] = 1;
			res[cnt] = nums[i];
			per(cnt+1);
			ch[i] = 0;
		}
	}
	for(int i = 0; i < nums.size(); i++)
		dup_ch[cnt][nums[i]] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt",stdin);
	cin.tie(0);
    cout.tie(0);
	
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		int x;
		
		cin>>x;
		
		nums.push_back(x);
	}
	
	sort(nums.begin(), nums.end());
	
	per(0);
	return 0;
}
