#include <bits/stdc++.h>
using namespace std;

string str;

//���� ����
string divide_and_conquer(int start){
	//�� �κ� 
	string top;
	//�Ʒ� �κ� 
	string bottom;
	
	//������ �Ǿ������� 
	if(str[start] == 'x'){
		string s1,s2;
		//'x'�������� Ž�� 
		int len = start + 1;
		
		//���� ��� ���� string Ž��
		s1 = divide_and_conquer(len);
		//���� ������ġ�� ���� 
		len += s1.size();

		//������ ��� ���� string Ž��		
		s2 = divide_and_conquer(len);
		//���� ������ġ�� ����
		len += s2.size();
		
		//����� ���� ���� top�� ���� 
		top = s1 + s2;
		
		//���� �ϴ� ���� string Ž�� 
		s1 = divide_and_conquer(len);
		//���� ������ġ�� ����
		len += s1.size();
		
		//������ �ϴ� ���� string Ž�� 
		s2 = divide_and_conquer(len);
		//���� ������ġ�� ����
		len += s2.size();
		
		//�ϴ� �������� string�� ���� 
		bottom = s1 + s2;
		
		// x + (�ϴ� ���� ���ڿ�) + (��� ���� ���ڿ�) 
		return str.substr(start, 1) + bottom + top;
	}
	else
		//�����̵����ʾ����� ���� start���ڿ� ���� 
		return str.substr(start,1);
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
		res = divide_and_conquer(0);
		cout<<res<<"\n";
	}
	return 0;
} 
