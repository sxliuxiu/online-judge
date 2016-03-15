#include <stdio.h>
using namespace std;

int main()  
{  
    long long x, n, app_1, app_2, not_three;  
    while(scanf("%lld",&n)!=EOF){  
        app_1=0, app_2=0;  
        while(n--){  
            scanf("%lld",&x);  
            app_2 |= app_1&x;  
            app_1 ^= x;  
            not_three = ~(app_1&app_2);  
            app_1 = not_three&app_1;  
            app_2 = not_three&app_2;  
        }  
        printf("%lld\n",app_1);  
    }  
    return 0;  
}  
