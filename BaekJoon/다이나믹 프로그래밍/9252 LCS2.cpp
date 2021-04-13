#include <bits/stdc++.h>
using namespace std;
//���ڿ� �迭 
char a[1001];
char b[1001];

//dp�迭 
int dp[1001][1001][4];
int main(void){
	ios_base::sync_with_stdio(false);
	vector<char> s;
	
	cin>>a>>b;
	
	//�ִ� ��Ī�� 
	int mx = 0;
	//�ִ� ��Ī�� ��ǥ 
	int x, y;
	//�� ���ڿ��� ���� 
	int n = strlen(a);
	int m = strlen(b);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			//���ڰ� ���� ��ġ�ϸ� 
			if(a[i-1] == b[j-1]){
				//�밢�� ��ġ�� ��ǥ���� dp[i][j][0],dp[i][j][1]�� ���� 
				dp[i][j][0] = i-1;
				dp[i][j][1] = j-1;
				//���簪�� ���õǾ����� ǥ�� 
				dp[i][j][2] = 1;
				//��Ī�� ���� 
				dp[i][j][3] = dp[i-1][j-1][3] + 1;
				
				//�ִ� ��Ī������ Ȯ�� 
				if(mx < dp[i][j][3]){
					//�ִ� ���� 
				 	mx = dp[i][j][3];
				 	//��ǥ ���� 
				 	y = i;
				 	x = j;
				 }
			}
			//���� ��ġ�� �հ� ���ǰ� �� ū���� ����
			else{ 
				if(dp[i][j-1][3] > dp[i-1][j][3]){
					dp[i][j][0] = i;
				 	dp[i][j][1] = j-1;
				 	//���õ��� �ʾ����� ǥ�� 
				 	dp[i][j][2] = 0;
				 	dp[i][j][3] = dp[i][j-1][3];
				}
				else{
					dp[i][j][0] = i-1;
				 	dp[i][j][1] = j;
				 	//���õ��� �ʾ����� ǥ��
				 	dp[i][j][2] = 0;
				 	dp[i][j][3] = dp[i-1][j][3];
				}
			}
		}
	}
	//�ִ��� 0�̻��̸� 
	if(mx > 0){
		//���������� ���õȰ� ���Ϳ� ���� 
		s.push_back(a[y-1]);
		while(x > 0 && y > 0){
			//bottom-up ������� Ž�� 
			int tmp = dp[y][x][0];
			x = dp[y][x][1];
			y = tmp;
			
			//���õǾ����� ���Ϳ� ���� 
			if(dp[y][x][2] == 1)
				s.push_back(a[y-1]);
		}
		//�ִ� ��Ī�� ��� 
		cout<<mx<<endl;
		//���͸� �������� ��� 
		for(int i = s.size()-1; i >= 0; i--)
			cout<<s[i];
	}
	else
		cout<<"0"<<endl;
	
    return 0;
}
