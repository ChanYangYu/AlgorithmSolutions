#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> arr;

int my_binary_search(int target, int n){
	int left = 0;
	int right = n-1;
	
	while(left <= right){
		int mid = (left + right) / 2;
		
		if(target == arr[mid])
			return 1;
		else if(target < arr[mid])
			right = mid-1;
		else
			left = mid + 1;
	}
	return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "rt", stdin); 
    int n, m;
    
    cin>>n;
    
    for(int i = 0; i < n; i++){
    	int x;
		cin>>x;
		
		arr.push_back(x);
	}
	
	sort(arr.begin(), arr.end());
	
	cin>>m;
	
	while(m--){
		int t;
		
		cin>>t;
		
		cout<<my_binary_search(t, n)<<"\n";
	}
	    
	return 0;
}
