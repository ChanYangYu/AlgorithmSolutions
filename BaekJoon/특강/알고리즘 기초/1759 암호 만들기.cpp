#include <bits/stdc++.h>
using namespace std;

char alpha[16];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    int l, c;
    
    cin>>l>>c;
    
    for(int i = 0; i < c; i++)
    	cin>>alpha[i];
    
    vector<int> check(c, 1);
    
    for(int i = 0; i < l; i++)
    	check[i] = 0;
    
    priority_queue<string, vector<string>, greater<string> > pq;
    
    do{
    	bool has_vowel = false;
    	int consonant_cnt = 0;
    	string candidate = "";
    	for(int i = 0; i < c; i++){
    		if(check[i] == 0){
    			if(alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o'|| alpha[i] == 'u')
    				has_vowel = true;
    			else
    				consonant_cnt++;
    			candidate += alpha[i];
			}
		}
		
		if(has_vowel == false || consonant_cnt < 2)
			continue;
		sort(candidate.begin(), candidate.end());
		pq.push(candidate);
	}while(next_permutation(check.begin(), check.end()));
	
	while(!pq.empty()){
		cout<<pq.top()<<"\n";
		pq.pop();
	}
    return 0;
}
