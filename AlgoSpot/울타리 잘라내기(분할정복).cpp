#include <bits/stdc++.h>
using namespace std;
int h[20001];

int solve(int left , int right){
	if(left == right)
		return h[left];
	int mid = (left + right) / 2;
	
	int res = max(solve(left, mid), solve(mid+1, right));
	
	int hi = mid + 1;
	int low = mid;
	
	int height = min(h[low], h[hi]);
	
	res = max(res , height * 2);
	while(low > left || hi < right){
		if(hi < right && (low == left || h[hi + 1] > h[low - 1])){
			hi++;
			height = min(height, h[hi]);
			res = max(res, (hi - low + 1) * height);
		}
		else{
			low--;
			height = min(height, h[low]);
			res = max(res, (hi - low + 1) * height);
		}
	}
	return res;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	int t, n;
	
	cin.tie(0);
	cin>>t;
	
	for(int k = 0; k < t; k++){
		cin>>n;
		
		for(int i = 0; i < n; i++)
			cin>>h[i];
		int res = solve(0, n-1);
		cout<<res<<"\n";
	}
	return 0;
} 
