#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//首先考虑存储结构：
//	1. 使用一个数组，数组中存储每个节点的指针
//	2. 定义节点结构：num域记录该节点的序号，parent节点记录父节点的指针，level记录深度
//  3. 定义一个数组，每个数组存储该节点的儿子节点

struct Node {
	Node* parent;
	int level;
	int num;
};

//查找最近祖先，返回其序号
int LCA(Node* u, Node* v) {
	Node* p;
	Node* q;
	if(u->level < v->level) {
		p = u;
		q = v;
	}
	else {
		p = v;
		q = u;
	}
	int deepth = q->level - p->level;
	while(deepth--)
		q = q->parent;
	while(p != q) {
		p = p->parent;
		q = q->parent;
	}
	return p->num + 1;
}

Node* create() {
	Node* root = (Node*)malloc(sizeof(Node));
	root->level = 0;
	root->num = 0;
	root->parent = NULL;
	return root;
}

Node* insert(Node* node, int num) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->level = node->level + 1;
	p->num = num;
	p->parent = node;
	return p;
}

//层序递归创建二叉树
void createTree(vector<vector<int> >& Num, vector<Node*>& Tree, Node* node, int num) {
	for(int i = 0; i < Num[num].size(); i++) {
		Node* p = insert(Tree[num], Num[num][i]);
		Tree[Num[num][i]] = p;
		createTree(Num, Tree, p, Num[num][i]);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector<vector<int> > Num(n);
		vector<Node*> Tree(n);
		Tree[0] = create();
		int k = n - 1;
		while(k--) {
			int u, v;
			scanf("%d%d", &u, &v);
			Num[u - 1].push_back(v - 1);
		};
		createTree(Num, Tree, Tree[0], 0);
		int m;
		scanf("%d", &m);
		while(m--) {
			int p, q;
			scanf("%d%d", &p, &q);
			printf("%d\n", LCA(Tree[p - 1], Tree[q - 1]));
		}
	}
	return 0;
}