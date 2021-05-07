#include <bits/stdc++.h>
#include <sstream>
using namespace std;
string W, S;
//���ϵ�ī���� ��ġ x �� ���ڿ��� ��ġ 
int cache[101][101];
int match(int w, int s){
	int& ret = cache[w][s];
	
	//�̹� Ž�������� 
	if(ret != -1)
		return ret;
	//���ڿ� �� 
	while(w < W.size() && s < S.size() && (W[w] == S[s] || W[w] == '?')){
		w++;
		s++;
	}
	
	//���ϵ�ī�尡 ���ΰ�� 
	if(W.size() == w){
		//�񱳹��ڿ��� ���� ��� �� 
		if(S.size() == s)
			return ret = 1;
		else
			return ret = 0;
	}
	//*������ ��� 
	if(W[w] == '*'){
		//���� �񱳹��ڿ� ��ġ���� ������ �����غ��鼭 Ž�� 
		for(int i = 0; i+s <= S.size(); i++){ 
			if(match(w+1, s+i))
				return ret = 1;
		}
	}
	//�׿ܿ� ��� ���� 
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
			//��ġ�Ǵ��� Ȯ�� 
			if(match(0,0))
				res.push_back(S);
		}
		//���ĺ� ������ ���� 
		sort(res.begin(), res.end());
		for(int i = 0; i < res.size(); i++)
			cout<<res[i]<<"\n";
	}
	
	return 0;
} 
