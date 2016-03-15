#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long convert(long long x) {
	long long digit[64];
	int len = 0;
	while(x > 9) {
		long long tmp = x / 10;
		digit[len++] = x - tmp * 10;
		x = tmp;
	}
	digit[len] = x;
	int sum = 0;
	for(int i = 0; i <= len; i++)
		sum += digit[i] * (1 + pow(10, i));
	return sum;
}

int len(long long x) {
	stringstream x_str;
	x_str<<x;
	string s;
	x_str>>s;
	return s.length();
}

int main() {
	long long n;
	scanf("%lld", &n);
	int key = -1;
	if(n == 1) {
		cout<<-1<<endl;
		return 0;
	}
	long long m = sqrt(n);
	long long start = sqrt(n/2);
	if(start < m - 64 * 9)
		start = m - 64  * 9;
	for(long long x = start; x <= m; x++) {
		if(n % x == 0) {
			long long tmp  = x * convert(x);
			if(tmp == n) {
				key = x;
				break;
			}
		}
	}
	cout<<key<<endl;
	return 0;
}