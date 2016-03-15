#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void matrixMulti(vector<vector<int> >& matrix, int k) {
	vector<vector<int> > tmp(matrix);
	vector<vector<int> > res(matrix);
	while(k > 1) {
		int n = matrix.size();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				int val = 0;
				for(int p = 0; p < n; p++)
					val += tmp[i][p] * matrix[p][j];
				res[i][j] = val;
			}
		}
		tmp = res;
		k -= 1;
	}
	matrix = tmp;
}

void matrixPrint(vector<vector<int> >& matrix) {
	int n = matrix.size();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout<<matrix[i][j];
			if(j < n - 1)
				cout<<" ";
		}
		cout<<endl;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		vector<vector<int> > matrix(n);
		int i = 0;
		while(n--) {
			int m = matrix.size();
			while(m--) {
				int val;
				scanf("%d", &val);
				matrix[i].push_back(val);
			}
			i += 1;
		}
		matrixMulti(matrix, k);
		matrixPrint(matrix);
	}
	return 0;
}