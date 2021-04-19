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
            //���� stone���� ��ŭ ���� �� ��
            while(cur < stones.size() && stones[cur] - (mid-1) <= 0){
                cur++;
                jmp++;
            }
            //jumpȽ���� �ʰ��� ���
            if(jmp >= k){
                check = false;
                break;
            }
            cur++;
        }
        
        //������ ���
        if(check){
            //answer ����
            answer = max(answer, mid);
            left = mid+1;
        }
        else
            right = mid-1;
    }
    return answer;
}
