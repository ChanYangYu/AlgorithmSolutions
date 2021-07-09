#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    //(무게, 가치) 
    priority_queue<pii, vector<pii>, greater<pii> > min_mass;
    //(가치, 무게) 
	priority_queue<pii> max_values;
    priority_queue<int, vector<int>, greater<int> > bags;
    int n, k;
    
    cin>>n>>k;
 	
	//보석 작은순으로 정렬   
    for(int i = 0; i < n; i++){
    	int m, v;
    	
    	cin>>m>>v;
    	
    	min_mass.push({m,v});
	}
	
	//가방 작은순으로 정렬 
	for(int i = 0; i < k; i++){
		int c;
		
		cin>>c;
		bags.push(c);
	}
    
    ll res = 0;
    while(!bags.empty()){
    	int bags_m = bags.top();
    	
    	bags.pop();
    	
    	//가방에 들어갈 수 있는 보석인 경우 
    	while(!min_mass.empty()){
    		if(bags_m < min_mass.top().first)
    			break;
    		int m = min_mass.top().first;
    		int v = min_mass.top().second;
    		
    		min_mass.pop();
    		
    		//보석을 최대가치 순으로 정렬되는 큐에 삽입 
    		max_values.push({v, m});
		}
		
		//담을 수 있는 최대가치 보석중 가방에 최대한 담는다 
		if(!max_values.empty()){
			int v = max_values.top().first;
			res += v;
			
			max_values.pop();
		}
	}
	
	cout<<res;
}
