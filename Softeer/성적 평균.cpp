#include<bits/stdc++.h>


using namespace std;

int sum[1000001];
int main(int argc, char** argv)
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout.precision(2);
        int n, k;

        cin>>n>>k;
        for(int i = 1; i <=n; i++){
                cin>>sum[i];
                sum[i] += sum[i-1]; 
        }

        while(k--){
                int s, e;
                cin>>s>>e;

                int cnt = e - s + 1;
                int diff = sum[e] - sum[s-1];

                double avg = (double)diff / (double)cnt;

                cout<<avg<<"\n";

        }
        return 0;
}
