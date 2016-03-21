#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//使用两个数组来记录信息：第一个数组存储内存块的内存大小，第二个数组存储内存块是否分配

int distribution(vector<int>& memory, vector<bool>& has_put, int cur) {
	for(int i = 0; i < memory.size(); i++) {
		if(memory[i] >= cur && !has_put[i]) {
			has_put[i] = true;
			return memory[i];
		}
	}
	return -1;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector<int> memory;
		vector<bool> has_put(n, false);
		while(n--) {
			int val;
			scanf("%d", &val);
			memory.push_back(val);
		}
		sort(memory.begin(), memory.end());
		int m;
		scanf("%d", &m);
		while(m--) {
			int cur;
			scanf("%d", &cur);
			int dis = distribution(memory, has_put, cur);
			if(dis > 0)
				printf("%d", dis);
			else
				printf("NULL");
			if(m > 0)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}