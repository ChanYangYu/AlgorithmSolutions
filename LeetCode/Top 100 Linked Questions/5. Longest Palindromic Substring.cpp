#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
    //정렬된 배열
	vector<int> a = {17, 28, 43, 67, 88, 92, 100};
	
	int left = 0;
	int right = a.size()-1;
	int target = 17;
	int pos = -1;
	
	while(left <= right){
		int mid = (left + right) / 2;
		
		if(a[mid] > target)
			right = mid - 1;
		else if(a[mid] < target)
			left = mid + 1;
		else{
			pos = mid;
			break;
		}
	}
	
	if(pos != -1)
		cout<<pos;
	else
		cout<<"Not Found!\n";		
	return 0;
}
