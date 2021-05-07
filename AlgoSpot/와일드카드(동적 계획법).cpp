#include <bits/stdc++.h>
#include <sstream>
using namespace std;
string W, S;
//와일드카드의 위치 x 비교 문자열의 위치 
int cache[101][101];
int match(int w, int s){
	int& ret = cache[w][s];
	
	//이미 탐색했으면 
	if(ret != -1)
		return ret;
	//문자열 비교 
	while(w < W.size() && s < S.size() && (W[w] == S[s] || W[w] == '?')){
		w++;
		s++;
	}
	
	//와일드카드가 끝인경우 
	if(W.size() == w){
		//비교문자열도 끝인 경우 참 
		if(S.size() == s)
			return ret = 1;
		else
			return ret = 0;
	}
	//*문자인 경우 
	if(W[w] == '*'){
		//현재 비교문자열 위치부터 끝까지 생략해보면서 탐색 
		for(int i = 0; i+s <= S.size(); i++){ 
			if(match(w+1, s+i))
				return ret = 1;
		}
	}
	//그외에 경우 거짓 
	return ret = 0;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	cin.tie(0);
	int t, n;
	
	cin>>t;
	for(int k = 0; k < t; k++){
		cin>>W;
		cin>>n;
		vector<string> res;
		for(int i = 0; i < n; i++){
			cin>>S;
			memset(cache, -1, sizeof(cache));
			//매치되는지 확인 
			if(match(0,0))
				res.push_back(S);
		}
		//알파벳 순으로 정렬 
		sort(res.begin(), res.end());
		for(int i = 0; i < res.size(); i++)
			cout<<res[i]<<"\n";
	}
	
	return 0;
} 
