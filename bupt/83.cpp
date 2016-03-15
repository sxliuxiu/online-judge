#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;
    int val;
	int res = 0;
    while(cin>>val) {
        nums.push_back(val);
		res += val;
	}
	cout<<res<<endl;
	return 0;
}
