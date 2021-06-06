#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int n;
	vector<int> res;
	
	cin>>n;
	vector<int> arr(n);
	vector<int> s[n];
	
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	
	for(int i = 0; i < n; i++){
		int size = res.size();
		if(size == 0 || res[size-1] < arr[i]){
			res.push_back(arr[i]);
			s[size].push_back(i);
		}
		else{
			int idx = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
			s[idx].push_back(i);
			res[idx] = arr[i];
		}
	}
	
	int res_size = res.size();
	int s_size = s[res_size-1].size();
	int idx = s[res_size-1][s_size-1];
	
	for(int i = res_size-2; i >= 0; i--){
		for(int j = s[i].size() - 1; j >= 0; j--){
			if(s[i][j] < idx){
				idx = s[i][j];
				res[i] = arr[idx];
				break;
			}
		}
	}
	
	cout<<res.size()<<"\n";
	for(int i = 0; i < res.size(); i++)
		cout<<res[i]<<" ";
	return 0;
}
