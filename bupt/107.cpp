#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char* posReverse(int n, int len, char* s) {
	for(int i = 0; i < len - 1 - i; i++) {
		char tmp = s[n + i];
		s[n + i] = s[n + len - 1 - i];
		s[n + len - 1 - i] = tmp;
	}
	return s;
}

char* replace(char* s, int n, int len, char* sub) {
	for(int i = 0; i < len; i++)
		s[n + i] = sub[i];
	return s;
}

int main() {
	char s[205];
	while(scanf("%s", s) != EOF) {
		int n;
		scanf("%d", &n);
		while(n--) {
			int type;
			scanf("%d", &type);
			int pos, len;
			scanf("%d%d", &pos, &len);
			if(type == 0)
				printf("%s\n", posReverse(pos, len, s));
			else {
				char sub[len];
				scanf("%s", sub);
				printf("%s\n", replace(s, pos, len, sub));
			}
		}
	}
	return 0;
}