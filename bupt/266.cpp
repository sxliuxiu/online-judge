#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void addFun(int a, int b) {
	if(a > b)
		swap(a, b);
	if(a == b)
		printf("%d/%d\n", 1, int(pow(2, a - 1)));
	else
		printf("%d/%d\n", int(pow(2, b - a) + 1), int(pow(2, b)));
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		addFun(a, b);
	}
	return 0;
}