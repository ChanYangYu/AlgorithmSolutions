#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

/*
	Ǯ��
	 1. ó�� ������ �Է����� �ް� �̸� ������� �ݳ������� ����Ѵ�.
	 2. n�� �ݺ����� ���鼭 �Է��� �ް�, �Է¿��� ���� �ð��� 2021�� 1�� 1����
	    �������� �Ͽ� ����� �ð��� �� ������ ��ȯ�Ѵ�.
	 3. ��ǰ�̸�/���̵� Ű������ �ϴ� �ؽ����� ���� �Է��� ���� ������ �ݳ��̹Ƿ� 
	    ���ݿ��θ� üũ�Ͽ� fee_list�� ���� �߰��Ѵ�.
	 4. fee_list�� iteration�ϸ鼭 �̸����� ������ �̾Ƴ��� �̸� vector�� �����Ͽ�
	    ������ �� ����Ѵ�.
	
	�����Ʈ
	 - long long �� �ʰ��� üũ���� ���Ͽ� �����÷ο찡 �߻��Ͽ���.
	 - ���� �뿩 ���θ� �ʱ�ȭ�ϴ� �ڵ带 if���� ���ӽ���
	   ����� �߸��� ����� �߻��Ͽ���. -> lent_list[key] = 0 
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
    		// ���� 0�̸� �ȵǹǷ� +1 
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
