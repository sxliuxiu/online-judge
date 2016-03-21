#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int isAppend(string s) {
	if(s.length() < 11)
		return -1;
	for(int i = 0; i <= s.length() - 10; i++) {
		if(s.substr(i, 7) == ".append")
			return i;
	}
	return -1;
}

int isClear(string s) {
	if(s.length() < 4)
		return -1;
	if(s.substr(s.length() - 3, 3) == "=[]")
		return s.length() - 3;
	return -1;
}

int isGet(string s) {
	if(s.length() < 4)
		return -1;
	for(int i = 1; i <= s.length() - 3; i++)
		if(s[i] == '[' && s[i + 1] != ']')
			return i;
	return -1;
}

int isSort(string s) {
	if(s.length() < 8)
		return -1;
	if(s.substr(s.length() - 7, 7) == ".sort()")
		return s.length() - 7;
	return -1;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector<vector<int> > list(n);
		map<string, int> name;
		while(n--) {
			string s;
			cin>>s;
			map<string, int>::iterator iter;
			if(isClear(s) > 0) {
				string t_name = s.substr(0, isClear(s));
				iter = name.find(t_name);
				if(iter == name.end())
					name[t_name] = name.size();
				else {
					int pos = iter->second;
					list[pos].clear();
				}
			}
			if(isSort(s) > 0) {
				string t_name = s.substr(0, isSort(s));
				int pos = name[t_name];
				if(list[pos].size() > 0)
					sort(list[pos].begin(), list[pos].end());
			}
			if(isGet(s) > 0) {
				string t_name = s.substr(0, isGet(s));
				int pos = name[t_name];
				stringstream tmp;
				tmp<<s.substr(isGet(s) + 1, s.length() - isGet(s) - 2);
				int num;
				tmp>>num;
				if(num < list[pos].size())
					printf("%d\n", list[pos][num]);
				else
					printf("ERROR\n");
			}
			if(isAppend(s) > 0) {
				string t_name = s.substr(0, isAppend(s));
				int pos = name[t_name];
				stringstream tmp;
				tmp<<s.substr(isAppend(s) + 8, s.length() - isAppend(s) - 9);
				int num;
				tmp>>num;
				list[pos].push_back(num);
			}
		}
	}
	return 0;
}