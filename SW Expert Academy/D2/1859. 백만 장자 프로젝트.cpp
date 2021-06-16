#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int test;
	
	cin>>test;
	for(int t = 1; t <= test; t++){
		int n;
		priority_queue<pair<ll, ll> > pq;
		vector<ll> prices;
		
		cin>>n;
		
		for(int i = 0; i < n; i++){
			ll x;
			
			cin>>x;
			pq.push({x, i});
			prices.push_back(x);
		}
		
		ll won = 0;
		ll cnt = 0;
		for(int i = 0; i < n; i++){
			while(!pq.empty() && pq.top().second < i)
				pq.pop();
			
			//유효한 최고가 보다 작은 경우 구매 
			if(pq.top().first > prices[i]){
				won -= prices[i];
				cnt++;
			}
			
			//최고가를 만난경우 판매
			if(pq.top().second == i){
				won += (pq.top().first) * cnt;
				cnt = 0;
				pq.pop();
			}
		}
		
		cout<<"#"<<t<<" "<<won<<"\n";
	}
	return 0;
}
