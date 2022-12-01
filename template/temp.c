#include <stdio.h>
#include <string.h>

int main(){
    char y[4] = "1234";
    int x = y[0] -'1' + 1;
    printf("%d\n", x);
    for(int i=0; i<4; ++i) printf("%d ", y[i]);
}
