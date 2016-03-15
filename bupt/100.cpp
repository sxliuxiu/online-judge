#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	int count = 1;
	while(t--) {
		int n, m;
		cin>>n>>m;
		vector<vector<int> > son(m);
		while(n--) {
			int x, y;
			cin>>x>>y;
			son[y - 1].push_back(x - 1);
		}
		vector<int> current;
		current.push_back(0);
		printf("%c%d:\n",'Q',count);
		count += 1;
		while(current.size() > 0) {
			vector<int> next;
			for(int i = 0; i < current.size(); i++) {
				cout<<current[i] + 1;
				if(i < current.size() - 1)
					cout<<" ";
			}
			cout<<endl;
			for(int i = 0; i < current.size(); i++) {
				vector<int> tmp = son[current[i]];
				for(int j = 0; j <tmp.size(); j++)
					next.push_back(tmp[j]);
			}
			current = next;
		}
	}
	return 0;
}