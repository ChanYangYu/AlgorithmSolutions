#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int num;
	struct node* left;
	struct node* right;
};

struct node* input_node(struct node* root, int num){
	
	if(root == NULL){
		struct node* new_node = (struct node*)malloc(sizeof(struct node));
		new_node->num = num;
		new_node->left = NULL;
		new_node->right = NULL;
		
		return new_node;		
	}
	
	if(root->num > num)
		root->left = input_node(root->left, num);
	else
		root->right = input_node(root->right, num);
		
	return root;
}

void print_post_order(struct node* root){
	if(root->left == NULL && root->right == NULL){
		cout<<root->num<<"\n";
		return; 
	}
	
	if(root->left != NULL)
		print_post_order(root->left);
	if(root->right != NULL)
		print_post_order(root->right);
	cout<<root->num<<"\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    struct node* root = NULL;
    int i = 0;
    while(true){
       	int num;
       	
       	cin>>num;
    	if(cin.eof() == true)
    		break;
    	root = input_node(root, num);
	}
	
	print_post_order(root);
    
}
