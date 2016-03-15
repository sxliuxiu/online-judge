#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct Node {
	Node* parent;
	Node* child;
	Node* brother;
	bool visit;
	char value;
	int num;
};

Node* create(char c, int n) {
	Node* root = (Node*)malloc(sizeof(Node));
	root->parent = NULL;
	root->child = NULL;
	root->brother = NULL;
	root->visit = false;
	root->value = c;
	root->num = n;
	return root;
}

Node* childInsert(Node* node, char c, int n) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->parent = node;
	p->child = NULL;
	p->brother = NULL;
	p->visit = false;
	p->value = c;
	p->num = n;
	node->child = p;
	return p;
}

Node* brotherInsert(Node* node, char c, int n) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->parent = node->parent;
	p->child = NULL;
	p->brother = NULL;
	p->visit = false;
	p->value = c;
	p->num = n;
	node->brother = p;
	return p;
}

Node* createTree(vector<vector<int> > matrix, int n, string str) {
	stack<Node*> tmp;
	Node* root = create(str[n], n);
	tmp.push(root);
	while(!tmp.empty()) {
		Node* p = tmp.top();
		tmp.pop();
		for(int i = 0; i < matrix[p->num].size(); i++) {
			int num = matrix[p->num][i];
			if(p->parent == NULL || num != p->parent->num) {
				if(p->child == NULL)
					tmp.push(childInsert(p, str[num], num));
				else
					tmp.push(brotherInsert(tmp.top(), str[num], num));
			}
		}
	}
	return root;
}

string mediumVisit(Node* root) {
	string res = "";
	stack<Node*> tmp;
	tmp.push(root);
	while(!tmp.empty()) {
		if(tmp.top()->child != NULL && !tmp.top()->visit)
			tmp.push(tmp.top()->child);
		else {
			Node* p = tmp.top();
			tmp.pop();
			if(!p->visit) {
				res.append(1, p->value);
				p->visit = true;
			}
			if(p->brother != NULL)
				tmp.push(p->brother);
			if(p->parent != NULL && !p->parent->visit) {
				res.append(1, p->parent->value);
				p->parent->visit = true;
			}
		}
	}
	return res;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		string str;
		cin>>str;
		vector<vector<int> > node(n);
		n -= 1;
		while(n--) {
			int x, y;
			scanf("%d%d", &x, &y);
			node[x].push_back(y);
			node[y].push_back(x);
		}
		for(int i = 0; i < node.size(); i++)
			sort(node[i].begin(), node[i].end());
		vector<string> res;
		for(int i = 0; i < str.length(); i++) {
			Node* root = createTree(node, i, str);
			res.push_back(mediumVisit(root));
		}
		string min = res[0];
		for(int i = 0; i < res.size(); i++) {
			if(min > res[i])
				min = res[i];
		}
		cout<<min<<endl;
	}
	return 0;
}