#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int t;
	int n, res;
	vector<pair<int, int> >arr;
	
	cin>>t;
	
	for(int i = 0; i < t; i++){
		cin>>n;
		for(int j = 0; j < n; j++){
			int s,m;
			cin>>s>>m;
			arr.push_back(make_pair(s,m));
		}
		
		sort(arr.begin(), arr.end());
		
		int mm = arr[0].second;
		res = 1;
		for(int j = 1; j < n; j++){
			if(mm > arr[j].second){
				mm = arr[j].second;
				res++;
			}
		}
		arr.clear();
		cout<<res<<endl;
	}
	return 0;
}
