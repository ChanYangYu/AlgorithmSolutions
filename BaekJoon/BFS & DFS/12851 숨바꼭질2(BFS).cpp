#include <bits/stdc++.h>
using namespace std;
int check[100001];
int n, k;

int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	queue<pair<int, int> > q;
	
	cin>>n>>k;
	
	q.push({n,0});
	
	int res = 987654321;
	int count = 0;
	while(!q.empty()){
		int pos = q.front().first;
		int cnt = q.front().second;
		
		q.pop();
		
		//�湮�� üũ(����depth�� ���� K�� �����ߴ��� üũ �ؾ��ϱ� ����) 
		check[pos] = 1;
		//�ּڰ��� �ƴѰ�� 
		if(res < cnt)
			continue;
		//���� üũ 
		if(pos == k){
			if(res > cnt){
				count = 1;
				res = cnt; 
			}
			else if(res == cnt)
				count++;
			continue;
		}
		
		//�湮���� �ʾҰų� �����ΰ�� Ž�� 
		if(2*pos <= 100000 && check[2*pos] == 0)
			q.push({2*pos, cnt+1});
		
		if(pos-1 >= 0 && check[pos-1] == 0)
			q.push({pos-1, cnt+1});
		
		
		if(pos+1 <= 100000 && check[pos+1] == 0)
			q.push({pos+1, cnt+1});
		
	}
	
	cout<<res<<"\n"<<count;

    return 0;
}
