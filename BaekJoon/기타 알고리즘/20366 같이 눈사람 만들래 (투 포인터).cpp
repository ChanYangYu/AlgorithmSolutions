#include <bits/stdc++.h>
#define pii pair<int,int> 

using namespace std;

vector<int> snows;
vector<pair<int, pii> > sums;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  int n;
  
  cin>>n;
  for(int i = 0; i < n; i++){
  	int s;
  	
  	cin>>s;
  	snows.push_back(s);
  }
  
  for(int i = 0; i < n-1; i++)
  	for(int j = i+1; j < n; j++)
  		sums.push_back({snows[i] + snows[j],{i, j}});

  sort(sums.begin(), sums.end());
  
  int res = 1000000001;
  for(int i = 0; i < sums.size()-1; i++){
  	for(int j = i+1; j < sums.size(); j++){
  		int x1 = sums[i].second.first;
  		int y1 = sums[i].second.second;
  		int x2 = sums[j].second.first;
  		int y2 = sums[j].second.second;
  		
  		if(x1 != x2 && x1 != y2 && y1 != x2 && y1 != y2){
  			res = min(res, sums[j].first - sums[i].first);
			break;	
		}
	  }
  }
  cout<<res;
}
