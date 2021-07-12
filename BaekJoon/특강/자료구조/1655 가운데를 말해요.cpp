#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
//    freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    int n;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
    
    cin>>n;
    
    for(int i = 1; i <= n; i++){
    	int num;
    	
    	cin>>num;
    	
    	max_heap.push(num);
    	
    	//최소힙이 비어있지 않을때 
    	if(!min_heap.empty()){
    		//수가 엇갈린 경우 
	    	int mx_num = max_heap.top();
	    	int mn_num = min_heap.top();
	    	
	    	//교환 
	    	if(mx_num > mn_num){
	    		max_heap.pop();
	    		min_heap.pop();
	    		
	    		max_heap.push(mn_num);
	    		min_heap.push(mx_num);
			}
    	}
		
		//짝수인 경우 
		if(i % 2 == 0){
			//두 힙의 크기가 다른경우
			if(max_heap.size() != min_heap.size()){
				int mx_num = max_heap.top();
				max_heap.pop();
				
				min_heap.push(mx_num);
			}
			
			int mx_num = max_heap.top();
			int mn_num = min_heap.top();
			
			cout<<min(mx_num, mn_num)<<"\n";
		}
		//홀수인 경우 
		else{
			cout<<max_heap.top()<<"\n";
		}
	}
    
}
