#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
	Node* parent;
	Node* child;
	Node* brother;
	int num;
};

Node* create() {
	Node* root = (Node*)malloc(sizeof(Node));
	root->parent = NULL;
	root->child = NULL;
	root->brother = NULL;
	root->num = 0;
	return root;
};

Node* insert(Node* node, int n) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->child = NULL;
	p->brother = NULL;
	p->num = n;
	Node* q = node->child;
	if(q == NULL) {
		node->child = p;
		p->parent = node;
	}
	else {
		while(q->brother != NULL)
			q = q->brother;
		q->brother = p;
		p->parent = q;
	}
	return p;
};

int Delete(Node* node) {
	Node* p = node->parent;
	if(p->brother == node)
		p->brother = NULL;
	else
		p->child = NULL;
	int num = node->num;
	free(node);
	return num;
}

void recDelete(Node* node, vector<Node*>& tree) {
	if(node != NULL) {
		if(node->child != NULL)
			recDelete(node->child, tree);
		if(node->brother != NULL)
			recDelete(node->brother, tree);
		tree[Delete(node)] = NULL;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector<Node*> tree(101);
		tree[0] = create();
		while(n--) {
			string cmd;
			cin>>cmd;
			if(cmd == "FORK") {
				int father, son;
				scanf("%d%d", &father, &son);
				Node* p = insert(tree[father], son);
				tree[son] = p;
			}
			if(cmd == "KILL") {
				int num;
				scanf("%d", &num);
				if(num > 0 && tree[num] != NULL) {
					recDelete(tree[num]->child, tree);
					tree[Delete(tree[num])] = NULL;
				}
			}
			if(cmd == "QUERY") {
				int num;
				scanf("%d", &num);
				if(num > 0 && tree[num] == NULL)
					printf("No\n");
				else
					printf("Yes\n");
			}
		}
	}
	return 0;
}