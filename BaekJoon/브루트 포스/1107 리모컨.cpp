#include<bits/stdc++.h>
using namespace std;
int unable[10];
/*그리디로 할 경우 너무 많은 반례가 생길 수 있으므로 
  최적화 탐색이 어려운 경우 시도해볼것
*/ 

//만들 수 있는지 체크 
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
	
	//직접 +/- 버튼으로 이동 
	int res = abs(n - 100);
	
	//수가 50만까지지만 상한값인 100만까지 커버를 해야함 
	for(int i = 0; i <= 1000000; i++){
		if(i == 0){
			//0인 경우 체크 
			if(unable[0] == 0)
				res = min(res, abs(n - 0) + 1);
		}
		else{
			int digit = check(i);
			//만들 수 있는 숫자인 경우 
			if(digit){
				res = min(res, abs(n - i) + digit);				
			}
		}
	}
	
	cout<<res;
    return 0;
}
