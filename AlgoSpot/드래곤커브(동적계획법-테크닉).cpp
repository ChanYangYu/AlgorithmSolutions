#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000001
int len[51];
void preCalc(){
	len[0] = 1;
	for(int i = 1; i <= 50; i++)
		len[i] = min(MAX, 2*len[i-1] + 2);
}

char expand(string curve, int gen, int skip){
	if(gen == 0){
		if(skip > curve.size())
			exit(-1);
		return curve[skip];
	}
	
	for(int i = 0; i < curve.size(); i++){
		if(curve[i] == 'X' || curve[i] == 'Y'){
			if(len[gen] <= skip)
				skip -= len[gen];
			else if(curve[i] == 'X')
				return expand("X+YF", gen-1, skip);
			else if(curve[i] == 'Y')
				return expand("FX-Y", gen-1, skip);
		}
		else if(skip > 0)
			skip--;
		else
			return curve[i];
	}
}


int main() {
	cin.tie(0);
	freopen("input.txt", "rt", stdin);
	
	int test_case;

    cin >> test_case;
    preCalc();
    
    for (int i = 0; i < test_case; i++){
    	int gen, skip, len;
		
		cin>>gen>>skip>>len;
		
		for(int i = skip; i < skip + len; i++)
			cout<<expand("FX", gen, i-1);
		cout<<"\n";
	}


	return 0;
}
