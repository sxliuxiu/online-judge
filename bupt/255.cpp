#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		int odd = 0, even = 0;
		while(n--) {
			int val;
			scanf("%d", &val);
			if(val % 2 == 0)
				even += val;
			else
				odd += val;
		}
		printf("%d %d\n", odd, even);
	}
	return 0;
}