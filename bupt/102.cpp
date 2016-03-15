#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <string.h>
using namespace std;

#define _USE_MATH_DEFINES

double min(double x, double y) {
	return x < y ? x : y;
}

double edge(double a ,double b, double theta) {
	double rad = theta / 180.0 * M_PI;
	return sqrt(a * a + b * b - 2 * a * b * cos(rad));
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		double forward = 0, backward = 0;
		vector<bool> visit(360, false);
		visit[0] = true;
		double res = 180;
		while(n--) {
			string cmd;
			cin>>cmd;
			int val;
			scanf("%d", &val);
			if(cmd == "forward")
				forward += val;
			else if(cmd == "backward")
				backward += val;
			else {
				int x;
				if(cmd == "right")
					x = 360 - val;
				else
					x = val;
				vector<bool> current(360, false);
				for(int i = 0; i < 360; i++) {
					int tmp = (i + x) % 360;
					if(!current[i] && visit[i] && !visit[tmp]) {
						visit[tmp] = true;
						current[tmp] = true;
						res = min(res, abs(180 - tmp));
					}
				}
			}
		}
        printf("%.3lf\n", edge(forward, backward, 180 - res));  
	}
	return 0;
}