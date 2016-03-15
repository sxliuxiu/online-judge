#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int sub(int x) {
	x = abs(x);
	int tmp = 26 - x;
	if(tmp < x)
		return tmp;
	else
		return x;
}

int invert(string& s, int x) {
	int sum = 0;
	for(int i = 0; i < s.length(); i++)
		sum += sub(int(s[i]) - x);
	return sum;
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		string s;
		cin>>s;
		int res = s.length() * 25;
		for(int i = 0; i < 26; i++) {
			int tmp = invert(s, i + 97);
			if(res > tmp)
				res = tmp;
		}
		printf("%d\n", res);
	}
	return 0;
}