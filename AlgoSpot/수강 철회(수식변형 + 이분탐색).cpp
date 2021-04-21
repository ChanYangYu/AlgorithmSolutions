#include <bits/stdc++.h>
using namespace std;
class Data{
	public:
		int r;
		int c;
		
		Data(int r, int c){
			this->r = r;
			this->c = c;
		}
		
};

vector<Data> info;

//x�� �ذ� �Ǵ��� ���� 
bool check(double x, int k){
	vector<double> v;
	
	// x = �������
	//���� ���� => (������ �� x) * (c�� ��) - (r�� ��) >= 0
	for(int i = 0; i < info.size(); i++)
		v.push_back(x*info[i].c - info[i].r);
	
	sort(v.begin(), v.end(),greater<double>());
	double sum = 0.0;
	
	//k�� �̻� ���� �ʿ���� ���� ū 5���� ���� ���� 0�� �Ѵ��� Ȯ�� 
	for(int i = 0; i < k; i++)
		sum += v[i];
	
	return sum >= 0;
	
}
int main(void){
	//ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	int t, n, k;
	
	cin>>t;
	
	for(int j = 0; j < t; j++){
		cin>>n>>k;
		
		info.clear();
				
		for(int i = 0; i < n; i++){
			int r, c;
			double p;
			
			cin>>r>>c;
			
			info.push_back(Data(r,c));
		}
		
		double left = 0.0;
		double right = 1.0;
		
		//10^-10���� ���� 
		while(right - left > 0.00000000001){
			double mid = (left + right) / 2.0;
			
			if(check(mid, k))
				right = mid;
			else
				left = mid;
			
		}
		
		printf("%.10lf\n",right);
	}	
    return 0;
}
