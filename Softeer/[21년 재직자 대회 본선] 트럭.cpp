#include<bits/stdc++.h>
#define pii pair<int, int>

/*
 Ǯ�̹��
 1. ���� ȣ�������� custormer_request�� ����
 2. ��� ȣ�������� all_request�� ����
 3. all_request�� ������� ���� ���� ����
 4. all_request���� �� ������� sum�� ���Ͽ� sums�� �߰��Ѵ�.
 	- sums�� ������ �� �� �ִ�. (���� ������ �������� ������ ���)
	- �� ���� Ʈ���� �ϳ��� ��� ������ ������ ��� �����̶� �� �� �� ��ΰ� ���� ȣ���� �����ش�.
	- ���� ������ ȣ���� ���� �ε����� selected�� �����Ѵ�.
 5. sums���� �հ谪�� ���� bs�� �����, �ݺ����� ���鼭 q���� ū ���� ��ġ�� �̺�Ž������ ã�´�.
 6. bs���� ã�� �ε��� ���� �´� size���� sums���� ã�Ƽ� ����Ѵ�. 
*/

using namespace std;

class Data{
	public:
		int s;
		int p;
		int c;
		int idx;
		Data(int s, int p, int c, int idx){
			this->s = s;
			this->p = p;
			this->c = c;
			this->idx = idx;
		}
		bool operator<(const Data &a) const{
			return this->s < a.s;
		}
};

vector<pii> custormer_request[100001];
vector<Data> all_request;
vector<pair<int, long long> > sums;
int selected[100001];

int main(int argc, char** argv)
{
	int n, m;

	cin>>n;

	for(int i = 0; i < n; i++){
		int a;

		cin>>a;

		for(int j = 0; j < a; j++){
			int s, p;

			cin>>s>>p;
			custormer_request[i].push_back({s,p});
			all_request.push_back(Data(s,p,i,j));
		}

		selected[i] = -1;
	}

	sort(all_request.begin(), all_request.end());
	
	long long sum = 0;
	for(int i = 0; i < all_request.size(); i++){
		int s = all_request[i].s;
		int p = all_request[i].p;
		int c = all_request[i].c;
		int idx = all_request[i].idx;

		if(selected[c] != -1){
			int selected_price = custormer_request[c][selected[c]].second;

			// ���� �����Ѱ��� �� ũ��
			if(selected_price < p){
				selected[c] = idx;
				sum -= selected_price;
				sum += p;
			}
		}
		else{
			selected[c] = idx;
			sum += p;
		}

		if(!sums.empty() && sums.back().first == s)
			sums[sums.size()-1].second = sum;
		else
			sums.push_back({s, sum});
		
		mp[s] = sum;
	}

	vector<int> bs;
	for(int i = 0; i < sums.size(); i++)
		bs.push_back(sums[i].second);

	cin>>m;
	while(m--){
		int q;

		cin>>q;

		int idx = lower_bound(bs.begin(), bs.end(), q) - bs.begin();

		if(idx == bs.size())
			cout<<"-1 ";
		else 
			cout<<sums[idx].first<<" ";

	}
	return 0;
}
