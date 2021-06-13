#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, s;

//n/2 ũ���� ��� �κм����� �� ��� 
void calc(vector<int> &arr, vector<int> &c, int idx, int state, int sum){
	if(idx == c.size())
		return;
	int choose_state = (state | (1<<idx));
	
	calc(arr, c, idx+1, choose_state, sum + c[idx]);
	arr[choose_state] = sum + c[idx];
	calc(arr, c, idx+1, state, sum);
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s;
	
	int a_cnt = n/2;
	int b_cnt = n - a_cnt;
	vector<int> a((1<<a_cnt));
	vector<int> b((1<<b_cnt));
	
	vector<int> arr1(a_cnt);
	vector<int> arr2(b_cnt);
	
	for(int i = 0; i < a_cnt; i++)
		cin>>arr1[i];
	for(int i = a_cnt; i < n; i++)
		cin>>arr2[i-a_cnt];
	
	calc(a, arr1, 0, 0, 0);
	calc(b, arr2, 0, 0, 0);
	
	ll res = 0;
	
	//������ �κм����� �� �� S���� ��� üũ 
	for(int i = 1; i < a.size(); i++)
		if(a[i] == s)
			res++;
	for(int i = 1; i < b.size(); i++)
		if(b[i] == s)
			res++;
	//b�� 0�ΰ�� �ǵڷ� 
	b[0] = 987654321;
	
	//b ���� 
	sort(b.begin(), b.end());
	
	//a�� b�� ���� S�� ��� ����� �� ���� 
	for(int i = 1; i < a.size(); i++){
		int target = s - a[i];
		//target <= x < target ���� res�� ���� 
		res += upper_bound(b.begin(), b.end(), target) - lower_bound(b.begin(), b.end(), target);
	}
	
	cout<<res;
	return 0;
}
