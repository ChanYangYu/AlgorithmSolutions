#include<bits/stdc++.h>
using namespace std;

int num[10] = {6,2,5,5,4,5,6,3,7,6};
//1�ڸ� ���� �ּڰ� 
int one[9] = {0,0,1,7,4,2,6,8};
int res[201];
//���� �ڸ��� = pos, �����ִ� ���� = remain, ���� �ڸ��� = digit
int solve(int pos, int remain, int digit){
	if(digit == 0)
		return 1;
	
	int start = 0;
	//ù°�ڸ��� ��� 
	if(pos == 0)
		start++;
	
	//0 ~ 9 �ڸ����� ���� �� �ִ� ������ ���ʷ� ���� 
	for(int i = start; i < 10; i++){
		//�ش� ���ڸ� ���� �� �ִ��� üũ 
		if((remain - num[i]) >= 0){
			int a = remain - num[i];
			int b =  a / 7;
			
			//������ üũ 
			if(a % 7 != 0)
				b += 1;
			
			//�ش� ���ڸ� ���������� ���� �ڸ����� �ּ��ڸ� ���� ���� ��� 
			if(b == digit-1){
				//���� ���� 
				res[pos] = i;
				//���� �ڸ��� ���� 
				if(solve(pos+1, remain - num[i], digit-1))
					return 1;
				res[pos] = 0;
			}
		}
	}
	
	//���� �� ���� ��� 
	return 0; 
	
}

string get_best(int n){
	string res = "";
	
	//¦���� ��� 
	if(n % 2 == 0)
		res += "1";
	//Ȧ���� ��� 
	else
		res += "7";
	
	int cnt = n / 2;
	//���� �ڸ��� 1�� ä�� 
	for(int i = 1; i < cnt; i++)
		res += "1";
	
	return res;
}

int main(int argc, char** argv)
{
    cin.tie(0);
    //freopen("input.txt","rt",stdin);
    int t;
    
    cin>>t;
    for(int i = 0; i < t; i++){
    	int n;
    	
    	cin>>n;
    	
    	//���ڸ� ���� �ּҰ��� ��� 
    	if(n < 8)
    		cout<<one[n]<<" "<<get_best(n)<<"\n";
    	//���ڸ� �� �̻��� �ּڰ� üũ 
    	else{
    		//���ڸ� �� 7���� �ִ�� ���� �� �ִ� ��  
    		int digit = n / 7;
    		
    		//�������� �ִ°�� �ڸ��� �߰� 
    		if(n % 7 != 0)
    			digit++;
    		
    		//�ڸ����� �߰��ɼ��� ���ڰ� ��ũ��. 
    		solve(0, n, digit);
    		
    		for(int i = 0; i < digit; i++)
    			cout<<res[i];
    		cout<<" "<<get_best(n)<<"\n";
		}
    	
	}

    return 0;
}
