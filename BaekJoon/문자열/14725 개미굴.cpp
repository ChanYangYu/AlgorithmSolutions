#include <bits/stdc++.h>
#define pii pair<int,int>
#define vs vector<string>

using namespace std;

class Node{
	public:
		string name;
		vector<Node*> childs;
		
		Node(string name){
			this->name = name;
		}
};

bool comp(Node* a, Node* b){
	return a->name < b->name;
}

void print_node(Node* cur, string depth){
	
	if(cur == NULL)
		return;
	
	sort(cur->childs.begin(), cur->childs.end(), comp);
	
	for(int i = 0; i < cur->childs.size(); i++){
		Node* child = cur->childs[i];
		cout<<depth<<child->name<<"\n";
		
		print_node(child, depth+"--");
	}	
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin>>n;
	
	Node* root = new Node("");
	
	while(n--){
		int k;
		
		cin>>k;
		
		Node* cur = root;
		for(int i = 1; i <= k; i++){
			string name;
			bool is_exist = false;
			
			cin>>name;
			
			for(int j = 0; j < cur->childs.size(); j++){
				Node* child = cur->childs[j];
				
				if(child->name == name){
					is_exist = true;
					cur = child;
					break;
				}	
			}
			
			if(is_exist == false){
				Node* new_node = new Node(name);
				cur->childs.push_back(new_node);
				cur = new_node;
			}
		}
	}  
    
    print_node(root, "");
    
    return 0;
}
