#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

int preorder[101];
int inorder[101];
int in_idx[1001];

//inorder는 루트노드를 기점으로 나눠주는 역할
//preorder는 루트노드를 찾는 역할 
void print_postorder(int pre_s, int pre_e, int in_s, int in_e){
	if(pre_s > pre_e)
		return;
	 
	int root_idx = in_idx[preorder[pre_s]];
	int num = root_idx - in_s;
	
	print_postorder(pre_s + 1, pre_s + num, in_s, root_idx-1);
	print_postorder(pre_s + num + 1, pre_e, root_idx+1, in_e);
	
	cout<<inorder[root_idx]<<" ";
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	int test;
	
	cin>>test;
	
	while(test--){
		int n;
		
		cin>>n;
		for(int i = 0; i < n; i++)
			cin>>preorder[i];
		for(int i = 0; i < n; i++){
			cin>>inorder[i];
			in_idx[inorder[i]] = i;
		}
		print_postorder(0, n-1, 0, n-1);
		cout<<"\n";
	}
	
	return 0;
}
