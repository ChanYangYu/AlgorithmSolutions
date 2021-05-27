# 7579 앱(0-1 knapsack)
## 문제회고

- 기존에는 단순하게 (현재 물건 번호) * (현재 물건의 무게총합) ⇒ (최대 값어치)로 생각하였으나 이번 문제는 (100) * (10000000)으로 크기가 10억인 배열이 되어 기존의 방법을 사용하지 못했다.
- 그렇기에 (현재 앱) * (현재 총 비용) ⇒ 현재까지 최소 비용로 계산하였으나 반례로 (현재 앱 번호) * (현재 총 비용)이 같으나 메모리가 다른 경우에는 다른 경우이므로 제대로 계산되지 못했다.
- 문제는 0 ~ 10000까지  총 비용을 늘리면서 ex) solve(0, 0) → solve(0, 1) → solve(0, 2)

    dp(현재 앱) * (남은 비용) ⇒ 최대 메모리 로 정의하여 풀 수 있다. 재귀함수 내부 로직은 다음과 같다. 

      1) 현재 앱을 종료하지 않는 경우

      2) 현재 앱 종료 비용이 남은 비용보다 작은 경우 종료한 경우

    두 경우의 최대값을 저장하는 방법으로 풀 수 있다. 

## 문제

[https://www.acmicpc.net/problem/7579](https://www.acmicpc.net/problem/7579)

## 소스코드

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
// (n번째 앱) * (남아있는 비용) => 현재 상태에서 나올 수 있는 최대 메모리
int cache[101][10001]; 
int values[101]; 
int mems[101];
int n, m;

int solve(int p, int s){
	//n번 앱까지 모두 탐색한 경우 종료 
	if(p == n)
		return 0;
	
	int& ret = cache[p][s];
	
	//이미 탐색한 경우 
	if(ret != -1)
		return ret;
	
	//현재앱 종료x 
	ret = solve(p+1, s);
	
	//현재 앱을 종료하여도 총 비용이 남거나 0인경우 
	if(s - values[p] >= 0)
		//현재앱을 종료하지 않을때와 종료할때 두 경우중 더 메모리가 큰 경우를 선택 
		ret = max(ret, solve(p+1, s - values[p]) + mems[p]);
	return ret;
} 
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	
	for(int i = 0; i < n; i++)
		cin>>mems[i];
	for(int i = 0; i < n; i++)
		cin>>values[i];
	
	memset(cache, -1, sizeof(cache));
	
	//총 비용을 0 ~ 10000 범위로 늘려가며 탐색 
	for(int i = 0; i < 10001; i++){
		//총 비용이 i일때 사용할 수 있는메모리가 m이상이면 
		if(solve(0, i) >= m){
			//현재 총비용이 최소비용이므로 출력후 탐색종료 
			cout<<i;
			break;
		}
	}
	return 0;
}
```