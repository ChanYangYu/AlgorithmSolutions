#include <bits/stdc++.h>
#define ll long long 
using namespace std;

class Data{
	public:
		int number;
		int recommand;
		int in_time;
		
		Data(int number, int in_time){
			this->number = number;
			this->in_time = in_time;
			this->recommand = 1;
		}
		bool operator<(const Data &a) const{
			if(this->recommand == a.recommand){
				return this->in_time < a.in_time;
			}
			else
				return this->recommand < a.recommand;
		}
};
vector<Data> photo;
int cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    
    int n, k;
    
    cin>>n>>k;
    
    for(int i = 0; i < k; i++){
    	int r;
    	
    	cin>>r;
    	
    	//이미 걸려있는 학생이 추천 받은 경우 
    	bool check = false;
    	for(int j = 0; j < photo.size(); j++){
    		//추천수 증가 
    		if(r == photo[j].number){
    			check = true;
    			photo[j].recommand++;
    			break;
    		}
		}
		
		//이미 처리된 경우 
		if(check)
			continue;
		
		//아직 틀이 남은 경우 
    	if(cnt < n){
    		cnt++;
    		photo.push_back(Data(r, i));
    	}
    	else{
    		//정렬 후 가장 앞부분에 덮어쓰기(앞부분 나가야할 학생) 
    		sort(photo.begin(), photo.end());
    		photo[0].number = r;
    		photo[0].in_time = i;
    		photo[0].recommand = 1;
		}
	}
	
	vector<int> res; 
	for(int i = 0; i < photo.size(); i++)
		res.push_back(photo[i].number);
	
	sort(res.begin(), res.end());
	
	for(int i = 0; i < photo.size(); i++)
		cout<<res[i]<<" ";
	
	return 0;
}
