#include<bits/stdc++.h>

using namespace std;
int check[100001];
int weight[100001];
int main(int argc, char** argv)
{
        cin.tie(0);
        int n, m;
        
        cin>>n>>m;
        
        for(int i = 1; i <= n; i++)
                cin>>weight[i];
        
        for(int i = 0; i < m; i++){
                int a, b;

                cin>>a>>b;
				
				//a보다 b가 더 세면 a는 최고x 
                if(weight[a] > weight[b])
                        check[b] = 1;
            	//b보다 a가 더 세면 b는 최고x 
                else if(weight[a] < weight[b])
                        check[a] = 1;
                //같은 무게를 들면 모두 최고x 
                else{
                        check[a] = 1;
                        check[b] = 1;
                }
        }

        int res = 0;
        for(int i = 1; i <= n; i++){
                if(check[i] != 1)
                        res++;
        }

        cout<<res;
        return 0;
}
