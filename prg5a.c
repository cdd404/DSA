#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int top=-1,i;
int op2,op1,res,s[30];
char postfix[90],symb;
void push(int item){
    top = top+1;
    s[top]=item;
}
int pop(){
    int item;
    item=s[top];
    top = top-1;
    return item;
}
void main(){
    printf("\n ENTER A VALID SUFIX:");
    scanf("%s",postfix);
    for(i=0;postfix[i]!='\0';i++){
        symb=postfix[i];
        if(isdigit(symb)){
            push(symb-'0');
        }
        else{
            op2=pop();
            op1=pop();
            switch (symb){
                case '+':
                push(op2+op1);
                break;

                case '-':
                push(op2-op1);
                break;

                case '*':
                push(op2*op1);
                break;

                case '/':
                push(op2/op1);
                break;

                case '%':
                push(op2%op1);
                break;

                case '^':
                push(pow(op2,op1));
                break;

                default:
                printf("\nerror");
            }
        }
    }
    res=pop();
    printf("\n Result:%d",res);

}
