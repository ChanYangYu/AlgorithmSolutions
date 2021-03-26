#include <bits/stdc++.h>
int maxsize[300001];
int pizzas[300001]; 
using namespace std;

int solve(int left, int right, int pizza){
	if(left == right){
		if(maxsize[left] >= pizza)
			return left;
		//���� ��ġ�� ���� ���ϴ� ��� 
		else
			return 0;
	}
	int mid = (left + right) / 2;
	
	//mid�� ȭ�� ũ�Ⱑ ����ũ�⺸�� ���� ��� 
	if(maxsize[mid] < pizza){
		//mid�� �� ��ĭ�� ��� 
		if(mid == 1)
			return 0;
		//���� ȭ���� ũ�Ⱑ ���ں��� ũ�ų� ���� ���
		else if(maxsize[mid-1] >= pizza)
			return mid-1;
		//left ~ mid-1 Ž�� 
		else
			return solve(left, mid-1, pizza);
	}
	//mid�� ȭ�� ũ�Ⱑ ����ũ�⺸�� ũ�ų� ���� ���  
	else{
		//���� ȭ�� ũ�⺸�� ���ڰ� ū��� 
		if(maxsize[mid+1] < pizza)
			return mid;
		//mid+1 ~ right Ž�� 
		else
			return solve(mid+1, right, pizza);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	int d, n;
	int end;
	
	cin>>d>>n;
	
	cin>>maxsize[1];
	for(int i = 2; i <= d; i++){
		cin>>maxsize[i];
		maxsize[i] = min(maxsize[i], maxsize[i-1]);
	}
	
	for(int i = 0; i < n; i++)
		cin>>pizzas[i];
	
	end = d;
	int pos;
	for(int i = 0; i < n; i++){
		if(end > 0){
			pos = solve(1, end, pizzas[i]);
			if(pos == 0)
				break;
			end = pos-1;
		}
		else{
			pos = 0;
			break;
		}
	}
	
	if(pos < 1)
		cout<<"0";
	else
		cout<<pos;
	return 0;
}
