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
		
		//multiset 초기화 
		s.clear();
		for(int i = 0; i < n; i++){
			char ins;
			int num;
			
			cin>>ins>>num;
			//set에 삽입 
			if(ins == 'I')
				s.insert(num);
			else{
				//비어있으면 명령어 무시 
				if(s.empty())
					continue;
				
				//최댓값 삭제 
				if(num == 1){ 
					iter = s.end();
					iter--;
					s.erase(iter);
				}
				//최솟값 삭제 
				else{
					iter = s.begin();
					s.erase(iter);
				}
			}
		}
		
		//결과 출력 
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
