#include <bits/stdc++.h>

using namespace std;

int cache[100001];

int fibo(int n){
    int& ret = cache[n];
    
    if(n == 1 || n == 2)
        return 1;
    if(ret != -1)
        return ret;
    return ret = (fibo(n-2) + fibo(n-1)) % 1234567;
}

int solution(int n) {
    int answer = 0;
    
    memset(cache, -1, sizeof(cache));
    
    return fibo(n);
}
