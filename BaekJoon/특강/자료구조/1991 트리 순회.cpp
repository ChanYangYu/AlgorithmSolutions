#include <bits/stdc++.h>
#define ll long long
using namespace std;
int parent[128];
char left_child[128];
char right_child[128];
vector<char> nodes;

void pre_order(char node){
	cout<<node;
	if(left_child[node] != 0)
		pre_order(left_child[node]);
	if(right_child[node] != 0)
		pre_order(right_child[node]);
}
void in_order(char node){
	if(left_child[node] != 0)
		in_order(left_child[node]);
	cout<<node;
	if(right_child[node] != 0)
		in_order(right_child[node]);
}
void post_order(char node){
	if(left_child[node] != 0)
		post_order(left_child[node]);
	if(right_child[node] != 0)
		post_order(right_child[node]);
	cout<<node;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    
    cin>>n;
    while(n--){
    	char p, l, r;
    	
    	cin>>p>>l>>r;
    	
    	nodes.push_back(p);
    	if(l != '.'){
			left_child[p] = l;
			parent[l] = p;
		}
		if(r != '.'){
			right_child[p] = r;
			parent[r] = p;
		}
	}
    
    char root;
    for(int i = 0; i < nodes.size(); i++){
    	char node = nodes[i];
    	
    	if(parent[node] == 0){
    		root = node;
    		break;
		}
	}
	
	pre_order(root);
	cout<<"\n";
	in_order(root);
	cout<<"\n";
	post_order(root);
	
}
