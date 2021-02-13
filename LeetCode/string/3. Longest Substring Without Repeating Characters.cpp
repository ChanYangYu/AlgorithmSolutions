#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        
        unordered_map<char, int> hash;
        
        int mx = 0;
        int start = 0;
        int count = 0;
        
        for(int i = 0; i < s.size(); i++){
            count++;
            if(start < hash[s[i]]){
                start = hash[s[i]];
                hash[s[i]] = count;
            }
            else
                hash[s[i]] = count;
            
            if(mx < count - start)
                mx = count - start;
        }
        return mx;
    }
};
