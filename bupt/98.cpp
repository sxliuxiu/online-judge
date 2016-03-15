#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <sstream>
using namespace std;

void print_ip(vector<int>& array, int pos, int num) {
	for(int i = 0; i < num; i++) {
		printf("%d", array[pos + i]);
		if(i < num - 1)
			printf(".");
	}
	printf("\n");
}

void print_port(vector<int>& array, int pos, int num) {
	int res = 0;
	for(int i = 0; i < num; i++)
		res += array[pos + i] * pow(256, num - 1 - i);
	printf("%d\n", res);
}

void getMsg(int num, vector<int>& package) {
	printf("Case #%d\n", num);
	int head_len = package[0] % 16;
	int length = package[2] * 256 + package[3];
	printf("Total length = %d bytes\n", length);
	int ip_source = 12, ip_des = 16;
	printf("Source = ");
	print_ip(package, ip_source, 4);
	printf("Destination = ");
	print_ip(package, ip_des, 4);
	int source_port = head_len * 4, des_port = source_port + 2;
	printf("Source Port = ");
	print_port(package, source_port, 2);
	printf("Destination Port = ");
	print_port(package, des_port, 2);
}

int main() {
	int n;
	scanf("%d\n", &n);
	int num = 1;
	while(n--) {
		vector<int> package;
		string line;
		getline(cin, line);
		stringstream ss;
		ss<<line;
		int x;
		while(ss>>hex>>x)
			package.push_back(x);
		getMsg(num, package);
		printf("\n");
		num += 1;
	}
	return 0;
}