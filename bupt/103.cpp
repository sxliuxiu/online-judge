#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

stack<string> cutStr(string s) {
	stack<string> res;
	int down = 0;
	int up = 1;
	while(up <= s.length()) {
		if(s[up] == ' ' || up == s.length()) {
			res.push(s.substr(down, up - down));
			down = up + 1;
			up = down + 1;
		}
		else
			up += 1;
	}
	return res;
}

int main() {
	string s_line;
	while(getline(cin, s_line)) {
		stack<string> res = cutStr(s_line);
		while(res.size() > 0) {
			cout<<res.top();
			res.pop();
			if(res.size() > 0)
				cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}