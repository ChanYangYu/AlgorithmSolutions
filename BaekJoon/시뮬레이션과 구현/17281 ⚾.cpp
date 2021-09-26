#include<bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

int n;
int result[50][9];
int order[9];
int ch[9];
int max_score;
int c;


void simulation(){
	c++;
	bool first = false;
	bool second = false;
	bool third = false;
	int score = 0;
	int turn = 0;
	
	for(int i = 0; i < n; i++){
		int out = 0;
		while(out < 3){
			int res = result[i][order[turn]];
			if(res == 1){
				if(third){
					score++;
					third = false;
				}
				if(second){
					third = true;
					second = false;
				}
				if(first){
					second = true;
					first = false;
				}
				first = true;
			}
			else if(res == 2){
				if(third){
					score++;
					third = false;
				}
				if(second){
					score++;
					second = false;
				}
				if(first){
					third = true;
					first = false;
				}
				second = true;
			}
			else if(res == 3){
				if(third){
					score++;
					third = false;
				}
				if(second){
					score++;
					second = false;
				}
				if(first){
					score++;
					first = false;
				}
				third = true;
			}
			else if(res == 4){
				if(third){
					score++;
					third = false;
				}
				if(second){
					score++;
					second = false;
				}
				if(first){
					score++;
					first = false;
				}
				score++;
			}
			else
				out++;
			turn = (turn+1) % 9;
		}
		
		first = false;
		second = false;
		third = false;
	}
	
	max_score = max(max_score, score);
}
void make_order(int number){
	if(number == 9){
		simulation();
		return;
	}
	if(number == 3){
		make_order(number+1);
		return;
	}
	
	for(int i = 0; i < 9; i++){
		if(ch[i] == 0){
			ch[i] = 1;
			order[number] = i;
			
			make_order(number+1);
			ch[i] = 0;
			order[number] = 0;
		}	
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 9; j++)
			cin>>result[i][j];
	
	order[3] = 0;
	ch[0] = 1;
	
	make_order(0);
	
	cout<<max_score;
    return 0;
}
