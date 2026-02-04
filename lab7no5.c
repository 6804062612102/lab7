#include <stdio.h>

long convert(int, int ,int);

int main(){

    int h,m,s;
    scanf("%d %d %d",&h,&m,&s);
    printf("%d",convert(h,m,s));

    return 0;
}

long convert(int h, int m ,int s){
    return h*3600 + m*60 + s;
}