#include <stdio.h>

void printHead(int width);
void printBody(int width,int height);

int main(){

    int width,height;
	scanf("%d %d",&width,&height);
	printHead(width);
	printBody(width,height);
	printHead(width);

    return 0;
}

void printHead(int width){
    for(int i=0;i<width;i++){
        printf("*");
        if(i==width-1){
            printf("\n");
        }
    }
}
void printBody(int width,int height){
    for(int i=0;i<height-2;i++){
        printf("*");
        for(int j=0;j<width-2;j++){
            printf(" ");
        }
        printf("*\n");
    }
}