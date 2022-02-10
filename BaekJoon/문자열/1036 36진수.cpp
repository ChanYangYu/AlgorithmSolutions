#include <bits/stdc++.h>
#define pii pair<int,int>

/*
	풀이
	1. 0 ~ 35 숫자를 바꿨을 때 커지는 숫자를 number에 저장
	2. number를 기준으로 comp를 하여 0 ~ 36 숫자중에 가장 값을 크게만드는 숫자 K개 선택
	3. str 숫자 Z로 업데이트
	4. 변경된 숫자 하나씩 더해나가며 1개의 숫자로 만듬
	5. 모두 더한 수 출력 

	오답노트
	- number값에서 이전 위치값이 더 큰 경우 올림을 안해줘서 제대로 comp가 동작하지 않음
	   =>   number[i][j] %= 36;
			number[i][j+1] += next;
*/
using namespace std;

int n, k;
int number[36][50];
vector<string> str;
vector<int> sorted_number;

int char_to_idx(char c){
	if(c >= '0' && c <= '9')
		return c - '0';
	else
		return c - 'A' + 10;
}

char idx_to_char(int idx){
	if(idx >= 10)
		return 'A' + idx - 10;
	else
		return '0' + idx;
}

bool comp(int a, int b){
	for(int i = 49; i >= 0; i--){
		if(number[a][i] != number[b][i])
			return number[a][i] > number[b][i];
	}
	
	return number[a][0] > number[b][0];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    
    for(int i = 0; i < n; i++){
		string s;
    	
		cin>>s;
    	str.push_back(s);
    }
    
    for(int i = 0; i < n; i++){
    	int m = str[i].size();
    	for(int j = 0; j < m; j++){
    		int cur = m - 1 - j;
    		int idx = char_to_idx(str[i][cur]);
    		
    		number[idx][j] += 35 - idx;
		}
	}
	
	for(int i = 0; i < 36; i++){
		for(int j = 0; j < 49; j++){
			int next = number[i][j] / 36;
			
			number[i][j] %= 36;
			number[i][j+1] += next;
		}
	}
	cin>>k;
	
	for(int i = 0; i < 36; i++)
		sorted_number.push_back(i);
	
	sort(sorted_number.begin(), sorted_number.end(), comp);
	
	
	for(int i = 0; i < k; i++){
		char target = idx_to_char(sorted_number[i]);
		for(int j = 0; j < n; j++){
			for(int l = 0; l < str[j].size(); l++){
				if(target == str[j][l])
					str[j][l] = 'Z';
			}
		}
	}
	
	while(str.size() > 1){
		string s = str[str.size()-1];
		string f = str[0];
		string n = "";
		int next = 0;
		int mx = max(s.size(), f.size());
		
		str.pop_back();
		
		for(int i = 0; i < mx; i++){
			int num = next;
			
			if(i < f.size())
				num += char_to_idx(f[f.size() - 1 - i]);
			if(i < s.size())
				num += char_to_idx(s[s.size() - 1 - i]);
			
			if(num >= 36){
				next = 1;
				num -= 36;
			}
			else
				next = 0;
			
			n = idx_to_char(num) + n;
		}
		
		if(next == 1)
			n = '1' + n;
		
		str[0] = n;
	}
	
	cout<<str[0];
    return 0;
}
