#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int realTime(int x, int y) {
	return x * 60 + y;
}

int delta(int time1, int time2) {
	int res = time2 - time1;
	if(res < 0)
		return res + 24 * 60;
	else
		return res;
}

int main() {
	int n;	scanf("%d", &n);
	while(n--) {
		int x, y;
		int time1, time2;
		scanf("%d:%d", &x, &y);
		time1 = realTime(x, y);
		scanf("%d:%d", &x, &y);
		time2 = realTime(x, y);
		printf("%d\n", delta(time1, time2));
	}
	return 0;
}