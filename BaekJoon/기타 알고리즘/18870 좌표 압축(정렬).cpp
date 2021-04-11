#include<bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
    cin.tie(0);
    //freopen("input.txt","rt",stdin);
    int n;
    unordered_map<int, int> hash;
    vector<int> arr, res, backup;
    
    cin>>n;
    
    //좌표 입력 
    for(int i = 0; i < n; i++){
    	int x;
    	
		cin>>x;
    	arr.push_back(x);
    }
    
    //백업 
    backup = arr;
    //오름차순 정렬 
    sort(arr.begin(), arr.end(), greater<int>());
     
    int prev = arr[0];
    res.push_back(arr[0]);
    int num = 1;
    //숫자 중복 제거 
    for(int i = 1; i < arr.size(); i++){
    	if(arr[i] != prev){
    		prev = arr[i];
    		res.push_back(arr[i]);
    		num++;
		}
	}
	
	//hash에 인덱스 매핑 
	for(int i = 0; i < res.size(); i++){
		num--;
		hash[res[i]] = num;
	}
    
    
    //바뀐 인덱스 출력 
    for(int i = 0; i < n; i++)
    	cout<<hash[backup[i]]<<" ";

    return 0;
}
