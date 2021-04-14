#include<bits/stdc++.h>
using namespace std;
int unable[10];
/*�׸���� �� ��� �ʹ� ���� �ݷʰ� ���� �� �����Ƿ� 
  ����ȭ Ž���� ����� ��� �õ��غ���
*/ 

//���� �� �ִ��� üũ 
int check(int num){
	int digit = 0;
	while(num > 0){
		int t = num % 10;
		if(unable[t] != 0)
			return 0;
		
		num /= 10;
		digit++;
	}
	
	return digit;
}

int main(int argc, char** argv)
{
    cin.tie(0);
    //freopen("input.txt","rt",stdin);
    int n, m;
    
    cin>>n>>m;
	
    for(int i = 0; i < m; i++){
    	int x;
    	
    	cin>>x;
    	
    	unable[x] = 1;
	}
	
	//���� +/- ��ư���� �̵� 
	int res = abs(n - 100);
	
	//���� 50���������� ���Ѱ��� 100������ Ŀ���� �ؾ��� 
	for(int i = 0; i <= 1000000; i++){
		if(i == 0){
			//0�� ��� üũ 
			if(unable[0] == 0)
				res = min(res, abs(n - 0) + 1);
		}
		else{
			int digit = check(i);
			//���� �� �ִ� ������ ��� 
			if(digit){
				res = min(res, abs(n - i) + digit);				
			}
		}
	}
	
	cout<<res;
    return 0;
}
