#include <bits/stdc++.h>
#define ll long long
using namespace std;
//�ܾ� �迭 
string w[51];

//����ģ ���� �迭 
int ch[26];

//�ߺ�üũ �迭 
int dup_ch[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "rt", stdin);
	
	int n, k;
	//��� �ܾ�� �ʼ� ���� �̿� �ʿ��� ���� ����
	vector<char> req_char; 
	cin>>n>>k;
	
 
	for(int i = 0; i < n; i++){
		cin>>w[i];
		for(int j = 0; j < w[i].size(); j++){
			//���̻� ���λ�� ���� 
			if(w[i][j] == 'a' || w[i][j] == 'n' || w[i][j] == 't' || w[i][j] == 'i' || w[i][j] == 'c')
				continue;
			//���λ� ���̻� �̿ܿ� ������ ���(�ߺ��ؼ� ���� �ȵǵ��� üũ �ʿ�) 
			if(dup_ch[w[i][j] - 'a'] == 0){
				req_char.push_back(w[i][j]);
				dup_ch[w[i][j] - 'a'] = 1;
			}
		}
	}
	
	//�ʼ� ���� ���ϸ� ����ĥ �� �ִ� ��� 
	if(k < 5){
		cout<<"0";
		return 0;
	}
	
	k -= 5;
	//�ʼ� ���� üũ 
	ch['a' - 'a'] = 1;
	ch['n' - 'a'] = 1;
	ch['t' - 'a'] = 1;
	ch['i' - 'a'] = 1;
	ch['c' - 'a'] = 1;
	
	//�ʿ��� ��� ���ڸ� ��� �� �ִ� ��� 
	if(k >= req_char.size()){
		cout<<n;
		return 0;
	}
	
	vector<int> c(req_char.size(), 1);
	int res = 0;
	
	for(int i = 0; i < k; i++)
		c[i] = 0;
		
	//��� ���� Ž��
	int test = 0;
	
#ifdef DEBUG
	cout<<req_char.size()<<" C "<<k<<" = ";
#endif
	do{
		//���� �� �ִ� ���� üũ 
		for(int i = 0; i < req_char.size(); i++)
			if(c[i] == 0)
				ch[req_char[i] - 'a'] = 1;
		test++;
			
		int cnt = 0;
		//n�� �ܾ� üũ 
		for(int j = 0; j < n; j++){
			int size = w[j].size();
			bool check = true;
			
			//���λ� ���̻� ���� ���� üũ 
			for(int k = 4; k < size-4; k++){
				int idx = w[j][k] - 'a';
				if(ch[idx] != 1){
					check = false;
					break;
				}
			}
			
			//���� �� �ִ� �ܾ��� ��� 
			if(check)
				cnt++;
			
		}
		
		//�ִ� ���� ���� 
		res = max(res, cnt);
		
		//���� �ٽ� �ǵ����� 
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
