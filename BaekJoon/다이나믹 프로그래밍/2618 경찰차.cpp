#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

/*
	Ǯ�̰���
	1. position�� �״�� cache�� �������� �ʰ� �� �ε����� ��ġ���Ѵ�.
		=> [1001][1001][1001][1001] => [1001][1001]
	2. �ٷ� trace�� �ϸ� ������ ������ �ƴϱ� ������ ��� ���� ���ϰ�,
	   cache�� ����Ǿ� �ִ� ���� �̿��Ͽ� tracing �Ѵ�.
*/

int cache[1001][1001];
int pos[1001][2];
int trace[1001];
int n;
int w;

int solve(int a, int b){
	if(a == w || b == w)
		return 0;
	
	int& ret = cache[a][b];
	
	if(ret != -1)
		return ret;
	
	int trace_a, trace_b;
	int diff;
	int next = max(a, b) + 1;
	
	if(a == 0)
		diff = abs(1 - pos[next][0]) + abs(1 - pos[next][1]);
	else
		diff = abs(pos[a][0] - pos[next][0]) + abs(pos[a][1] - pos[next][1]);
	trace_a = solve(next, b) + diff;
	
	if(b == 0)
		diff = abs(n - pos[next][0]) + abs(n - pos[next][1]);
	else
		diff = abs(pos[b][0] - pos[next][0]) + abs(pos[b][1] - pos[next][1]);	
	trace_b = solve(a, next) + diff;
	
	
	ret = min(trace_a, trace_b);
	
	return ret;
}

void trace_select(int a, int b){
	if(a == w || b == w)
		return;

	int diff_a, diff_b;
	int next = max(a, b) + 1;
	
	if(a == 0)
		diff_a = abs(1 - pos[next][0]) + abs(1 - pos[next][1]);
	else
		diff_a = abs(pos[a][0] - pos[next][0]) + abs(pos[a][1] - pos[next][1]);
	
	if(b == 0)
		diff_b = abs(n - pos[next][0]) + abs(n - pos[next][1]);
	else
		diff_b = abs(pos[b][0] - pos[next][0]) + abs(pos[b][1] - pos[next][1]);	
		
	if(cache[next][b] + diff_a < cache[a][next] + diff_b){
		cout<<"1\n";
		trace_select(next, b);
	}
	else{
		cout<<"2\n";
		trace_select(a, next);
	}
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>w;
    
    for(int i = 1; i <= w; i++)
    	cin>>pos[i][0]>>pos[i][1];
    
    memset(cache, -1, sizeof(cache));
    
    cout<<solve(0,0)<<"\n";
    trace_select(0,0);
    return 0;
}
