#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	string str;
	//������� p�� ���� 
	int count = 0;
	
	cin>>str;
	
	int size = str.size();
	for(int i = 0; i < size; i++){
        //A�� ���
		if(str[i] == 'A'){
            //���� ���ڰ� P�� ���
			if(i+1 < size && str[i+1] == 'P'){
				//������ PP�� �� ���
                if(count >= 2){
					count--;
					i++;	
				}
                //�������� �����Ƿ� NP
				else{
					cout<<"NP";
					return 0;
				}
			}
            //�������� �����Ƿ� NP
			else{
				cout<<"NP";
				return 0;
			}
		}
		//P�ΰ�� 
		else
			count++;	
	}
	
	if(count == 1)
		cout<<"PPAP";
	else
		cout<<"NP";
	return 0;
}
