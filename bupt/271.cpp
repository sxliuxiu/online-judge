#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void printMatrix(vector<string>& matrix) {
	for(int i = 0; i < matrix.size(); i++)
		cout<<matrix[i]<<endl;
}

vector<string> rotate(vector<string>& matrix) {
	vector<string> res(matrix[0].length(), "");
	for(int i = 0; i < matrix[0].length(); i++) {
		for(int j = 0; j < matrix.size(); j++)
			res[i].append(1, matrix[matrix.size() - 1 - j][i]);
	}
	return res;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		vector<string> matrix;
		while(n--) {
			string s;
			cin>>s;
			matrix.push_back(s);
		}
		int degree;
		scanf("%d", &degree);
		int k = degree / 90;
		vector<string> res;
		while(k--) {
			res = rotate(matrix);
			matrix = res;
		}
		printMatrix(matrix);
	}
	return 0;
}