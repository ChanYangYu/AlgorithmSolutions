#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
	int test_case;
	int T;

    int num[8];
    T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int idx, mn = INT_MAX;
        
        cin>>idx;
        
        for(int i = 0; i < 8; i++){
            cin>>num[i];
            mn = min(mn, num[i]);
        }
        
        //5번의 cylcle마다 전체값이 15씩 감소하고 포인터가 제자리로옴
        //15씩 감소하고 포인터도 제자리로 돌아오기때문에, 최소값을 15로 나눈값부터 검토하면 시간을 매우 절약할 수 있음
        int cycle = mn / 15;
        
        //나누어떨어지는 경우 이전값으로 
        if(mn % 15 == 0)
            cycle -= 1;
        
        for(int i = 0; i < 8; i++)
            num[i] %= cycle;
            

        int pointer = 0;
        int minus = 1;
        while(1){
            if(num[pointer % 8] - minus <= 0){
                num[pointer % 8] = 0;
                pointer++;
                break;
            }                         
            num[pointer % 8] -= minus;
            pointer++;
            
            if(minus == 5)
                minus = 1;
            else
            	minus++;
        }
        
        cout<<"#"<<idx<<" ";
        for(int i = 0; i < 8; i++)
            cout<<num[(pointer + i) % 8]<<" ";
		cout<<"\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
