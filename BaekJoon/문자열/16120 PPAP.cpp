#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	string str;
	//현재까지 p의 개수 
	int count = 0;
	
	cin>>str;
	
	int size = str.size();
	for(int i = 0; i < size; i++){
        //A인 경우
		if(str[i] == 'A'){
            //다음 문자가 P인 경우
			if(i+1 < size && str[i+1] == 'P'){
				//이전에 PP가 온 경우
                if(count >= 2){
					count--;
					i++;	
				}
                //유망하지 않으므로 NP
				else{
					cout<<"NP";
					return 0;
				}
			}
            //유망하지 않으므로 NP
			else{
				cout<<"NP";
				return 0;
			}
		}
		//P인경우 
		else
			count++;	
	}
	
	if(count == 1)
		cout<<"PPAP";
	else
		cout<<"NP";
	return 0;
}
