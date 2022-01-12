#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;


/*
	오답노트
	- Greedy로 모든 간격을 우선순위큐에 넣고 하나씩 빼면서 그 절반으로 쪼개는 방법을
	  생각했으나 반례가 있어서 잘못된 알고리즘 이었다.
	- 이진탐색으로 구하는것을 알았으나, cnt를 세는것에서 한개씩만 더하는게 아니라 mid값으로
	  나눠줘야했는데 그냥++해서 답이 나오지 않았었다. 
*/

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, l;
    vector<int> pos;
    priority_queue<pair<int, pii> > pq;
    
    cin>>n>>m>>l;
    
    for(int i = 0; i < n; i++){
    	int x;
    	
    	cin>>x;
    	pos.push_back(x);
	}
	
	pos.push_back(l);
	sort(pos.begin(), pos.end());
	
	int left = 1;
	int right = l;
	while(left < right){
		int mid = (left + right) / 2;
		int prev = 0;
		int cnt = 0;
		
		for(int i = 0; i < pos.size(); i++){
			int diff = pos[i] - prev;
			
			if(diff / mid > 0)
				cnt += (diff % mid == 0) ? (diff/mid)-1 : diff/mid;
			prev = pos[i];
		}
		if(cnt > m)
			left = mid+1;
		else
			right = mid;
	}
	
	cout<<left;
    return 0;
}
