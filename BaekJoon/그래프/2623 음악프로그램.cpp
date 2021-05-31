#include <bits/stdc++.h>
#define ll long long
using namespace std;

int preq[1001][1001];
int cnt[1001];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	
	cin>>n>>m;
	
	for(int i = 0; i < m; i++){
		int k;
		vector<int> a;
		
		cin>>k;
		for(int j = 0; j < k; j++){
			int cur;
			
			cin>>cur;
			
			//a = �����;��� ������ 
			for(int l = 0; l < a.size(); l++){
				if(preq[cur][a[l]] == 0){
					preq[cur][a[l]] = 1;
					cnt[cur]++;
				}
			}
			a.push_back(cur);
		}
	}
	
	vector<int> res;
	for(int i = 0; i < n; i++){
		int next = -1;
		
		//���� �;��ϴ� ������ 0���� ���� search 
		for(int j = 1; j <= n; j++){
			if(cnt[j] == 0){
				//���� ���� ���� ��, -1�� �ߺ������� ���´�. 
				next = j;
				cnt[j] = -1;
				break;
			}
		}
		
		//���� ������ �� ������ ���� ��� 
		if(next == -1){
			// 0��� �� ���� 
			cout<<"0";
			return 0;
		}
		//���� �迭�� ���� ��ȣ ���� 
		res.push_back(next);
		
		//���� ���õ� �������� ���� ������ �;��� ������ cnt(���� �;��ϴ� ������ ��)-- 
		for(int j = 1; j <= n; j++){
			if(preq[j][next] == 1){
				preq[j][next] = 0;
				cnt[j]--;
			}
		}
	}
	
	for(int j = 0; j < n; j++)
		cout<<res[j]<<"\n";
	return 0;
}
