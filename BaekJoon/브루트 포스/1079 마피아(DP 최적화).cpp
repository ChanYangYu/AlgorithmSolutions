#include<bits/stdc++.h>
using namespace std;
//DP 3^16 �������� 
char state[43046721];
int check[16];
int r[16][16];
int crime[16];
int n;
int square[16];
int mafia;

char solve(int idx, int remain){
	if(remain == 1)
		return 0;
	
	char& ret = state[idx];
	
	if(ret != -1)
		return ret;
	
	//�� 
	if(remain % 2 == 0){
		ret = 1;
		//����ִ� ��� �߿� ���ϻ�� ���� 
		for(int i = 0; i < n; i++){
			if(i != mafia && check[i] == 0){
				check[i] = 1;
				//���Ǿƿ� �������� ��� square[i] * 1 
				for(int k = 0; k < n; k++)
					crime[k] += r[i][k];
				
				char res = solve(idx + square[i], remain-1) + 1;
				ret = max(ret, res);
				for(int k = 0; k < n; k++)
					crime[k] -= r[i][k];
				check[i] = 0;
			}
		}
	}
	//�� 
	else{
		int target = -1;
		int mx = 0;
		//��ü ����ִ� ��� �� ���ϻ�� üũ 
		for(int i = 0; i < n; i++){
			//���� üũ
			if(check[i] == 1)
				continue;
			//������ üũ 
			if(mx < crime[i]){
				target = i;
				mx = crime[i];
			}
		}
		//���Ǿư� ���� ���
		if(target == mafia)
			return ret = 0;
		check[target] = 1;
		//�������� ������� square[i]*2 
		ret = solve(idx + square[target]*2, remain-1);
		check[target] = 0;
	}
	
	return ret;
}
int main(int argc, char** argv)
{
    cin.tie(0);
    //freopen("input.txt","rt",stdin);
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>crime[i];
    
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++)
    		cin>>r[i][j];
	}
	
	cin>>mafia;
	
	square[0] = 1;
	for(int i = 1; i < 16; i++)
    	square[i] = square[i-1] * 3;
    
    memset(state, -1, sizeof(state));
    
    int res = solve(0, n);
    
    cout<<res;
    
    return 0;
}
