#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    cin.tie(0);
    //freopen("input.txt","rt",stdin);
    unordered_map<int, int> a;
	
	int t;
	
	cin>>t;
	
	
	multiset<int> s;
	for(int k = 0; k < t; k++){
		multiset<int>::iterator iter;
		int n;
		
		cin>>n;
		
		//multiset �ʱ�ȭ 
		s.clear();
		for(int i = 0; i < n; i++){
			char ins;
			int num;
			
			cin>>ins>>num;
			//set�� ���� 
			if(ins == 'I')
				s.insert(num);
			else{
				//��������� ��ɾ� ���� 
				if(s.empty())
					continue;
				
				//�ִ� ���� 
				if(num == 1){ 
					iter = s.end();
					iter--;
					s.erase(iter);
				}
				//�ּڰ� ���� 
				else{
					iter = s.begin();
					s.erase(iter);
				}
			}
		}
		
		//��� ��� 
		if(s.empty())
			cout<<"EMPTY\n";
		else{
			iter = s.end();
			iter--;
			cout<<*iter<<" "<<*s.begin()<<"\n";
		}
	}
	
    return 0;
}
