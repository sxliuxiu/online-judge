#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int maxTerm(vector<int>& array) {
	if(array.size() == 1)
		return array[0];
	vector<int> pos;
	int count = 1;
	int tmp = 1;
	int pre = 0;
	for(int i = 1; i < array.size(); i++) {
		if(array[i] == array[i - 1])
			tmp += 1;
		else {
			if(tmp > count) {
				count = tmp;
				pos.clear();
				pos.push_back(pre);
			}
			else if(tmp == count)
				pos.push_back(pre);
			pre = i;
			tmp = 1;
		}
	}
	if(tmp > count) {
		count = tmp;
		pos.clear();
		pos.push_back(pre);
	}
	else if(tmp == count)
		pos.push_back(pre);
	return array[pos[0]];
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
		printf("%d\n", maxTerm(array));
	}
	return 0;
}