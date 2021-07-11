#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int n, num;
pii player[500001];
int tr[1<<20]; //들어갈 원소수 곱하기x2 = > 2^20 =>100만 

int seg_sum(int node, int s, int e, int l, int r) {
	if(r < s || e < l)
		return 0;
	if(l <= s && e <= r)
		return tr[node];
	else
		return seg_sum(node*2, s, (s+e) / 2, l, r) + seg_sum(node*2+1,(s+e) / 2 +1, e, l, r);
}

void update(int node, int s, int e, int idx, int v){
	if(idx < s || e < idx)
		return;
	if(s == e){
		tr[node] = v;
	}
	else{
		update(node * 2, s, (s+e)/2, idx, v);
		update(node * 2 + 1, (s+e)/2 + 1, e, idx, v);
		tr[node] = tr[node * 2] + tr[node * 2 + 1];
	}
}
bool comp(pii a, pii b){
	return a.second < b.second;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    
    for(int i = 0; i < n; i++){
    	int power;
    	
    	cin>>power;
    	player[i].first = i;
    	player[i].second = power;
	}
	//파워 순 정렬 
	sort(player, player+n, comp);
	
	
	//re label (파워를 50만개로 추린다) 
	for(int i = 0; i < n; i++){
		player[i].second = ++num;
	}
	
	//원래 순으로 정렬 
	sort(player, player + n);
		
	for(int i = 0; i < n; i++){
		int curpower = player[i].second;
		
		int cnt = 0;
		
		if (curpower > 1) {
            cnt = seg_sum(1, 1, num, 1, curpower - 1);
        }
		update(1, 1, num, curpower, 1);
		cout<<i+1 - cnt<<"\n";
	}
}
