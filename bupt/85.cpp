#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool isLine(double x0, double y0, double x1, double y1, double x2, double y2) {
	return fabs(x0 * y1 - x1 * y0 + x1 * y2 - x2 * y1 + x2 * y0 - x0 * y2) <= 1e-6;
}

bool locate(vector<double>& x, vector<double>& y, double val_x, double val_y) {
	if(x.size() < 2)
		return false;
	int n = x.size();
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++) {
			if(isLine(x[i], y[i], x[j], y[j], val_x, val_y))
				return true;
		}
	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	vector<string> res;
	while(t--) {
		int n;
		scanf("%d", &n);
		vector<double> x, y;
		double val_x, val_y;
		bool is_line = false;
		while(n--) {
			scanf("%lf%lf", &val_x, &val_y);
			if(locate(x, y, val_x, val_y)) {
				is_line = true;
				//break;
			}
			x.push_back(val_x);
			y.push_back(val_y);
		}
		if(is_line)
			res.push_back("Yes");
		else
			res.push_back("No");
	}
	for(int i = 0; i < res.size(); i++)
		cout<<res[i]<<endl;
	return 0;
}
