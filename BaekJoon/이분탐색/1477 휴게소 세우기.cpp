#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;


/*
	�����Ʈ
	- Greedy�� ��� ������ �켱����ť�� �ְ� �ϳ��� ���鼭 �� �������� �ɰ��� �����
	  ���������� �ݷʰ� �־ �߸��� �˰��� �̾���.
	- ����Ž������ ���ϴ°��� �˾�����, cnt�� ���°Ϳ��� �Ѱ����� ���ϴ°� �ƴ϶� mid������
	  ��������ߴµ� �׳�++�ؼ� ���� ������ �ʾҾ���. 
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
