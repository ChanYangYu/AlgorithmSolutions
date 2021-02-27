#include <bits/stdc++.h>
using namespace std;

string str;

//���� ����
string divide_and_conquer(string::iterator& it){
	char head = *it;
	
	it++;	
	//������ �Ǿ������� 
	if(head == 'x'){
		string s1,s2,s3,s4;
		
		//���� ��� ���� string Ž��
		s1 = divide_and_conquer(it);

		//������ ��� ���� string Ž��		
		s2 = divide_and_conquer(it);
		
		//���� �ϴ� ���� string Ž�� 
		s3 = divide_and_conquer(it);
		
		//������ �ϴ� ���� string Ž�� 
		s4 = divide_and_conquer(it);
		
		// x + (�ϴ� ���� ���ڿ�) + (��� ���� ���ڿ�) 
		return string("x") + s3 + s4 + s1 + s2;
	}
	else
		//�����̵����ʾ����� ���� start���ڿ� ���� 
		return string(1,head);
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int n;
	string res;
	
	cin.tie(0);
	cin>>n;
	
	for(int i = 0; i < n; i++){
		cin>>str;
		string::iterator it = str.begin();
		res = divide_and_conquer(it);
		cout<<res<<"\n";
	}
	return 0;
} 
