#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char ssn[20];
    char name[50];
    char dept[30];
    char designation[30];
    float sal;
    char phno[15];
    struct Employee* prev;
    struct Employee* next;
};

typedef struct Employee* NODE;
NODE start = NULL;

NODE createNode() {
    NODE newNode = (NODE)malloc(sizeof(struct Employee));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter SSN: ");
    scanf("%s", newNode->ssn);
    printf("Enter Name: ");
    scanf("%s", newNode->name);
    printf("Enter Dept: ");
    scanf("%s", newNode->dept);
    printf("Enter Designation: ");
    scanf("%s", newNode->designation);
    printf("Enter Salary: ");
    scanf("%f", &newNode->sal);
    printf("Enter Phone Number: ");
    scanf("%s", newNode->phno);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

NODE insertEnd() {
    NODE newNode = createNode();
    if (start == NULL) {
        start = newNode;
    } else {
        NODE cur = start;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = newNode;
        newNode->prev = cur;
    }
    printf("Employee inserted at the end.\n");
    return start;
}

NODE insertFront() {
    NODE newNode = createNode();
    if (start == NULL) {
        start = newNode;
    } else {
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }
    printf("Employee inserted at the front.\n");
    return start;
}

NODE deleteEnd() {
    if (start == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    if (start->next == NULL) {
        printf("Deleted employee with SSN: %s\n", start->ssn);
        free(start);
        start = NULL;
        return start;
    }
    NODE cur = start;
    while (cur->next != NULL)
        cur = cur->next;
    printf("Deleted employee with SSN: %s\n", cur->ssn);
    cur->prev->next = NULL;
    free(cur);
    return start;
}

NODE deleteFront() {
    if (start == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    NODE temp = start;
    if (start->next == NULL) {
        printf("Deleted employee with SSN: %s\n", start->ssn);
        free(start);
        start = NULL;
        return start;
    }
    start = start->next;
    start->prev = NULL;
    printf("Deleted employee with SSN: %s\n", temp->ssn);
    free(temp);
    return start;
}

void displayAndCount() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    int count = 0;
    NODE cur = start;
    printf("\n--- Employee List ---\n");
    while (cur != NULL) {
        printf("SSN: %s | Name: %s | Dept: %s | Designation: %s | Salary: %.2f | Phone: %s\n",
               cur->ssn, cur->name, cur->dept, cur->designation, cur->sal, cur->phno);
        cur = cur->next;
        count++;
    }
    printf("Total employees: %d\n", count);
}

void doubleEndedQueueDemo() {
    int choice;
    while (1) {
        printf("\n--- Double Ended Queue Operations ---\n");
        printf("1. Insert at Front (Push)\n");
        printf("2. Insert at End (Enqueue)\n");
        printf("3. Delete from Front (Pop)\n");
        printf("4. Delete from End (Dequeue)\n");
        printf("5. Display\n");
        printf("6. Exit Deque Demo\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start = insertFront();
                break;
            case 2:
                start = insertEnd();
                break;
            case 3:
                start = deleteFront();
                break;
            case 4:
                start = deleteEnd();
                break;
            case 5:
                displayAndCount();
                break;
            case 6:
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Employee DLL Menu ---\n");
        printf("1. Create DLL by End Insertion\n");
        printf("2. Display and Count Nodes\n");
        printf("3. Insert at End\n");
        printf("4. Delete from End\n");
        printf("5. Insert at Front\n");
        printf("6. Delete from Front\n");
        printf("7. Double Ended Queue Demo\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                start = insertEnd();
                break;
            case 2:
                displayAndCount();
                break;
            case 3:
                start = insertEnd();
                break;
            case 4:
                start = deleteEnd();
                break;
            case 5:
                start = insertFront();
                break;
            case 6:
                start = deleteFront();
                break;
            case 7:
                doubleEndedQueueDemo();
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
