#include<bits/stdc++.h>
using namespace std;

int num[10] = {6,2,5,5,4,5,6,3,7,6};
//1자리 수의 최솟값 
int one[9] = {0,0,1,7,4,2,6,8};
int res[201];
//현재 자릿수 = pos, 남아있는 개수 = remain, 남은 자릿수 = digit
int solve(int pos, int remain, int digit){
	if(digit == 0)
		return 1;
	
	int start = 0;
	//첫째자리인 경우 
	if(pos == 0)
		start++;
	
	//0 ~ 9 자릿수중 만들 수 있는 수부터 차례로 검토 
	for(int i = start; i < 10; i++){
		//해당 숫자를 만들 수 있는지 체크 
		if((remain - num[i]) >= 0){
			int a = remain - num[i];
			int b =  a / 7;
			
			//나머지 체크 
			if(a % 7 != 0)
				b += 1;
			
			//해당 숫자를 선택했을때 남은 자릿수가 최소자릿 수와 같은 경우 
			if(b == digit-1){
				//숫자 선택 
				res[pos] = i;
				//다음 자릿수 검토 
				if(solve(pos+1, remain - num[i], digit-1))
					return 1;
				res[pos] = 0;
			}
		}
	}
	
	//만들 수 없는 경우 
	return 0; 
	
}

string get_best(int n){
	string res = "";
	
	//짝수인 경우 
	if(n % 2 == 0)
		res += "1";
	//홀수인 경우 
	else
		res += "7";
	
	int cnt = n / 2;
	//남은 자릿수 1로 채움 
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
    	
    	//한자리 수의 최소값인 경우 
    	if(n < 8)
    		cout<<one[n]<<" "<<get_best(n)<<"\n";
    	//두자리 수 이상의 최솟값 체크 
    	else{
    		//한자리 당 7개가 최대로 가질 수 있는 수  
    		int digit = n / 7;
    		
    		//나머지가 있는경우 자릿수 추가 
    		if(n % 7 != 0)
    			digit++;
    		
    		//자릿수가 추가될수록 숫자가 더크다. 
    		solve(0, n, digit);
    		
    		for(int i = 0; i < digit; i++)
    			cout<<res[i];
    		cout<<" "<<get_best(n)<<"\n";
		}
    	
	}

    return 0;
}
