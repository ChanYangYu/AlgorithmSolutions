# 재하의 금고(KMP)
## 문제 회고

- 문제에서 시계방향으로 증가할 경우
현재상태 : abbab abbab abbab
abbab 에서 babba으로 변하므로 ← 방향으로 문자열을 탐색해 나가야한다.

    따라서, target을 reverse로 바꾸고 start도 reverse로 바꿔서 계산해야한다.

    `! 시계방향으로 이동시 순환 배열에서는 마지막 요소가 앞으로 오기 때문에 음의 방향 이동이다`

- 따로 turn 변수를 두어 일치하지 않을때만 turn++해주는 방식으로 금고를 돌렸다고 생각하였지만 이는 잘못된 값으로, 구한 값은 일치하지 않는 경우 점프한 횟수를 구하였다. 문제에서 요구하는것은 금고를 돌린 횟수 이므로 전체 시작점에서 이동한 위치인 begin 값이 답이었다.

## 문제

[https://algospot.com/judge/problem/read/JAEHASAFE](https://algospot.com/judge/problem/read/JAEHASAFE)

## 소스코드

```cpp
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> get_pi(string t){
	int n = t.size();
	vector<int> pi(n,0);
	
	int begin = 1;
	int mached = 0;
	
	while(begin < n){
		if(t[begin + mached] == t[mached]){
			mached++;
			pi[begin + mached - 1] = mached;
		}
		else if(mached == 0)
			begin++;
		else{
			begin += mached - pi[mached-1];
			mached = pi[mached-1];
		}
	}
	return pi;
}

int kmp(string s, string t, vector<int> pi){
	int n = t.size();
	
	int begin = 0;
	int mached = 0;
	
	while(mached < n){
		int s_idx = (begin + mached) % n;
		if(s[s_idx] == t[mached])
			mached++;
		else if(mached == 0){
			begin++;
		}
		else{
			begin += mached - pi[mached-1];
			mached = pi[mached-1];
		}
	}
	
	//시작점에서 얼마나 이동했는가 = begin = 금고를 돌린 횟수 
	return begin;	
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int t;
	
	cin>>t;
	
	for(int test = 0; test < t; test++){
		int n;
		int d = 1;
		int res = 0;
		string start;
		
		cin>>n;
		cin>>start;
		for(int i = 0; i < n; i++){
			string target;
			string nxt;
			vector<int> pi;
			
			cin>>target;
			
			nxt = target;
			
			//시계방향의 경우 반대로 돌려서 탐색 
			if(d == 1){
				reverse(start.begin(), start.end());
				reverse(target.begin(), target.end());
			}
			
			pi = get_pi(target);
			
			res += kmp(start, target, pi);
			d = -d;
			start = nxt;
		}
		
		cout<<res<<"\n";
	}
	return 0;
}
```