#include <bits/stdc++.h>
#define ll long long
#define BIT 50

using namespace std;
int ch[BIT];

ll check(ll num, ll target, ll res){
    if (target < num && res > num)
        return num;
    else
        return res;
}

ll brute_force(ll target){
    ll res = 1000000000000001;
    for(int i = 0; i < BIT; i++){
        ll num = target;
        
        if(ch[i] == 0){
            ch[i] = 1;
            
            num ^= ((ll)1<<i);
            res = check(num, target, res);
            
            for(int j = i+1; j < BIT; j++){
                num ^= ((ll)1<<j);
                res = check(num, target, res);
                num ^= ((ll)1<<j);
            }
            ch[i] = 0;
        }
    }
    return res;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i = 0; i < numbers.size(); i++){
        answer.push_back(brute_force(numbers[i]));
    }
    return answer;
}
