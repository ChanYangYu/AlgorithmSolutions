#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

/*
	풀이
	 1. 처음 라인을 입력으로 받고 이를 기반으로 반납기한을 계산한다.
	 2. n번 반복문을 돌면서 입력을 받고, 입력에서 받은 시간을 2021년 1월 1일을
	    기준으로 하여 경과된 시간을 분 단위로 변환한다.
	 3. 부품이름/아이디를 키값으로 하는 해쉬맵을 보고 입력이 값이 있으면 반납이므로 
	    벌금여부를 체크하여 fee_list에 값을 추가한다.
	 4. fee_list를 iteration하면서 이름값과 벌금을 뽑아내고 이를 vector에 저장하여
	    정렬한 후 출력한다.
	
	오답노트
	 - long long 값 초과를 체크하지 못하여 오버플로우가 발생하였다.
	 - 이전 대여 여부를 초기화하는 코드를 if문에 종속시켜
	   제대로 잘못된 계산이 발생하였다. -> lent_list[key] = 0 
*/

unordered_map<string, int> lent_list;
int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
unordered_map<string, long long> fee_list;

int calc_days(int m, int d){
	int cur_m = 1;
	int cur_d = 1;
	int ret = 0;
	while(cur_m < m){
		ret += month_days[cur_m];
		cur_m++;
	}
	
	while(cur_d < d){
		ret++;
		cur_d++;
	}
	
	return ret;	
}

int to_minute(int d, int h, int m){
	return d * 60 * 24 + h * 60 + m;
}

int main(void) {
    int n, ddd, mm, hh, f;
    int limit;
    scanf("%d %03d/%2d:%2d %d", &n, &ddd, &hh, &mm, &f);

    limit = mm + hh*60 + ddd*60*24;
    for(int i = 0; i < n; i++){
    	int y, m, d, hh, mm;
    	string name, id;
    	string key;
    	
    	scanf("%d-%02d-%02d %02d:%02d",&y, &m, &d, &hh, &mm);
    	cin>>name>>id;
    	
    	key = name + "/" + id;
    	
    	int time = to_minute(calc_days(m,d), hh, mm);
    	if(lent_list[key] == 0){
    		// 값이 0이면 안되므로 +1 
    		lent_list[key] = time + 1;
		}
		else{
			int diff = time - lent_list[key] + 1;
			if(diff > limit)
				fee_list[id] += (diff-limit) * f;
			lent_list[key] = 0;
		}
	}
	
	vector<pair<string, long long> > res;
	unordered_map<string, long long> :: iterator it;
	for(it = fee_list.begin(); it != fee_list.end(); it++)
		res.push_back({it->first, it->second});
	
	sort(res.begin(), res.end());
	
	if(res.size() == 0)
		cout<<"-1";
	else
		for(int i = 0; i < res.size(); i++)
			cout<<res[i].first<<" "<<res[i].second<<"\n";
    return 0;
}
