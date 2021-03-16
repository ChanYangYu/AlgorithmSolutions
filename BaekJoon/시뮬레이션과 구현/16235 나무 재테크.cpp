#include<bits/stdc++.h>
using namespace std;
vector<int> trees[11][11];
int a[11][11];
int f[11][11];
int dy[8] = {-1,1,0,0,1,-1,1,-1};
int dx[8] = {0,0,-1,1,1,-1,-1,1};


int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","rt",stdin);
	int n, m, k;
	
	cin>>n>>m>>k;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n ;j++){
			cin>>a[i][j];
			f[i][j] = 5;
		}
	}
	for(int i = 0; i < m; i++){
		int x, y, z;
		
		cin>>x>>y>>z;
		
		//이 부분 생각필요 
		trees[x][y].push_back(z);
	}
	
	for(int y = 0; y < k; y++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(trees[i][j].size() != 0){
					int size = trees[i][j].size();
					int l;
					//봄 
					for(l = 0; l < size; l++){
						//영양분 부족시 
						if(f[i][j] - trees[i][j][l] < 0)
							break;
						//영양분 흡수 
						f[i][j] -= trees[i][j][l];
						//나무 성장 
						trees[i][j][l]++;		
					}
					//여름
					if(l != size){
						//양분추가 
						for(int a = l;a < size; a++)
							f[i][j] += trees[i][j][a] / 2;
						//나무 제거 
						for(int a = l ;a < size; a++)
							trees[i][j].pop_back(); 
					}
				}
			}
		}
		//가을 
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				for(int l = 0; l < trees[i][j].size(); l++){
					//나이가 5의배수이면 
					if(trees[i][j][l] % 5 == 0){
						for(int a = 0; a < 8; a++){
							int yy = i + dy[a];
							int xx = j + dx[a];
							
							if(yy > n || yy < 1 || xx > n || xx < 1)
								continue;
							//나무 추가
							trees[yy][xx].push_back(1);
						}
					}
				}
			}
		}
		//어린순으로 나무 정렬 
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				sort(trees[i][j].begin(), trees[i][j].end());
		
		//겨울 
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				f[i][j] += a[i][j];	
	}
	
	int res = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			res += trees[i][j].size();
	
	cout<<res;
	
	return 0;
}
