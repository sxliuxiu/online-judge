#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

void recDelete(vector<vector<bool> >& son, vector<int>& count, vector<int>& father, int node) {
	if(father[node] != -1) {
		for(int i = 0; i < son[node].size(); i++) {
			if(son[node][i])
				recDelete(son, count, father, i);
		}
		int pos = father[node];
		son[pos][node] = false;
		count[pos] -= 1;
		father[node] = -1;
	}
}

void create(vector<vector<bool> >& son, vector<int>& count, vector<int>& father, int f_node, int s_node) {
	son[f_node][s_node] = true;
	father[s_node] = f_node;
	count[f_node] += 1;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector<vector<bool> > son(101);
		for(int i = 0; i < son.size(); i++) {
			int p = son.size();
			while(p--)
				son[i].push_back(false);
		}
		vector<int> father(101, -1);
		vector<int> count(101, 0);
		father[0] = 0;
		while(n--) {
			string cmd;
			cin>>cmd;
			if(cmd == "FORK") {
				int f_node, s_node;
				scanf("%d%d", &f_node, &s_node);
				create(son, count, father, f_node, s_node);
			}
			if(cmd == "KILL") {
				int node;
				scanf("%d", &node);
				recDelete(son, count, father, node);
			}
			if(cmd == "QUERY") {
				int node;
				scanf("%d", &node);
				if(father[node] == -1)
					printf("No\n");
				else
					printf("Yes\n");
			}
		}
	}
	return 0;
}