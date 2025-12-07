#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int top = -1;
int s[MAX];
void push(int item);
int pop();
void palindrome();
void display();
void main(){
    int choice,item;
    while(1){
        printf("\n----MENU----");
        printf("\n=>1. Push An Element in Stack");
        printf("\n=>2. Pop An Element From stack: ");
        printf("\n=>3. Palindrome:");
        printf("\n=>4. Display the stack:");
        printf("\n=>5. EXIT:");
        printf("\n ENTER YOUR CHOICE:");
        scanf("%d",&choice);
        switch (choice){
            case 1:
            if(top==MAX-1){
                printf("\nSTACK FULL");
            }
            printf("\nENTER AN ELEMENT IN STACK:");
            scanf("%d",&item);
            push(item);
            break;

            case 2:
            item=pop();
            if(item!=-1){
                printf("\nElement popped %d",item);
            }
            break;

            case 3:
            palindrome();
            break;

            case 4:
            display();
            break;

            case 5:
            exit(1);
            break;

            default:
            printf("\n Enter The right choice");
            break;

        }
    }
}
void push(int item){
    if(top==MAX-1){
        printf("\nSTACK FULL");
        return;
    }
    top=top+1;
    s[top]=item;
}
int pop(){
    int item;
    if(top==-1){
        printf("\nSTACK EMPTY");
    }
    item=s[top];
    top=top-1;
    return item;
}
void palindrome(){
    int flag=1,i;
    for(i=top;i>=0;i--){
        printf("|%d|\n",s[i]);
    }
    printf("\n");
    printf("\n");
    for(i=0;i<=top;i++){
        printf("|%d|\n",s[i]);
    }
    for(i=0;i<=top/2;i++){
        if(s[i]!=s[top-i]){
            flag=0;
            break;
        }
    }
    if(flag==1){
        printf("\nPALINDROME");
    }
    else{
        printf("\nNOT A PALINDROME");
    }

}
void display(){
    for(int i=top;i>=0;i--){
        printf("|%d|\n",s[i]);
    }
}
