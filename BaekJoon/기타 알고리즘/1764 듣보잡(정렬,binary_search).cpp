#include <bits/stdc++.h>
using namespace std;
int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	vector<string> names;
	int n, m;
	
	
	cin>>n>>m;
	//���� ���� ��� ��� �Է� 
	for(int i = 0; i < n; i++){
		string name;
		
		cin>>name;
		
		names.push_back(name);
	}
	
	sort(names.begin(), names.end());
	vector<string> res;
	
	//�赵 ���� ��� ��ܰ� �� 
	for(int i = 0; i < m; i++){
		string name;
		
		cin>>name;
		
		//����Ž�� 
		if(binary_search(names.begin(), names.end(), name))
			res.push_back(name);
	}
	
	sort(res.begin(), res.end());
	
	cout<<res.size()<<"\n";
	for(int i = 0; i < res.size(); i++)
		cout<<res[i]<<"\n";
    return 0;
}
