#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdio.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		map<int, int> info;
		while(n--) {
			string cmd;
			cin>>cmd;
			if(cmd == "Insert") {
				int id, score;
				scanf(" %d%d", &id, &score);
				info[id] = score;
			}
			else {
				int id;
				scanf(" %d", &id);
				if(info.find(id) != info.end())
					printf("name:%d score:%d\n", id, info[id]);
				else
					printf("No result!\n");
			}
		}
	}
	return 0;
}