#include <bits/stdc++.h>
#define pii pair<int,int>

/*
	Ǯ��
	1. �ּ� ���� Ʈ���� ����� make_min_tree ����
		- �� ��ġ�� ���� �ְ� �θ��忡 �ּڰ� ������Ʈ
	2. �ּ� ���� Ʈ���� �����ϴ� min_query ����
		- left right ������ a, b�� ���ϰų�  left == right�� ��� ����
		- a�� mid �����̰ų� b�� mid+1 �϶� Ž�� ���� ���� Ž��
	3. ���� ������� �ִ� ����Ʈ�� ����
	
	�����Ʈ
		- ����Ʈ�� ũ�⸦ �ܼ��� �������� 10���̻� 1<<17 (�� 13��)���� ��Ҵµ�,
		  ������嵵 ���ԵǾ���ϱ� ������ 10�� * 2 �̻��� ������ �ʿ��Ͽ���.
		  �׷��� OutOfBound ������ �߻��Ѱ����� ���δ�. 
*/

using namespace std;

int min_tree[1<<18];
int max_tree[1<<18];
int n, m;

int make_min_tree(int l, int r, int idx, int pos, int num){
	if(l == r){
		return min_tree[idx] = num;
	}

	int mid = (l + r) / 2;
	if(pos >= l && pos <= mid){
		return min_tree[idx] = min(min_tree[idx], make_min_tree(l, mid, 2*idx+1, pos, num));
	}
	else{
		return min_tree[idx] = min(min_tree[idx], make_min_tree(mid+1, r, 2*idx+2, pos, num));
	}
}

int make_max_tree(int l, int r, int idx, int pos, int num){
	if(l == r){
		cout<<idx<<" ";
		return max_tree[idx] = num;
	}

	int mid = (l + r) / 2;
	if(pos >= l && pos <= mid){
		return max_tree[idx] = max(max_tree[idx], make_max_tree(l, mid, 2*idx+1, pos, num));
	}
	else{
		return max_tree[idx] = max(max_tree[idx], make_max_tree(mid+1, r, 2*idx+2, pos, num));
	}
}

int min_query(int l, int r, int a, int b, int idx) {
	if(l == r) {
		return min_tree[idx];
	}
	else if(a <= l && r <= b){
		return min_tree[idx];
	}
	else{
		int mid = (l + r) / 2;
		int ret = 1000000001;
		if(mid >= a){
			ret = min(ret, min_query(l, mid, a, b, 2*idx+1));
		}
		if(mid+1 <= b){
			ret = min(ret, min_query(mid+1, r, a, b, 2*idx+2));
		}
		
		return ret;
	}
}

int max_query(int l, int r, int a, int b, int idx) {
	if(l == r) {
		return max_tree[idx];
	}
	else if(a <= l && r <= b){
		return max_tree[idx];
	}
	else{
		int mid = (l + r) / 2;
		int ret = 0;
		if(mid >= a){
			ret = max(ret, max_query(l, mid, a, b, 2*idx+1));
		}
		if(mid+1 <= b){
			ret = max(ret, max_query(mid+1, r, a, b, 2*idx+2));
		}
		
		return ret;
	}
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    
	int len = 1<<17;
	
	for(int i = 0; i < len; i++){
		min_tree[i] = 1000000001;
	}
	
	for(int i = 1; i <= n; i++){
		int x;
		
		cin>>x;
		
		make_min_tree(1, n, 0, i, x);
		make_max_tree(1, n, 0, i, x);
	}
	
	while(m--){
		int a, b;
		
		cin>>a>>b;
		
		cout<<min_query(1, n, a, b, 0)<<" "<<max_query(1, n, a, b, 0)<<"\n";
	}
    return 0;
}
