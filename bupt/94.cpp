#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        string s;
        cin>>s;
        int n;
        scanf("%d", &n);
        vector<int> last_char(26, -1);
        vector<int> res(100001);
        for(int i = 0; i < s.length(); i++) {
        	int name = s[i] - 'a';
        	int pos = last_char[name];
        	if(pos < 0)
        		res[i] = -1;
        	else {
        		if(res[pos] == -1 || res[pos] > i - pos)
        			res[pos] = i - pos;
        		res[i] = i - pos;
        	}
        	last_char[name] = i;
        }
        int len = s.length();
        while(n--) {
            char cmd[10];
            scanf("%s", cmd);
            if(cmd[0] == 'I') {
            	char c;
            	scanf(" %c", &c);
            	int name = c - 'a';
            	int pos = last_char[name];
            	if(pos < 0)
            		res[len] = -1;
            	else {
            		if(res[pos] == -1 || res[pos] > len - pos)
            			res[pos] = len - pos;
            		res[len] = len - pos;
            	}
            	last_char[name] = len;
            	len += 1;
            }
            else {
            	int m;
            	scanf(" %d", &m);
                printf("%d\n", res[m]);
            }
        }
    }
    return 0;
}