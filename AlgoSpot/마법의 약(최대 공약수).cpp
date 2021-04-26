#include <bits/stdc++.h>
using namespace std;
int minFactor[1001];

//�����佺�׳׽��� ü 
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
		//���� 1�κ��� ���� �Է� 
		for(int i = 0; i < n; i++){
			int p;
			
			cin>>p;
			best.push_back(p);
		}
		
		//���� ���� ���� �Է� 
		for(int i = 0; i < n; i++){
			int p;
			
			cin>>p;
			cur.push_back(p);
		}
		
		//�ִ����� 
		int minPower = 1;
		
		//��� 1�̵ɶ����� �ݺ� 
		while(best[0] > 1){
			int first_minFactor = minFactor[best[0]];
			bool check = false;
			
			for(int i = 1; i < n; i++){
				//������� ���� ��� 
				if(minFactor[best[i]] != first_minFactor){
					check = true;
					break;
				}
			}
			
			//����� ���°�� ���� 
			if(check)
				break;
				
			//�ּ� ������� ������Ʈ 
			minPower *= first_minFactor;
			
			//������� ���� 
			for(int i = 0; i < n; i++)
				best[i] /= first_minFactor;
		}
		
		//�̹� ���� ����� ������ ����ū ���� Ž�� 
		for(int i = 0; i < n; i++){
			int multi = cur[i] / best[i];
			
			if(cur[i] % best[i] != 0)
				multi++;
			
			minPower = max(minPower, multi);
		}
		
		//�ּ� �־���� ������ ���� �������� ���̸� ��� 
		for(int i = 0; i < n; i++)
			cout<<best[i]*minPower - cur[i]<<" ";
		
		cout<<"\n";
	}
	
    return 0;
}
