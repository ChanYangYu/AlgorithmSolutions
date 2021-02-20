#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	priority_queue<int, vector<int>, greater<int> > minheap;
	priority_queue<int> maxheap;
	int n, x;
	
    cin.tie(0);
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>x;
		if(maxheap.size() == minheap.size())
			maxheap.push(x);
		else
			minheap.push(x);
		
		if(maxheap.size() != 0 && minheap.size() != 0 && maxheap.top() > minheap.top()){
			int tmp = minheap.top();
			minheap.pop();
			maxheap.push(tmp);
			
			tmp = maxheap.top();
			maxheap.pop();
			minheap.push(tmp);
		}
		cout<<maxheap.top()<<"\n";
	}
	 
	return 0;
}
