#include <stdio.h>

int r(int n){
    int res=0;
    while(1){
        if(n/10==0){
            res+=n%10;
            break;
        }
        res+=(n%10);
        n/=10;
    }
    if(res>9)
        return r(res);
    else
        return res;
}
int main() {
    char n[1001] = {'1'};
    while(n[0] != '0') {
        scanf("%s",&n);
        if(n[0] == '0') break;
        int n2 = 0;
        for(int i = 0; n[i]; i++) n2 += (n[i] - '0');
        printf("%d\n", r(n2));
    }
    return 0;
}