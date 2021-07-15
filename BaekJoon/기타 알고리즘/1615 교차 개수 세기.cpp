#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
ll tr[1<<12];

ll query(int node, int s, int e, int l, int r){
    if(r < s || e < l)
        return 0;
    else if(l <= s && e <= r)
        return tr[node];
    else
        return query(2*node, s, (s+e)/2, l, r) + query(2*node+1, (s+e)/2+1, e, l, r);
} 

void update(int node, int s, int e, int pos){
    if(s > pos || e < pos)
        return;
    if(s == e){
        tr[node]++;
        return;
    }
    else{
        update(2*node, s, (s+e)/2, pos);
        update(2*node+1, (s+e)/2+1, e, pos);

        //부모노드에 B추가 
        tr[node]++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","rt",stdin);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin>>n>>m;

    vector<pii> edge;
    while(m--){
        int a, b;

        cin>>a>>b;

        edge.push_back({b, a});
    }

    //B를 기준으로 정렬
    sort(edge.begin(), edge.end());

    ll res = 0;
    for(int i = 0; i < edge.size(); i++){
        int a = edge[i].second;
        int b = edge[i].first;

        //targetA < A , targetB > B
        res += query(1, 1, n, a+1, n);
        //새로운 간선 추가
        update(1, 1, n, a);
    }

    cout<<res<<"\n";
    return 0;
}
