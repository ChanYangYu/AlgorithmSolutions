#include <bits/stdc++.h>
#define ll long long

// 실행시간 : 960ms
using namespace std;
struct Node{
	int d;
	struct Node* left;
	struct Node* right;
};

vector<int> a;
struct Node* head;

struct Node* make_bst(int left, int right){
	int mid = (left + right) / 2;
	
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->d = a[mid];
	new_node->left = NULL;
	new_node->right = NULL;
	
	if(left == right)
		return new_node;
	else{
		if(mid-1 >= left)
			new_node->left = make_bst(left, mid-1);
		new_node->right = make_bst(mid+1, right);
	}
	return new_node;
}

int search_bst(int x){
	struct Node* res = NULL;
	struct Node* cur = head;
	
	while(cur != NULL){
		if(cur->d > x)
			res = cur;
		if(cur->d <= x)
			cur = cur->right;
		else
			cur = cur->left;	
	}
	return res->d;
}

struct Node* delete_bst(struct Node* root, int x){
	if(root->d > x)
		root->left = delete_bst(root->left, x);
	else if(root->d < x)
		root->right = delete_bst(root->right, x);
	else{
		if(root->left != NULL && root->right != NULL){
			struct Node* min_node = root->right;
			while(min_node->left != NULL)
				min_node = min_node->left;
			root->d = min_node->d;
			root->right = delete_bst(root->right, min_node->d);
		}
		else if(root->left != NULL)
			return root->left;
		else if(root->right != NULL)
			return root->right;
		else
			return NULL;
	}
	
	return root;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, k;
	
	cin>>n>>m>>k;
	
	for(int i = 0; i < m; i++){
		int x;
		
		cin>>x;
		a.push_back(x);
	}
	
	sort(a.begin(), a.end());
	head = make_bst(0, m-1);
	
	while(k--){
		int x;
		
		cin>>x;
		int res = search_bst(x);
		cout<<res<<"\n";
		head = delete_bst(head, res);
	}
	return 0;
}

// 실행시간 : 780ms
/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;
//int ch[4000001];
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	//freopen("input.txt","rt",stdin);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, k;
	
	cin>>n>>m>>k;
	
	vector<int> a(m);
	vector<int> ch(m,0);
	for(int i = 0; i < m; i++)
		cin>>a[i];
	
	sort(a.begin(), a.end());
	
	while(k--){
		int x;
		
		cin>>x;
		
		int idx = upper_bound(a.begin(), a.end(), x) - a.begin();
		while(idx<= n && ch[idx])
			idx++;
		cout<<a[idx]<<"\n";
		ch[idx] = 1;
	}
	return 0;
}
*/
