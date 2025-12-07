#include<stdio.h>
#include<stdlib.h>
struct Day{
    char* dayName;
    int date;
    char* activity;
};
void create(struct Day *day){
    day->dayName=(char*)malloc(sizeof(char)*20);
    day->activity=(char*)malloc(sizeof(char)*100);
    printf("Enter Day Name:");
    scanf("%s",day->dayName);
    printf("Enter Date:");
    scanf("%d",&day->date);
    printf("Enter activity:");
    scanf(" %99[^\n]",day->activity);
}

void read(struct Day *calendar,int size){
    for(int i=0;i<size;i++){
        printf("Enter details:%d\n",i+1);
        create(&calendar[i]);
    }
    }

void display(struct Day *calendar,int size){
    printf("\nWeekly planner\n");
    for(int i=0;i<size;i++){
        printf("Day:%d\n",i+1);
        printf("Day Name:%s\n",calendar[i].dayName);
        printf("Date:%i\n",calendar[i].date);
        printf("activity:%s\n",calendar[i].activity);
        printf("\n");
    }
}
void freeMemory(struct Day *calendar,int size){
    for(int i=0;i<size;i++){
        free(calendar[i].dayName);
         free(calendar[i].activity);
    } 
}
int main(){
    int size;
    printf("Enter Number Of Days:");
    scanf("%d",&size);
    struct Day *calendar = malloc(sizeof(struct Day) * size);
    read(calendar,size);
    display(calendar,size);
    freeMemory(calendar,size);
    free(calendar);
    return 0;
}
