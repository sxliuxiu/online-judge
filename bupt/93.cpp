#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector<int> array;
		bool sorted = true;
		while(n--) {
			int val;
			scanf("%d", &val);
			if(array.size() == 0 || val > array[array.size() - 1])
				array.push_back(val);
			else {
				sorted = false;
				//break;
			}
		}
		if(sorted)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}