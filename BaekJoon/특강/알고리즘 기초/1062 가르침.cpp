#include <bits/stdc++.h>
#define ll long long
using namespace std;
//단어 배열 
string w[51];

//가르친 문자 배열 
int ch[26];

//중복체크 배열 
int dup_ch[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "rt", stdin);
	
	int n, k;
	//모든 단어에서 필수 문자 이외 필요한 문자 저장
	vector<char> req_char; 
	cin>>n>>k;
	
 
	for(int i = 0; i < n; i++){
		cin>>w[i];
		for(int j = 0; j < w[i].size(); j++){
			//접미사 접두사는 제외 
			if(w[i][j] == 'a' || w[i][j] == 'n' || w[i][j] == 't' || w[i][j] == 'i' || w[i][j] == 'c')
				continue;
			//접두사 접미사 이외에 문자인 경우(중복해서 저장 안되도록 체크 필요) 
			if(dup_ch[w[i][j] - 'a'] == 0){
				req_char.push_back(w[i][j]);
				dup_ch[w[i][j] - 'a'] = 1;
			}
		}
	}
	
	//필수 문자 이하를 가르칠 수 있는 경우 
	if(k < 5){
		cout<<"0";
		return 0;
	}
	
	k -= 5;
	//필수 문자 체크 
	ch['a' - 'a'] = 1;
	ch['n' - 'a'] = 1;
	ch['t' - 'a'] = 1;
	ch['i' - 'a'] = 1;
	ch['c' - 'a'] = 1;
	
	//필요한 모든 문자를 배울 수 있는 경우 
	if(k >= req_char.size()){
		cout<<n;
		return 0;
	}
	
	vector<int> c(req_char.size(), 1);
	int res = 0;
	
	for(int i = 0; i < k; i++)
		c[i] = 0;
		
	//모든 조합 탐색
	int test = 0;
	
#ifdef DEBUG
	cout<<req_char.size()<<" C "<<k<<" = ";
#endif
	do{
		//읽을 수 있는 문자 체크 
		for(int i = 0; i < req_char.size(); i++)
			if(c[i] == 0)
				ch[req_char[i] - 'a'] = 1;
		test++;
			
		int cnt = 0;
		//n개 단어 체크 
		for(int j = 0; j < n; j++){
			int size = w[j].size();
			bool check = true;
			
			//접두사 접미사 제외 문자 체크 
			for(int k = 4; k < size-4; k++){
				int idx = w[j][k] - 'a';
				if(ch[idx] != 1){
					check = false;
					break;
				}
			}
			
			//읽을 수 있는 단어인 경우 
			if(check)
				cnt++;
			
		}
		
		//최대 개수 갱신 
		res = max(res, cnt);
		
		//문자 다시 되돌리기 
		for(int i = 0; i < req_char.size(); i++)
			if(c[i] == 0)
				ch[req_char[i] - 'a'] = 0;
		
	}while(next_permutation(c.begin(), c.end()));
#ifdef DEBUG
	cout<<test<<"\n";
#endif
	
	cout<<res; 
	return 0;
}
