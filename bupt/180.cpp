#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;

int max(int x, int y) {
	return x > y ? x : y;
}

int lowest(vector<int>& score) {
	vector<int> value(score.size());
	value[0] = 1;
	for(int i = 1; i < score.size(); i++) {
		if(score[i] > score[i - 1]) 
			value[i] = value[i - 1] + 1;
		else
			value[i] = 1;
	}
	for(int i = score.size() - 2; i >= 0; i--) {
		if(score[i] > score[i + 1]) {
			if(i > 0)
				value[i] = max(value[i], value[i + 1] + 1);
			else
				value[i] = value[i + 1] + 1;
		}
	}
	int sum = 0;
	for(int i = 0; i < value.size(); i++) {
		//cout<<value[i]<<" ";
		sum += value[i];
	}
	//cout<<endl;
	return sum;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		vector<int> score;
		while(n--) {
			int val;
			scanf("%d", &val);
			score.push_back(val);
		}
		printf("%d\n", lowest(score));
	}
	return 0;
}