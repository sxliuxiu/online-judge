#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

string binary(int x) {
	stack<int> digit;
	while(x > 1) {
		digit.push(x % 2);
		x = x / 2;
	}
	string s = "1";
	while(digit.size() > 0) {
		stringstream d;
		d<<digit.top();
		digit.pop();
		string digit_str;
		d>>digit_str;
		s += digit_str;
	}
	return s;
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		int x;
		scanf("%d", &x);
		cout<<binary(x)<<endl;
	}
	return 0;
}