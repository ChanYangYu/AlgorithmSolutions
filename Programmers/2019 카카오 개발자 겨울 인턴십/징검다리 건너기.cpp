#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 1;
    int right = 200000000;
    while(left <= right){
        int mid = (left + right) / 2;
        
        int cur = 0;
        bool check = true;
        while(cur < stones.size()){
            int jmp = 0;
            //이전 stone개수 만큼 제거 후 비교
            while(cur < stones.size() && stones[cur] - (mid-1) <= 0){
                cur++;
                jmp++;
            }
            //jump횟수를 초과한 경우
            if(jmp >= k){
                check = false;
                break;
            }
            cur++;
        }
        
        //가능한 경우
        if(check){
            //answer 갱신
            answer = max(answer, mid);
            left = mid+1;
        }
        else
            right = mid-1;
    }
    return answer;
}
