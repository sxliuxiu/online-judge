#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

float median(vector<int>& array) {
	int pos = array.size() / 2;
	if(array.size() % 2 == 0) {
		int pre = pos - 1;
		return (array[pos] + array[pos - 1]) / 2.0;
	}
	else
		return array[pos];
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
		printf("%g\n", median(array));
	}
	return 0;
}