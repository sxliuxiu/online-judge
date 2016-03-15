#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int power(int x, int y) {
	return x * x + y * y;
}

typedef struct Node {
	int x;
	int y;
	Node* next;
} *List;

List create() {
	Node* list = (List)malloc(sizeof(Node));
	list->x = 0;
	list->y = 0;
	list->next = NULL;
	return list;
}

Node* insert(Node* p, int val_x, int val_y) {
	Node* q = (List)malloc(sizeof(Node));
	q->x = val_x;
	q->y = val_y;
	q->next = p->next;
	p->next = q;
	return q;
}

void pop(List list) {
	Node* p = list->next;
	printf("%d+i%d\n", p->x, p->y);
	list->next = p->next;
	free(p);
}

void listInsert(List list, int val_x, int val_y) {
	int val = power(val_x, val_y);
	Node* p = list;
	Node* q = p->next;
	while(q != NULL && power(q->x, q->y) > val) {
		p = q;
		q = p->next;
	}
	insert(p, val_x, val_y);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		List list = create();
		int count = 0;
		while(n--) {
			string cmd;
			cin>>cmd;
			if(cmd == "Pop") {
				if(count == 0)
					printf("Empty!\n");
				else {
					pop(list);
					count -= 1;
					if(count == 0)
						printf("Empty!\n");
					else
						printf("Size: %d\n", count);
				}
			}
			else {
				int x, y;
				scanf("%d+i%d", &x, &y);
				listInsert(list, x, y);
				count += 1;
				printf("Size: %d\n", count);
			}
		}
	}
	return 0;
}
