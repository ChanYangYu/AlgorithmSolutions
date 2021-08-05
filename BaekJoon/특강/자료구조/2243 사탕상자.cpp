#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int tr[1<<21];
int max_tr[1<<21];

int search(int node, int s, int e, int v){
	if(s == e)
		return s;
	//���� ������ ������ �������� �۰ų� ���� ��� 
	if(v <= tr[2*node])
		return search(2*node, s, (s+e)/2, v);
	//���� ������ ������ �������� ū ��� 
	else{
		//���� ������ �������� �� Ž��
		return search(2*node+1, (s+e)/2+1, e, v-tr[node*2]);
	}
}

void update(int node, int s, int e, int pos, int v){
	if(pos < s || pos > e)
		return;
	else if(s == e){
		tr[node] += v;
	}
	else{
		update(2*node, s, (s+e)/2, pos, v);
		update(2*node+1, (s+e)/2+1, e, pos, v);
		
		tr[node] = tr[2*node] + tr[2*node+1];
	}
} 

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt",stdin);
	cin.tie(0);
    cout.tie(0);
    
    int size = 1000000;
    int n;
    
    cin>>n;
    while(n--){
    	int a,b,c;
    	
    	cin>>a;
    	
    	if(a == 1){
    		cin>>b;
    		
    		int res = search(1, 1, 1000000, b);
    		cout<<res<<"\n";
    		update(1,1,size,res, -1);
		}
		else{
			cin>>b;
			cin>>c;
			
			update(1,1,size,b,c);
		}
	}
}
