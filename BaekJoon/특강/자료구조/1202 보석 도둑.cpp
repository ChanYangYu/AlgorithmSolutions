#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    //(����, ��ġ) 
    priority_queue<pii, vector<pii>, greater<pii> > min_mass;
    //(��ġ, ����) 
	priority_queue<pii> max_values;
    priority_queue<int, vector<int>, greater<int> > bags;
    int n, k;
    
    cin>>n>>k;
 	
	//���� ���������� ����   
    for(int i = 0; i < n; i++){
    	int m, v;
    	
    	cin>>m>>v;
    	
    	min_mass.push({m,v});
	}
	
	//���� ���������� ���� 
	for(int i = 0; i < k; i++){
		int c;
		
		cin>>c;
		bags.push(c);
	}
    
    ll res = 0;
    while(!bags.empty()){
    	int bags_m = bags.top();
    	
    	bags.pop();
    	
    	//���濡 �� �� �ִ� ������ ��� 
    	while(!min_mass.empty()){
    		if(bags_m < min_mass.top().first)
    			break;
    		int m = min_mass.top().first;
    		int v = min_mass.top().second;
    		
    		min_mass.pop();
    		
    		//������ �ִ밡ġ ������ ���ĵǴ� ť�� ���� 
    		max_values.push({v, m});
		}
		
		//���� �� �ִ� �ִ밡ġ ������ ���濡 �ִ��� ��´� 
		if(!max_values.empty()){
			int v = max_values.top().first;
			res += v;
			
			max_values.pop();
		}
	}
	
	cout<<res;
}
