#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

bool ch[3201];
vector<int> prime;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 2; i <= 3200; i++){
    	if(ch[i])
    		continue;
    	for(int j = i+i; j <= 3200; j +=i){
    		ch[j] = 1;
		}
	}
	for(int i = 2; i <= 3200; i++){
		if(ch[i] == 0)
			prime.push_back(i);
	}
	
	int n;
	
	cin>>n;
	vector<int> nums(n);
	unordered_map<int, int> h;
	
	//��ü �Ҽ��� ���� ī���� 
	for(int i = 0; i < n; i++){
		cin>>nums[i];
		
		int tmp = nums[i];
		for(int j = 0; j < prime.size(); j++){
			if(tmp == 1)
				break;
			while(tmp % prime[j] == 0){
				h[prime[j]]++;
				tmp /= prime[j];
			}
		}
		//3200�̻��� �Ҽ� ī���� 
		if(tmp != 1)
			h[tmp]++;
	}
	
	unordered_map<int, int>::iterator it;
	vector<pair<int, int> > gcds;
	
	int res = 1;
	//�Ҽ����� ������ n���� ū ���鸸 ���� �ִ����� ���ϱ� 
	for(it = h.begin(); it != h.end(); it++){
		if((it->second) / n > 0){
			res *= pow(it->first, (it->second/n));
			gcds.push_back({it->first, it->second/n});
		}
	}
	
	int res_cnt = 0;
	
	//�Է¹��� n������ ������ ����� ���� ���ؼ� res_cnt�� ���ϱ� 
	for(int i = 0; i < nums.size(); i++){
		for(int j = 0; j < gcds.size(); j++){
			int target_cnt = gcds[j].second;
			int cur_cnt = 0;
			int target = gcds[j].first;
			int tmp = nums[i];
			
			while(tmp % target == 0){
				cur_cnt++;
				tmp /= target;
			}
			
			if(cur_cnt < target_cnt)
				res_cnt += target_cnt - cur_cnt;
		}
	}
	
	cout<<res<<" "<<res_cnt;
	
	return 0;
}
