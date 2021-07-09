#include <bits/stdc++.h>
#define ll long long
#define range cnts.begin(), cnts.end()
using namespace std;

int jong_h[500001];
int seok_h[500001];

//�������� �����Ѵ��� �ѹ��� ���ϴ� ���
//�������� +1 �������� ������ -1 ���ְ� �������� ���������� ������ �ö󰡸� ���� �� �ִ�. 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int n,h;
	
	cin>>n>>h;
	
	for(int i = 0; i < n; i++){
		int height;
		
		cin>>height;
		
		if(i % 2 == 0){
			seok_h[1]++;
			seok_h[height+1]--;
		}
		else{
			jong_h[h]++;
			jong_h[h-height]--;
		}
	}
	for(int i = 1; i <= h; i++){
		seok_h[i] += seok_h[i-1];
		jong_h[h-i] += jong_h[h-i+1];
	}
	
	vector<int> cnts;
	for(int i = 1; i <= h; i++)
		cnts.push_back(seok_h[i] + jong_h[i]);
	
	sort(range);
	int res = cnts[0];
	int res_cnt = upper_bound(range, res) - lower_bound(range, res);
	
	cout<<res<<" "<<res_cnt;	
}
