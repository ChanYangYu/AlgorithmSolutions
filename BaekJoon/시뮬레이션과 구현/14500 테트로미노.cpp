#include<bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(false);
    
    int p[19][8] = {
	{0,0,1,0,2,0,3,0}, // ¤Ó 
	{0,0,0,1,0,2,0,3},  
	{0,0,0,1,1,0,1,1}, // ¤± 
	{0,0,1,0,1,1,2,1},{0,0,1,0,1,-1,2,-1},{0,0,0,1,1,0,1,-1},{0,0,0,1,1,1,1,2}, // ¤¡+¤¤ 
	{0,0,0,1,0,2,1,1},{0,0,1,0,2,0,1,1},{0,0,1,0,1,-1,1,1},{0,0,1,0,1,-1,2,0},  // ¤Ç 
	{0,0,1,0,2,0,2,1},{0,0,1,0,2,0,2,-1},{0,0,1,0,1,-1,1,-2},{0,0,1,0,1,1,1,2}, //¤¡ 
	{0,0,0,1,1,1,2,1},{0,0,0,1,1,0,2,0},{0,0,0,1,0,2,1,0},{0,0,0,1,0,2,1,2}
	};
    
    int n, m,l;
    
    cin>>n>>m;
    int mx = -1;
    vector<vector<int> > a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < m; j++)
    		cin>>a[i][j];
    
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		for(int k = 0; k < 19; k++){
    			int num = 0;
    			for(l = 0; l < 8; l+=2){
    				if(i+p[k][l] >= n || i+p[k][l] < 0 || j+p[k][l+1] >= m || j+p[k][l+1] < 0)
    					break;
    				num += a[i+p[k][l]][j+p[k][l+1]];
				}
				if(l == 8 && mx < num)
					mx = num;
			}
		}
	}
	cout<<mx;
    return 0;
}
