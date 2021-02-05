#include <bits/stdc++.h>
using namespace std;
//k개의 랜선길이를 담는 배열 
long long lan[10000];

int main(void){
	ios_base::sync_with_stdio(false);
	
	//변수 선언 
	long long k, n, sum = 0;
	
	cin>>k>>n;
	
	//k개의 랜선 입력받으면서 합을 구함 
	for(int i = 0; i < k; i++){
		cin>>lan[i];
		sum += lan[i];
	}
	
	//가장 큰 길이는 모든길이의 합을 n으로 나눈 크기 
	long long best = sum/n;
	
	while(1){
		//현재 길이로 나오는 랜선의 개수 
		long long cnt = 0;
		//다음으로 가장 유력한 최대 길이 
		long long next_best = 0;
		for(int i = 0; i < k; i++){
			//최댓값으로 나눴을때 나오는 랜선의 개수 
			long long m = lan[i]/best;
			//나눠진 개수보다 1개 많았을때의 랜선의 길이 
			long long c = lan[i]/(m+1);
			
			cnt += m;
			//가장 유력한 최대길이를 선정 
			if(next_best < c)
				74
		}
		//개수가 n개이상이면 종료 
		if(cnt >= n)
			break;
		//다음 유력한 최대길이로 갱신 
		else
			best = next_best;
	}
	
	//best값 출력 
	cout<<best;
	
    return 0;
}
