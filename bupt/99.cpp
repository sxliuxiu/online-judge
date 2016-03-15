#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int hasChar(string s, char x) {
	int count = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == x)
			count += 1;
	}
	return count;
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		char x;
		cin>>x;
		string s;
		cin>>s;
		cout<<hasChar(s, x)<<endl;
	}
	return 0;
}