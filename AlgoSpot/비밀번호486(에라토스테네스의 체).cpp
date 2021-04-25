#include <bits/stdc++.h>
#define MAX 10000001
using namespace std;

int factors[MAX];
int minFactor[MAX];
int minFactorPower[MAX];

//�Ҽ� -> minFactor�� �ڱ��ڽ�  
void eratos(){
	minFactor[0] = -1;
	minFactor[1] = -1;
	
	for(int i = 2; i < MAX; i++)
		minFactor[i] = i;
	
	int nsqrt = int(sqrt(MAX-1));
	for(int i = 2; i <= nsqrt; i++){
		if(minFactor[i] == i){
			for(int j = i*i; j < MAX; j+=i){
				if(minFactor[j] == j)
					minFactor[j] = i;
			}
		}
	}
} 

//num�� ���μ��� ã�� ������ ��(�ð� �ʰ� �߻�) 
bool check(int num, int n){
	unordered_map<int, int> factors;
	unordered_map<int, int>::iterator it;
	
	while(num > 1){
		int facto = minFactor[num];
		factors[facto]++;
		
		num /= facto;
	}
	
	int cnt = 1;
	for(it = factors.begin(); it != factors.end(); it++)
		cnt *= it->second+1;
	
	return cnt == n;
}

//1000�������� ���� ��� ����� ������ ���ϴ� ��� => O(nlogn)
void get_factors(){
	for(int div = 1; div < MAX; div++){
		for(int multi = div; multi < MAX; multi += div)
			factors[multi]++;
	}
}

//���� �ּ� ���μ��� �������� ���� ���ϴ� ��� 
void get_smartFactors(){
	factors[1] = 1;
	
	for(int i = 2; i < MAX; i++){
		if(minFactor[i] == i){
			factors[i] = 2;
			minFactorPower[i] = 1;
		}
		else{
			int p = minFactor[i];
			int m = i / p;
			
			if(minFactor[m] != p)
				minFactorPower[i] = 1;
			else
				minFactorPower[i] = minFactorPower[m] + 1;
			
			int a = minFactorPower[i];
			factors[i] = (factors[m] / a) * (a+1); 
		}
	}
}
int main(){   
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int t, n, l, h;
	
	cin>>t;
	eratos();
	get_smartFactors();
	//get_factors();
	//eratos();
	for(int k = 0; k < t; k++){
		cin>>n>>l>>h;
		
		int cnt = 0;	
		for(int i = l; i <= h; i++){
			//if(check(i, n))
				//cnt++;
			if(factors[i] == n)
				cnt++;
		}
		
		cout<<cnt<<"\n";
	}
    return 0;
}
