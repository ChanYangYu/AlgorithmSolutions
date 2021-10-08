#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    unordered_map<string, string> parent;
    unordered_map<string, int> res;
    
    for(int i = 0; i < enroll.size(); i++){
        string name = enroll[i];
        string refer = referral[i];
        
        parent[name] = refer;
        res[name] = 0;
    }
    
    for(int i = 0; i < seller.size(); i++){
        string name = seller[i];
        int im = amount[i] * 100;
        while(im > 0){
            
            string ref = parent[name];
            int profit = im / 10;
            res[name] += im - profit;
            
            if(ref == "-")
                break;
            name = ref;
            im /= 10;
        }
    }
    
    for(int i = 0; i < enroll.size(); i++)
        answer.push_back(res[enroll[i]]);
    return answer;
}
