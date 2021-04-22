#include<bits/stdc++.h>
using namespace std;

int in_order[100001];
int post_order[100001];
int in_index[100001];
//Data Ŭ���� ����
class Data{
	public:
		int depth;
		int start;
		int end;
		int idx;
		
		Data(int depth, int start, int end, int idx){
			this->depth = depth;
			this->start = start;
			this->end = end;
			this->idx = idx;
		}
		
		bool operator<(const Data &c) const{
			return this->depth < c.depth;
		}
};


//DFS �Լ� 
void pre_order(int in_start, int in_end, int post_idx){
	int parent = post_order[post_idx];
	
	cout<<parent<<" ";
	
	int cur = in_end;
	int num = 1; 
	while(in_order[cur] != parent){
		cur--;
		num++;
	}
	
	if(cur > in_start)
		pre_order(in_start, cur-1, post_idx - num);
	if(cur < in_end)
		pre_order(cur+1, in_end, post_idx - 1);
}

int main(int argc, char** argv)
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "rt", stdin);
    priority_queue<Data> q;
    int n;
    
    cin>>n;
    
    for(int i = 0; i < n; i++){
    	cin>>in_order[i];
    	//in_order index ��ġ ���� 
    	in_index[in_order[i]] = i;
    }
    
    for(int i = 0; i < n; i++)
    	cin>>post_order[i];
    
    //BFS
    q.push(Data(0 ,0, n-1, n-1));
    while(!q.empty()){
    	int depth = q.top().depth;
    	int in_start = q.top().start;
    	int in_end = q.top().end;
    	int post_idx = q.top().idx;
    	
    	q.pop();
		
		int parent = post_order[post_idx];
		
		cout<<parent<<" ";
		
		int cur = in_index[parent];
		//num : right�� ũ��
		int num = 1 + (in_end - in_index[parent]);
		
		//parent�� left ��� 
		if(cur > in_start)
			q.push(Data(depth+1, in_start, cur-1, post_idx - num));
		//parent�� right ��� 
		if(cur < in_end)
			q.push(Data(depth, cur+1, in_end, post_idx - 1));
		
	}
	
	//DFS
	//cout<<"\n";
    //pre_order(0, n-1, n-1);
    return 0;
}
