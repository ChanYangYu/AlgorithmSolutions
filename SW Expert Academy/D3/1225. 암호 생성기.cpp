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
        
        //5���� cylcle���� ��ü���� 15�� �����ϰ� �����Ͱ� ���ڸ��ο�
        //15�� �����ϰ� �����͵� ���ڸ��� ���ƿ��⶧����, �ּҰ��� 15�� ���������� �����ϸ� �ð��� �ſ� ������ �� ����
        int cycle = mn / 15;
        
        //����������� ��� ���������� 
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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
