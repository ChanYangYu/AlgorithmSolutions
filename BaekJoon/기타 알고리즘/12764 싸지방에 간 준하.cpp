#include <bits/stdc++.h>
using namespace std;

int use[100001]; 
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	int n;
	vector<pair<int, int> > v;
	
	cin>>n;
	
	for(int i = 0; i < n; i++){
		int s, e;
		
		cin>>s>>e;
		v.push_back({s,e});
	}
	
	sort(v.begin(), v.end());
	
	//computer -> ����ð�, �����ǻ�� ��ȣ
	priority_queue<pair<int, int> > computer;
	//���� �� ��ǻ�� ��ȣ
	priority_queue<int> wait;
	
	//��ǻ�� �ִ� ���� 
	int mx = 1;
	
	//O(2N)
	for(int i = 0; i < n; i++){
		int start = v[i].first;
		int end = v[i].second;
		
		//�̹� ����� ��ǻ�Ͱ� �ְų� ������ �ð��� ��ǻ�Ͱ� ������ 
		while(!computer.empty() && -(computer.top().first) <=  start){
			//�ּ� �켱���� ť �̹Ƿ� -ó�� 
			wait.push(-(computer.top().second));
			computer.pop();
		}
		
		if(!wait.empty()){
			//���� ������ȣ�� ��ǻ�� ��ȣ ���� 
			int comp_num = -(wait.top());
			wait.pop();
			
			//��ǻ�� ���Ƚ�� �߰� 
			use[comp_num]++;
			computer.push({-end, comp_num});
		}
		else{
			//���� ������� ��ǻ�Ͱ��� + 1��ȣ ��ǻ�� ��� 
			int comp_num = computer.size() + 1;
			
			//��ǻ�� ���Ƚ��  
			use[comp_num]++;
			computer.push({-end, comp_num});
		}
		
		//�ִ� ��ǻ�� ����Ȳ���� Ȯ�� 
		if(mx < computer.size())
			mx = computer.size();
	}
	
	//�ִ� ��� 
	cout<<mx<<endl;
	
	//��뷮 ��� 
	for(int i = 1; i <= mx; i++)
		cout<<use[i]<<" ";
	return 0;
}
