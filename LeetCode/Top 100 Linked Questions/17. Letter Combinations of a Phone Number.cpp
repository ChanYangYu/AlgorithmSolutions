class Solution {
public:
    vector<char> a[10] = {
        {},
        {},{'a','b','c'},{'d','e','f'},
        {'g','h','i'}, {'j','k','l'}, {'m','n','o'},
        {'p','q','r','s'}, {'t','u','v'}, {'w','x','y','z'}
    };
    
    vector<string> res;
    
    void solve(string d, int idx, string s){
        if(idx == d.size()){
            res.push_back(s);
            return;
        }
        int button = d[idx] - '0';
        for(int i = 0; i < a[button].size(); i++){
            solve(d, idx+1, s + a[button][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return res;
        solve(digits, 0, "");
        
        return res;
    }
};
