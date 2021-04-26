#include <bits/stdc++.h>
using namespace std;
int minFactor[1001];

//에라토스테네스의 체 
void eratos(){
	minFactor[0] = -1;
	minFactor[1] = -1;
	
	for(int i = 2; i <= 1000; i++)
		minFactor[i] = i;
	
	int nsqrt = int(sqrt(1000));
	for(int i = 2; i <= nsqrt; i++){
		if(minFactor[i] == i){
			for(int j = i*i; j <= 1000; j+=i){
				if(minFactor[j] == j)
					minFactor[j] = i;
			}
		}
	}
}

int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int t;
	
	eratos();
	cin>>t;
	
	for(int k = 0; k < t; k++){
		int n;
		vector<int> best;
		vector<int> cur;
		
		cin>>n;
		//물략 1인분의 재료양 입력 
		for(int i = 0; i < n; i++){
			int p;
			
			cin>>p;
			best.push_back(p);
		}
		
		//현재 냄비 재료양 입력 
		for(int i = 0; i < n; i++){
			int p;
			
			cin>>p;
			cur.push_back(p);
		}
		
		//최대공약수 
		int minPower = 1;
		
		//모두 1이될때까지 반복 
		while(best[0] > 1){
			int first_minFactor = minFactor[best[0]];
			bool check = false;
			
			for(int i = 1; i < n; i++){
				//공약수가 없는 경우 
				if(minFactor[best[i]] != first_minFactor){
					check = true;
					break;
				}
			}
			
			//공약수 없는경우 종료 
			if(check)
				break;
				
			//최소 공배수를 업데이트 
			minPower *= first_minFactor;
			
			//공배수로 나눔 
			for(int i = 0; i < n; i++)
				best[i] /= first_minFactor;
		}
		
		//이미 넣은 재료중 비율이 가장큰 것을 탐색 
		for(int i = 0; i < n; i++){
			int multi = cur[i] / best[i];
			
			if(cur[i] % best[i] != 0)
				multi++;
			
			minPower = max(minPower, multi);
		}
		
		//최소 넣어야할 비율과 현재 넣은양의 차이를 출력 
		for(int i = 0; i < n; i++)
			cout<<best[i]*minPower - cur[i]<<" ";
		
		cout<<"\n";
	}
	
    return 0;
}
