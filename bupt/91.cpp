#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Node {
	int flag;
	Node* child;
	Node* brother;
	char name[21];
};

Node* create() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->flag = 0;
	head->child = NULL;
	head->brother = NULL;
	strcpy(head->name, "root");
	return head;
}

Node* insert(Node* dir_point, char* v_name, int v_flag) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->flag = v_flag;
	p->child = NULL;
	p->brother = NULL;
	strcpy(p->name, v_name);
	Node* q = dir_point->child;
	if(q == NULL)
		dir_point->child = p;
	else {
		while(q->brother != NULL)
			q = q->brother;
		q->brother = p;
	}
	return p;
}

void listChild(Node* dir_point, int flag) {
	Node* p = dir_point->child;
	if(p == NULL)
		return;
	else {
		while(p != NULL) {
			if(p->flag == flag)
				printf("%s\n", p->name);
			p = p->brother;
		}
	}
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		map<string, Node*> point;
		Node* root = create();
		point["root"] = root;
		while(n--) {
			string cmd;
			cin>>cmd;
			if(cmd == "CREATEFILE" || cmd == "CREATEDIR") {
				char name[21], dir_point[21];
				scanf("%s%s", name, dir_point);
				int flag;
				if(cmd == "CREATEDIR")
					flag = 0;
				else
					flag = 1;
				point[name] = insert(point[dir_point], name, flag);
			}
			else {
				int flag;
				if(cmd == "LISTFILE")
					flag = 1;
				else
					flag = 0;
				char dir_point[21];
				scanf("%s", dir_point);
				listChild(point[dir_point], flag);
			}
		}
	}
	return 0;
}