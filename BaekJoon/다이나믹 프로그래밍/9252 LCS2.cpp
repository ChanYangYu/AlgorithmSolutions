#include <bits/stdc++.h>
using namespace std;
//문자열 배열 
char a[1001];
char b[1001];

//dp배열 
int dp[1001][1001][4];
int main(void){
	ios_base::sync_with_stdio(false);
	vector<char> s;
	
	cin>>a>>b;
	
	//최대 매칭값 
	int mx = 0;
	//최대 매칭된 좌표 
	int x, y;
	//각 문자열의 길이 
	int n = strlen(a);
	int m = strlen(b);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			//문자가 서로 일치하면 
			if(a[i-1] == b[j-1]){
				//대각선 위치의 좌표값을 dp[i][j][0],dp[i][j][1]에 저장 
				dp[i][j][0] = i-1;
				dp[i][j][1] = j-1;
				//현재값이 선택되었음을 표시 
				dp[i][j][2] = 1;
				//매칭값 저장 
				dp[i][j][3] = dp[i-1][j-1][3] + 1;
				
				//최대 매칭값인지 확인 
				if(mx < dp[i][j][3]){
					//최댓값 갱신 
				 	mx = dp[i][j][3];
				 	//좌표 저장 
				 	y = i;
				 	x = j;
				 }
			}
			//현재 위치의 앞과 위의값 중 큰값을 저장
			else{ 
				if(dp[i][j-1][3] > dp[i-1][j][3]){
					dp[i][j][0] = i;
				 	dp[i][j][1] = j-1;
				 	//선택되지 않았음을 표시 
				 	dp[i][j][2] = 0;
				 	dp[i][j][3] = dp[i][j-1][3];
				}
				else{
					dp[i][j][0] = i-1;
				 	dp[i][j][1] = j;
				 	//선택되지 않았음을 표시
				 	dp[i][j][2] = 0;
				 	dp[i][j][3] = dp[i-1][j][3];
				}
			}
		}
	}
	//최댓값이 0이상이면 
	if(mx > 0){
		//마지막으로 선택된값 벡터에 삽입 
		s.push_back(a[y-1]);
		while(x > 0 && y > 0){
			//bottom-up 방식으로 탐색 
			int tmp = dp[y][x][0];
			x = dp[y][x][1];
			y = tmp;
			
			//선택되었으면 벡터에 삽입 
			if(dp[y][x][2] == 1)
				s.push_back(a[y-1]);
		}
		//최대 매칭값 출력 
		cout<<mx<<endl;
		//벡터를 역순으로 출력 
		for(int i = s.size()-1; i >= 0; i--)
			cout<<s[i];
	}
	else
		cout<<"0"<<endl;
	
    return 0;
}
