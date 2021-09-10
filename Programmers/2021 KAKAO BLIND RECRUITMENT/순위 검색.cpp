#include <bits/stdc++.h>

using namespace std;
unordered_map<string, int> mp;

vector<int> lst[4000];
void add_info(int idx, int i, vector<int>& arr){
    if(i == 4){
        lst[idx].push_back(arr[4]);
        return;
    }
    add_info(idx*10 + arr[i], i+1, arr);
    add_info(idx*10, i+1, arr);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    mp["java"] = 1;
    mp["cpp"] = 2;
    mp["python"] = 3;
    mp["backend"] = 1;
    mp["frontend"] = 2;
    mp["junior"] = 1;
    mp["senior"] = 2;
    mp["chicken"] = 1;
    mp["pizza"] = 2;
    mp["-"] = 0;
    
    for(int i = 0; i < info.size(); i++){
        vector<int> arr;
        int j = 0;
        while(j < info[i].size()){
            string w = "";
            while(info[i][j] != ' ' && j < info[i].size()){
                w += info[i][j];
                j++;
            }
            if(w[0] >= '0' && w[0] <= '9')
                arr.push_back(stoi(w));
            else
                arr.push_back(mp[w]);
            j++;
        }
        add_info(0, 0, arr);
    }
    for(int i = 0; i < 4000; i++)
        sort(lst[i].begin(), lst[i].end());

    for(int i = 0; i < query.size(); i++){
        vector<int> arr;
        int j = 0;
        while(j < query[i].size()){
            string w = "";
            while(query[i][j] != ' ' && j < query[i].size()){
                w += query[i][j];
                j++;
            }
            if(w[0] >= '0' && w[0] <= '9')
                arr.push_back(stoi(w));
            else
                arr.push_back(mp[w]);
            if(arr.size() < 4)
                j+=5;
            else
                j+=1;
        }
        int idx = arr[0]*1000 + arr[1]*100 + arr[2]*10 + arr[3];
        int num = lst[idx].end() - 
                  lower_bound(lst[idx].begin(), lst[idx].end(), arr[4]);
        answer.push_back(num);
    }
    
    return answer;
}
