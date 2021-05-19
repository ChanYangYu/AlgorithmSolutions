#include <bits/stdc++.h>
#define ll long long
using namespace std;

int v[1000001];
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int n;
	queue<pair<int, int> > q;
	
	cin>>n;
	
	q.push({0, n});
	
	//search
	while(!q.empty()){
		int cnt = q.front().first;
		int num = q.front().second;
		
		q.pop();
		
		if(num == 1)
			break;
		if(num % 3 == 0){
			int new_num = num / 3;
			
			if(v[new_num] == 0){
				v[new_num] = num;
				q.push({cnt+1, new_num});
			}
		}
		if(num % 2 == 0){
			int new_num = num / 2;
			
			if(v[new_num] == 0){
				v[new_num] = num;
				q.push({cnt+1, new_num});
			}
		}
		int new_num = num - 1;
		if(v[new_num] == 0){
			v[new_num] = num;
			q.push({cnt+1, new_num});
		}
	}
	
	stack<int> res;
	
	res.push(1);
	int idx = 1;
	//tracking
	while(v[idx] > 0){
		res.push(v[idx]);
		idx = v[idx];
	}
	
	//print
	cout<<res.size()-1<<"\n";
	while(!res.empty()){
		cout<<res.top()<<" ";
		res.pop();
	}
	return 0;
}
