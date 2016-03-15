#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

vector<int> count(string s) {
	vector<int> count;
	count.push_back(-1);
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '.')
			count.push_back(i);
	}
	count.push_back(s.length());
	return count;
}

bool isIP(string s, vector<int> count) {
	if(count.size() != 5)
		return false;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] != '.' && s[i] - '0' < 0 || s[i] - '0' > 9) {
			return false;
		}
	}
	for(int i = 0; i < count.size() - 1; i++) {
		if(count[i + 1] == count[i] + 1)
			return false;
		string val;
		stringstream ss;
		val = s.substr(count[i] + 1, count[i + 1] - count[i] - 1);
		ss<<val;
		int x;
		ss>>x;
		if(x < 0 || x > 255) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	scanf("%d\n", &n);
	while(n--) {
		string s;
		getline(cin, s);
		if(isIP(s, count(s)))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}