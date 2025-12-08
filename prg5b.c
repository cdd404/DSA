#include<stdio.h>
#include<math.h>
void tower(int n, int source,int temp,int dest){
    if(n==0){
        return;
    }
    tower(n-1,source,dest,temp);
    printf("\nMove Disc %d from %c to %c",n,source,dest);
    tower(n-1,temp,source,dest);
}
void main(){
    int n;
    printf("\n Enter The Number Of Discs:");
    scanf("%d",&n);
    tower(n,'A','B','C');
    printf("\n Total Number Of Moves:%d",(int)pow(2,n)-1);
}
