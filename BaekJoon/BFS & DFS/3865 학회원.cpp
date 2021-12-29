#include <bits/stdc++.h>

using namespace std;

/*
	1. key -> vector<string>�� ���� mp�� Ȯȸ�� �´� ȸ���� ����
	2. ��ͷ� ���鼭 ��� ��ȸ�� elements�� ���� 
	3. ���� elements�� ����� ���
	
	�����Ʈ
	- ��������� ���� �̹� �湮�� ��ȸ�� üũ���� �ʾ� �޸� �ʰ��߻�! 
*/

vector<string> elements;
unordered_map<string, vector<string> > mp;
unordered_map<string, bool> v;
unordered_map<string, bool> ch;

void get_elements(string key){	
	for(int i = 0; i < mp[key].size(); i++){
		string element = mp[key][i];
		if(mp[element].size() > 0){
			if(!v[element]){
				v[element] = true;
				get_elements(element);	
			}
		}
		else if(!ch[element]){
			ch[element] = true;
			elements.push_back(element);
		}
	}
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	int n;
 	
 	cin>>n;
 	
 	while(n > 0){
 		mp.clear();
 		v.clear();
 		ch.clear();
 		elements.clear();
 		
		string target = "";
		
 		for(int i = 0; i < n; i++){
 			string s;
 			string name;
 			vector<string> arr;
 			int idx = 0;
 			
 			cin>>s;
 			
 			string tmp = "";
 			while(idx < s.size()){
 				if(s[idx] == ':'){
 					name = tmp;
 					tmp = "";
				 }
				else if(s[idx] == ',' || s[idx] == '.'){
					arr.push_back(tmp);
					tmp = "";
				}
				else{
					tmp += s[idx];
				}
				idx++;
			 }
			if(target == ""){
				target = name;
			}
			mp[name] = arr;
		}
		
		get_elements(target);
		cout<<elements.size()<<"\n";
		cin>>n;
	 }
 
    return 0;
}
