#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
	Node* left;
	Node* right;
	int val;
};

Node* create(int n) {
	Node* root = (Node*)malloc(sizeof(Node));
	root->left = NULL;
	root->right = NULL;
	root->val = n;
	return root;
}

Node* insert(Node* node, int n) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->left = NULL;
	p->right = NULL;
	p->val = n;
	if(node->left == NULL)
		node->left = p;
	else
		node->right = p;
	return p;
}

void medium(Node* root) {
	if(root->left != NULL)
		medium(root->left);
	cout<<root->val<<endl;
	if(root->right != NULL)
		medium(root->right);
}

void createTree(vector<vector<int> >& child, vector<int>& value, Node* root, int n) {
	for(int i = 0; i < child[n].size(); i++) {
		int num = child[n][i];
		Node* p = insert(root, value[num]);
		createTree(child, value, p, num);
	}
}

void isMin(Node* root, bool& tmp) {
	if(root != NULL) {
		if(root->left != NULL && root->val > root->left->val) {
			tmp = false;
			return;
		}
		if(root->right != NULL && root->val > root->right->val) {
			tmp = false;
			return;
		}
		isMin(root->left, tmp);
		isMin(root->right, tmp);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector<int> value;
		vector<vector<int> > child(n);
		int m = n - 1;
		while(n--) {
			int val;
			scanf("%d", &val);
			value.push_back(val);
		}
		Node* root = create(value[0]);
		while(m--) {
			int father, son;
			scanf("%d%d", &father, &son);
			child[father - 1].push_back(son - 1);
		}
		createTree(child, value, root, 0);
		bool tmp = true;
		isMin(root, tmp);
		if(tmp)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}