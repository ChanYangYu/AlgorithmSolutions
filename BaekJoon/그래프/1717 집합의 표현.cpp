#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int p[1000001];
int m_find(int a){
	if(a == p[a])
		return a;
	else
		return p[a] = m_find(p[a]);
}

void m_union(int a, int b){
	if(a < b)
		p[b] = a;
	else
		p[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false);
//    freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    
	cin>>n>>m;
	
	for(int i = 0; i <= n; i++)
		p[i] = i;
	
	while(m--){
		int c, a, b;
		
		cin>>c>>a>>b;
		
		int pa = m_find(a);
		int pb = m_find(b);
		if(c == 1){
			if(pa == pb)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		else
			m_union(pa, pb);
	}
	
	return 0;
}
