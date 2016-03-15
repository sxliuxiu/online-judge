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
		vector<int> degree(n);
		vector<vector<int> > fatherSon(n);
		while(n-- > 1) {
			int father, son;
			scanf("%d%d", &father, &son);
			degree[father] += 1;
			degree[son] += 1;
			fatherSon[father].push_back(son);
			fatherSon[son].push_back(father);
		}
		int count = 0;
		for(int i = 0; i < degree.size(); i++) {
			bool is_p = true;
			for(int j = 0; j < fatherSon[i].size(); j++) {
				if(degree[i] < degree[fatherSon[i][j]]) {
					is_p = false;
					break;
				}
			}
			if(is_p)
				count += 1;
		}
		printf("%d\n", count);
	}
	return 0;
}