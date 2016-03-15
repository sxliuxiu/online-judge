#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool isLeap(int year) {
	if(year % 4 == 0) {
		if(year % 100 != 0)
			return true;
		else {
			if(year % 400 == 0)
				return true;
			else
				return false;
		}
	}
	else
		return false;
}

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int countDate(int year, int month, int day) {
	if(isLeap(year))
		days[1] = 29;
	else
		days[1] = 28;
	int count = 0;
	for(int i = 0; i < month - 1; i++)
		count += days[i];
	count += day;
	return count;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> res;
	while(n--) {
		int year, month, day;
		scanf("%d:%d:%d", &year, &month, &day);
		res.push_back(countDate(year, month, day));
	}
	for(int i = 0; i < res.size(); i++) {
		cout<<res[i]<<endl;
	}
	return 0;
}