#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

int main() {
	int n, m, l;
	scanf("%d%d%d", &n, &m, &l);
	vector<vector<int> > son(n);
	int father[n];
	father[0] = -1;
	while(m--) {
		int p_father, p_son;
		scanf("%d%d", &p_father, &p_son);
		son[p_father].push_back(p_son);
		father[p_son] = p_father;
	}
	int res = 1;
	while(l > 0) {
		res *= son[father[l]].size();
		l = father[l];
	}
	printf("%f\n", 1.0 / res);
	return 0;
}
