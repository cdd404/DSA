#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char usn[20];
    char name[50];
    char program[30];
    int sem;
    char phno[15];
    struct Student* next;
};

typedef struct Student* NODE;
NODE head = NULL;

NODE createNode() {
    NODE newNode = (NODE)malloc(sizeof(struct Student));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter USN: ");
    scanf("%s", newNode->usn);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Programme: ");
    scanf("%s", newNode->program);
    printf("Enter Semester: ");
    scanf("%d", &newNode->sem);
    printf("Enter Phone Number: ");
    scanf("%s", newNode->phno);
    newNode->next = NULL;
    return newNode;
}

void insertFront() {
    NODE newNode = createNode();
    newNode->next = head;
    head = newNode;
    printf("Student inserted at front.\n");
}

void insertEnd() {
    NODE newNode = createNode();
    if (head == NULL) {
        head = newNode;
    } else {
        NODE temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Student inserted at end.\n");
}

void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    NODE temp = head;
    head = head->next;
    printf("Deleted student with USN: %s\n", temp->usn);
    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted student with USN: %s\n", head->usn);
        free(head);
        head = NULL;
        return;
    }
    NODE temp = head, prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted student with USN: %s\n", temp->usn);
    free(temp);
    prev->next = NULL;
}

void displayAndCount() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int count = 0;
    NODE temp = head;
    printf("\n--- Student List ---\n");
    while (temp != NULL) {
        printf("USN: %s | Name: %s | Program: %s | Sem: %d | Phone: %s\n",
               temp->usn, temp->name, temp->program, temp->sem, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("Total students: %d\n", count);
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Student SLL Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from End\n");
        printf("5. Display and Count Nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertFront();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                displayAndCount();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
