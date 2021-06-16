/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> orange, blue;
vector<char> seq;

int solve(int bpos, int opos, int bnext, int onext, int turn){
	if(turn == seq.size())
		return 0;
	char who = seq[turn];
	int use_time;
	
	if(who == 'B'){
		use_time = abs(bpos - blue[bnext]) + 1;
		
		//���� ������ ��ġ���� �տ� �ִ� ��� 
		if(orange[onext] - opos < 0){
			//�ش� �ð����� �ű�� �̵� 
			opos -= use_time;
			
			//�ð��� �� ���� ��� ��ư ��ġ�θ� �̵� 
			if(opos < orange[onext])
				opos = orange[onext];
		}
		else if(orange[onext] - opos > 0){
			opos += use_time;
			
			//�ð��� �� ���� ��� ��ư ��ġ�θ� �̵� 
			if(opos > orange[onext])
				opos = orange[onext];
		} 
		//���� ���� �̵�x
		
		//blue��ġ button���� �̵� 
		bpos = blue[bnext];
		return solve(bpos, opos, bnext+1, onext, turn+1) + use_time;
	}
	else{
		
		use_time = abs(opos - orange[onext]) + 1;
		
		if(blue[bnext] - bpos < 0){
			//�ش� �ð����� �ű�� �̵� 
			bpos -= use_time;
			
			//�ð��� �� ���� ��� ��ư ��ġ�θ� �̵� 
			if(bpos < blue[bnext])
				bpos = blue[bnext];
		}
		else if(blue[bnext] - bpos > 0){
			bpos += use_time;
			
			//�ð��� �� ���� ��� ��ư ��ġ�θ� �̵� 
			if(bpos > blue[bnext])
				bpos = blue[bnext];
		} 
		//���� ���� �̵�x
		
		//blue��ġ button���� �̵� 
		opos = orange[onext];
		return solve(bpos, opos, bnext, onext + 1, turn+1) + use_time;
	}
		 
		
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","rt",stdin);
	
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		
		cin>>n;
		seq.clear();
		orange.clear();
		blue.clear();
		
		for(int i = 0; i < n; i++){
			char who;
			int button;
			
			cin>>who>>button;
			
			seq.push_back(who);
			
			if(who == 'B')
				blue.push_back(button);
			else
				orange.push_back(button);
		}
		
		int res = solve(1, 1, 0, 0, 0);
		cout<<"#"<<test_case<<" "<<res<<"\n";
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
