#include<iostream>
#include <bits/stdc++.h>
using namespace std;

char ch[1500][1500];

//������ Ŭ���� ���� 
class Data{
	public:
		int a;
		int b;
		int c;
		Data(int a, int b, int c){
			this->a = a;
			this->b = b;
			this->c = c;
		}
};

//�ΰ��� �����Ǹ� �������� �ڵ����� ����(������ ���x) 
void fill_ch(int a, int b, int c){
	ch[a][b] = 1;
	ch[b][a] = 1;
	ch[a][c] = 1;
	ch[c][a] = 1;
	ch[b][c] = 1;
	ch[c][b] = 1;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int a, b, c;
	
	cin>>a>>b>>c;
	
	//3�� ����� �ƴϸ� 
	if((a+b+c) % 3 != 0)
		cout<<"0";
	else{ 
		fill_ch(a,b,c);
		queue<Data> q;
		int res = 0;
		
		q.push(Data(a,b,c));
		
		while(!q.empty()){
			int a = q.front().a;
			int b = q.front().b;
			int c = q.front().c;
			
			q.pop();
			
			//��� ������ üũ 
			if(a == b && b == c){
				res = 1;
				break;
			}
			
			//�̹� ������ �������� Ȯ�� 
			if(a < b && ch[2*a][b-a] == 0){
				q.push(Data(2*a, b-a, c));
				fill_ch(a,b,c);
			}
			if(a < c && ch[2*a][c-a] == 0){
				q.push(Data(2*a, b, c-a));
				fill_ch(a,b,c);
			}
			if(b < a && ch[a-b][2*b] == 0){
				q.push(Data(a-b, 2*b, c));
				fill_ch(a,b,c);
			}
			if(b < c && ch[2*b][c-b] == 0){
				q.push(Data(a, 2*b, c-b));
				fill_ch(a,b,c);
			}
			if(c < a && ch[a-c][2*c] == 0){
				q.push(Data(a-c, b, 2*c));
				fill_ch(a,b,c);
			}
			if(c < b && ch[b-c][2*c] == 0){
				q.push(Data(a, b-c, 2*c));
				fill_ch(a,b,c);
			}
		}
		
		//���� ���Դ��� üũ 
		if(res)
			cout<<"1";
		else
			cout<<"0";
	}
	return 0;
}
