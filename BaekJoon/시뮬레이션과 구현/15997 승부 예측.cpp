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
		//���������� ���� 
		sort(tmp.begin(), tmp.end(), greater<>());
		//����ū���� first�� ���� 
		int first = tmp[0].first;
		firsts.push_back(tmp[0].second);
		//second -1�� �ʱ�ȭ 
		int second = -1;
		
		for(int i = 1; i < tmp.size(); i++){
			//���� �ְ����� ������ 
			if(first == tmp[i].first)
				firsts.push_back(tmp[i].second);
			//second�� �������ų� second�� ������ 
			else if(second == -1 || second == tmp[i].first){
				seconds.push_back(tmp[i].second);
				second = tmp[i].first;
			}
		}
		
		//3���̻��� �ְ����϶� 
		if(firsts.size() > 2){
			for(int i = 0; i < firsts.size(); i++)
				//��1���� 2���̻��� ��� �� Ȯ���� 2/3, 2/4 �̹Ƿ� *2.0�� ������Ѵ�. 
				percentage[firsts[i]] += p / firsts.size() *2.0; 
		}
		//2�� �̻��� �ְ����϶� 
		else if(firsts.size() > 1){
			for(int i = 0; i < firsts.size(); i++)
				percentage[firsts[i]] += p;
		}
		//�� �ܿ� ��� 
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
	
	//Ȩ�� ���� 
	//�̰�����
	if(w != 0.0){
		points[h].first += 3;
		solve(game+1, p*w);
		points[h].first -= 3;
	}
	//�������
	if(d != 0.0){
		points[h].first += 1;
		points[a].first += 1;
		solve(game+1, p*d);
		points[h].first -= 1;
		points[a].first -= 1;
	}
	//������
	if(l != 0.0){
		points[a].first += 3;
		solve(game+1, p*l);
		points[a].first -= 3;
	}
	 
}
int main(void)
{
	string str;
	
	//���� �ޱ� 
	getline(cin,str);
	int start = 0;
	int point;
	int idx = 0;
	
	//��substr�Լ� ����� 
	//basic_string substr(size_type pos = 0, size_type count = npos) const;
	while((point = str.find(' ', start)) != -1){
		//substr(������, ũ��); 
		str_to_int[str.substr(start, point - start)] = idx;
		percentage.push_back(0.0);
		points.push_back({0, idx});
		idx++;
		start = point + 1;
	}
	
	//������ substring ���� 
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
	
	//��� ��� 
	for(int i = 0; i < percentage.size(); i++)
		printf("%.10lf\n",percentage[i]);
	
	
	return 0;
}
