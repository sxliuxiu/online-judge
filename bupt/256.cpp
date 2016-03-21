#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int maxSub(vector<int>& array) {
	if(array.size() <= 2)
		return array.size();
	int pre = 2;
	int tmp = 2;
	int increment = array[1] - array[0];
	for(int i = 2; i < array.size(); i++) {
		if(array[i] - array[i - 1] == increment)
			tmp += 1;
		else {
			if(tmp > pre)
				pre = tmp;
			increment = array[i] - array[i - 1];
			tmp = 2;
		}
	}
	if(tmp > pre)
		pre = tmp;
	return pre;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector<int> array;
		while(n--) {
			int val;
			scanf("%d", &val);
			array.push_back(val);
		}
		printf("%d\n", maxSub(array));
	}
	return 0;
}