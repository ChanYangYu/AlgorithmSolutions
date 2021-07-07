#include <bits/stdc++.h>
#define ll long long
using namespace std;

int cache[1000001][10];
int ten_sq[6] = {1, 10, 100, 1000, 10000, 100000};
int n, k;
int solve(int num, int idx){
	if(idx == k)
		return num;
	int& ret = cache[num][idx];
	
	if(ret != -1)
		return ret;
		
	vector<int> nums;
	int tmp = num;
	
	while(tmp > 0){
		nums.push_back(tmp % 10);
		tmp /= 10;
	}
	
	ret = 0;
	int size = nums.size();
	for(int i = 0; i < size; i++){
		for(int j = i+1; j < size; j++){
			
			//첫벗째 자리이고 바뀔 자리숫자가 0이면 
			if(j == size-1 && nums[i] == 0)
				continue;
			int prev = (nums[i] * ten_sq[i]) + (nums[j] * ten_sq[j]);
			int next = (nums[i] * ten_sq[j]) + (nums[j] * ten_sq[i]);
			
			ret = max(ret, solve(num-prev+next, idx+1));
		}
	}
	return ret;
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "rt", stdin); 
	
	cin>>n>>k;
	
	memset(cache, -1, sizeof(cache));
	
	if(n < 10)
		cout<<"-1";
	else{
		int res = solve(n, 0);
		if(res == 0)
			cout<<"-1";
		else
			cout<<res;
	}
	
	return 0;
}
