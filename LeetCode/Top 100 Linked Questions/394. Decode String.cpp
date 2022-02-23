class Solution {
public:
    int idx;

    string decodeString(string s) {
        string sub; 
        while(idx < s.size()){
            if(s[idx] >= '0' && s[idx] <= '9'){
                string num;
                
                while(s[idx] >= '0' && s[idx] <= '9')
                    num += s[idx++];
                
                int num_int = stoi(num);
                
                // [ ¹«½Ã
                idx++;
                string res = decodeString(s);
                
                for(int i = 0; i < num_int; i++)
                    sub += res;
            }
            else if(s[idx] == ']')
                return sub;
            else
                sub += s[idx];
            idx++;
        }
        
        return sub;
    }
};
