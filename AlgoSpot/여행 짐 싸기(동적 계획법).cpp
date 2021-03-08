#include <bits/stdc++.h>
using namespace std;
int C, n, w;
int volume[102], need[102];
int cache[1002][102][2]; // 무게가 i일때 j번 아이템 이후에서 얻을 수 있는 절박도 
string name[102];
vector<string> ans;

void trace2(int capacity, int item){
	int& next = cache[capacity][item][1];
	
	int vol = volume[item];
	
	if(next == -1)
		return;
	else if(next == 0)
		trace2(capacity, item+1);
	else{
		ans.push_back(name[item]);
		trace2(capacity - vol, item+1);
	}
}

int pack(int capacity, int item)
{
    if (item == n+1)
        return 0;

    int &result = cache[capacity][item][0];
    int &next = cache[capacity][item][1];

    if (result != -1)
        return result;

    //이 물건을 담지 않을 경우
    result = pack(capacity, item + 1);
    next = 0;

    //이 물건을 담을 경우
    if (capacity >= volume[item]){
    	int tmp = pack(capacity - volume[item], item + 1) + need[item];
    	if(result < tmp){
    		result = tmp;
    		next = 1;
		}
	}

    return result;

}

void recon(int remain, int thing){
	if(thing == n+1)
		return;
	if(pack(remain, thing) == pack(remain, thing +1))
		recon(remain, thing + 1);
	else{
		ans.push_back(name[thing]);
		recon(remain - volume[thing], thing + 1);
	}
}

int main()
{
	cin >> C;
	while (C--) {
		cin >> n >> w;
		memset(cache, -1, sizeof(cache));
		ans.clear();
		for (int i = 1; i <= n; i++)
			cin >> name[i] >> volume[i] >> need[i];
		int res = pack(w,1);
		trace2(w, 1);
		cout << res << " " << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << endl;
		}
	}
	
	return 0;
}
