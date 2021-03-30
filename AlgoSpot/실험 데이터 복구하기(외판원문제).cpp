#include <bits/stdc++.h>
#define MAX 15
using namespace std;
string word[MAX];
int over[MAX][MAX];
int cache[1<<MAX][MAX][2];
int k;

//������ Ƚ�� 
int overlap(string& s1, string& s2)
{
	for (int len = min(s1.size(), s2.size()); len > 0; len--) {
		if (s1.substr(s1.size() - len) == s2.substr(0, len)) {
			return len;
		}
	}
	return 0;
}

//������ ���� ��� 
void trace(int used, int last, int o){
	int& t = cache[used][last][1];
	
	cout<<word[last].substr(o);
	
	if(t == -1)
		return;
	trace(used + (1<<t), t, over[last][t]);

}

int solve(int used, int last){
	if(used == (1<<k)-1)
		return 0;
	
	int& ret = cache[used][last][0];
	int& trace = cache[used][last][1];
		
	if(ret != -1)
		return ret;
	
	ret = -1;
	
	for(int i = 0; i < k; i++){
		//���� ���õ��� ���� ��� 
		if((used & (1<<i)) == 0){
			int tmp = solve(used + (1<<i), i) + over[last][i];
			//�ִ� �������� �Ǵ� ��� 
			if(ret < tmp){
				trace = i;
				ret = tmp;
			}
		}
	}
	
	return ret;
}

int main() {
	cin.tie(0);
	freopen("input.txt", "rt", stdin);
	
	int test_case;

    cin >> test_case;
    
    for (int i = 0; i < test_case; i++){
    	cin>>k;
    	
    	for(int j = 0; j < k; j++)
    		cin>>word[j];
    	
    	memset(cache, -1, sizeof(cache));
    	
    	//���ԵǴ� ���ڿ� ���� 
    	while (true) {
			bool removed = false;
			for (int i = 0; i < k && !removed; i++) {
				for (int j = 0; j < k; j++) {
					if (i != j && word[i].find(word[j]) != -1) {
						word[j] = word[k-1];
						k--;
						removed = true;
					}
				}
			}
			if (!removed) break;
		}
    	
    	int used = 0;
    	//��ġ�� Ƚ�� ���� 
    	for(int j = 0; j < k; j++)
    		for(int l = 0; l < k; l++)
    			over[j][l] = overlap(word[j],word[l]);
    	
    	
		int res = 0;
		int start = 0;
		//�ְ�� ���� ��ġ�� ���� Ž�� 
		for(int j = 0; j < k; j++){
			if((used & (1<<j)) == 0){
				int tmp = solve(used + (1<<j), j);
				if(tmp > res){
					res = tmp;
					start = j;
				}
			}
		}
		
		//�������������� Ž�� 
		trace(used + (1<<start), start, 0);
		cout<<"\n";
	}


	return 0;
}
