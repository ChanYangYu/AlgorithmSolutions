#include <bits/stdc++.h>
using namespace std;
int mp[21][21];

class Data{
	public:
		int i;
		int j;
		int d;
		int num;
		Data(int i, int j, int d, int num){
			this->i = i;
			this->j = j;
			this->d = d;
			this->num = num;
		}
};

bool comp(Data a, Data b){
	if(a.d == b.d){
		if(a.i == b.i)
			return a.j < b.j;
		else
			return a.i < b.i;
	}
	else
		return a.d < b.d;
}

int main() {
	cin.tie(0);
	freopen("input.txt", "rt", stdin);
	int t;
	int n;
	
	cin>>t;
	
	cout<<t<<"\n";
	for(int k = 0; k < t; k++){
		cin>>n;
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin>>mp[i][j];
			}
		}
		
		vector<Data> res;
		int sum;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j < n; j++){
				if(mp[i][j] == 0 && mp[i][j+1] != 0){
					sum = 0;
					int l;
					for(l = j+1; l <= n; l++){
						if(mp[i][l] == 0)
							break;
						sum += mp[i][l];
					}
					res.push_back(Data(i,j,0, sum));
					j = l-1;			
				}
			}
		}
		
		for(int j = 1; j <= n; j++){
			for(int i = 1; i < n; i++){
				if(mp[i][j] == 0 && mp[i+1][j] != 0){
					sum = 0;
					int l;
					for(l = i+1; l <= n; l++){
						if(mp[l][j] == 0)
							break;
						sum += mp[l][j];
					}
					res.push_back(Data(i,j,1, sum));
					i = l-1;			
				}
			}
		}
		
		sort(res.begin(), res.end(), comp);
		
		
		cout<<n<<"\n";
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(mp[i][j] != 0)
					cout<<"1 ";
				else
					cout<<"0 ";
			}
			cout<<"\n";
		}
		
		cout<<res.size()<<"\n";
		for(int i = 0; i < res.size(); i++){
			cout<<res[i].i<<" "<<res[i].j<<" "<<res[i].d<<" "<<res[i].num<<"\n";
		}
				
	}
	return 0;
}
