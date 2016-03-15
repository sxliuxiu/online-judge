#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct Node {
	int val;
	Node* parent;
	Node* left;
	Node* right;
} *BStree;

int insert(BStree& T, int x, Node* parent = NULL) {
	if(T == NULL) {
		T = (BStree)malloc(sizeof(Node));
		T->val = x;
		T->left = NULL;
		T->right = NULL;
		T->parent = parent;
		if(x < parent->val)
			parent->left = T;
		else
			parent->right = T;
		if(parent != NULL)
			return parent->val;
		else
			return -1;
	}
	else if(x < T->val)
		return insert(T->left, x, T);
	else
		return insert(T->right, x, T);
}

int main() {
	int n;
	scanf("%d", &n);
	BStree T = (BStree)malloc(sizeof(Node));
	int x;
	scanf("%d", &x);
	T->val = x;
	T->left = NULL;
	T->right = NULL;
	T->parent = NULL;
	cout<<-1<<endl;
	n -= 1;
	while(n--) {
		scanf("%d", &x);
		cout<<insert(T, x, T->parent)<<endl;
	}
	return 0;
}