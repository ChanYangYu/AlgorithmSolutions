#include <bits/stdc++.h>
using namespace std;
vector<int> per;
vector<int> num;
vector<int> sub;
int check[9];
int n, m;

//��� ȣ�� 
void my_combination(int cnt, int cur){
	if(cnt == m){
		for(int i = 0; i < m; i++)
			cout<<per[i]<<" ";
		cout<<"\n";
		return;
	}
	
	for(int i = cur; i < n; i++){
		if(check[i] == 0){
			per.push_back(num[i]);
			check[i] = 1;
			my_combination(cnt+1, i+1);
			check[i] = 0;
			per.pop_back();
		}
	}
}

int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	//���� �迭 �ʱ�ȭ 
	for(int i = 0; i < n; i++){
		num.push_back(i+1);
		sub.push_back(1);
	}
	
	//��ŷ �迭 �ʱ�ȭ 
	for(int i = 0; i < m; i++)
		sub[i] = 0;
	
	//���� �迭 ���� 
	sort(num.begin(), num.end());
	
	do{
		//��ŷ�� ��ġ ��� 
		for(int i = 0; i < n; i++)
			if(sub[i] == 0)
				cout<<num[i]<<" ";
			cout<<"\n";
	}while(next_permutation(sub.begin(), sub.end()));
	
	//my_combination(0, 0);
    return 0;
}
