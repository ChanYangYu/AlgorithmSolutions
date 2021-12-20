#include<bits/stdc++.h>
#define pii pair<int, int>

/*
 풀이방법
 1. 고객당 호가정보를 custormer_request에 저장
 2. 모든 호가정보를 all_request에 저장
 3. all_request를 사이즈로 오름 차순 정렬
 4. all_request에서 각 사이즈별로 sum을 구하여 sums에 추가한다.
 	- sums는 갱신이 될 수 있다. (같은 사이즈 연속으로 나오는 경우)
	- 한 고객은 트럭을 하나만 사기 때문에 이전에 샀던 내역이랑 비교 후 더 비싸게 쳐준 호가를 더해준다.
	- 고객이 선택한 호가의 정보 인덱스를 selected에 갱신한다.
 5. sums에서 합계값만 빼서 bs를 만들고, 반복문을 돌면서 q보다 큰 값의 위치를 이분탐색으로 찾는다.
 6. bs에서 찾은 인덱스 값에 맞는 size값을 sums에서 찾아서 출력한다. 
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

			// 고객이 제시한값이 더 크면
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
