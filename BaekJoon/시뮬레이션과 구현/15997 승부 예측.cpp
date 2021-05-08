#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Data{
	public:
		int home;
		int away;
		double win;
		double draw;
		double lose;
		
		Data(int home, int away, double win, double draw, double lose){
			this->home = home;
			this->away = away;
			this->win = win;
			this->draw = draw;
			this->lose = lose;
		}
};

unordered_map<string, int> str_to_int;
vector<double> percentage;
vector<pair<int, int> > points;
vector<Data> games;
 
void solve(int game, double p)
{
	if(game == 6){
		vector<pair<int, int> > tmp = points;
		vector<int> firsts;
		vector<int> seconds;
		//승점순으로 정렬 
		sort(tmp.begin(), tmp.end(), greater<>());
		//가장큰값을 first에 저장 
		int first = tmp[0].first;
		firsts.push_back(tmp[0].second);
		//second -1로 초기화 
		int second = -1;
		
		for(int i = 1; i < tmp.size(); i++){
			//승점 최고점과 같으면 
			if(first == tmp[i].first)
				firsts.push_back(tmp[i].second);
			//second가 아직없거나 second와 같으면 
			else if(second == -1 || second == tmp[i].first){
				seconds.push_back(tmp[i].second);
				second = tmp[i].first;
			}
		}
		
		//3팀이상이 최고점일때 
		if(firsts.size() > 2){
			for(int i = 0; i < firsts.size(); i++)
				//★1등이 2명이상인 경우 각 확률이 2/3, 2/4 이므로 *2.0을 해줘야한다. 
				percentage[firsts[i]] += p / firsts.size() *2.0; 
		}
		//2팀 이상이 최고점일때 
		else if(firsts.size() > 1){
			for(int i = 0; i < firsts.size(); i++)
				percentage[firsts[i]] += p;
		}
		//그 외에 경우 
		else{
			percentage[firsts[0]] += p;
			for(int i = 0; i < seconds.size(); i++)
				percentage[seconds[i]] += p / seconds.size();
		}
		
		return;
	}
	int h, a;
	double w, d, l;
	
	h = games[game].home;
	a = games[game].away;
	w = games[game].win;
	d = games[game].draw;
	l = games[game].lose;
	
	//홈팀 기준 
	//이겼을때
	if(w != 0.0){
		points[h].first += 3;
		solve(game+1, p*w);
		points[h].first -= 3;
	}
	//비겼을때
	if(d != 0.0){
		points[h].first += 1;
		points[a].first += 1;
		solve(game+1, p*d);
		points[h].first -= 1;
		points[a].first -= 1;
	}
	//졌을때
	if(l != 0.0){
		points[a].first += 3;
		solve(game+1, p*l);
		points[a].first -= 3;
	}
	 
}
int main(void)
{
	string str;
	
	//한줄 받기 
	getline(cin,str);
	int start = 0;
	int point;
	int idx = 0;
	
	//↓substr함수 선언부 
	//basic_string substr(size_type pos = 0, size_type count = npos) const;
	while((point = str.find(' ', start)) != -1){
		//substr(시작점, 크기); 
		str_to_int[str.substr(start, point - start)] = idx;
		percentage.push_back(0.0);
		points.push_back({0, idx});
		idx++;
		start = point + 1;
	}
	
	//마지막 substring 저장 
	str_to_int[str.substr(start)] = idx;
	percentage.push_back(0.0);
	points.push_back({0, idx});
	
	for(int i = 0; i < 6; i++){
		string h, a;
		double w, d, l;
		cin>>h>>a;
		cin>>w>>d>>l;
		
		games.push_back(Data(str_to_int[h], str_to_int[a], w, d, l));
	} 
	solve(0, 1.0);
	
	//결과 출력 
	for(int i = 0; i < percentage.size(); i++)
		printf("%.10lf\n",percentage[i]);
	
	
	return 0;
}
