#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int twoLargest(int x, int y, int& max1, int& max2) {
	if(x > max1) {  // x > y
		if(x > max2)
			max2 = x;
		else
			max1 = x;
	}
	if(y > max1) {
		if(x > max2)
			max2 = y;
		else
			max1 = y;
	}
	return 0;
}

int listLargest(vector<int> array, int& max1, int& max2) {
	for(int i = 0; i < array.size() - 1; i++) {
		int x = array[i], y = array[i + 1];
		int tmp = x;
		if(x < y) {
			x = y;
			y = tmp;
		}
		twoLargest(x, y, max1, max2);
	}
	return 0;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector<int> array;
		int max1, max2;
		while(n--) {
			int val;
			scanf("%d", &val);
			array.push_back(val);
			max1 = array[0];
			max2 = array[0];
			listLargest(array, max1, max2);
		}
		cout<<max2<<" "<<max1<<endl;
	}
	return 0;
}