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
NODE head = NULL;

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

void insertEnd() {
    NODE newNode = createNode();
    if (head == NULL) {
        head = newNode;
    } else {
        NODE temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Employee inserted at the end.\n");
}

void insertFront() {
    NODE newNode = createNode();
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Employee inserted at the front.\n");
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted employee with SSN: %s\n", head->ssn);
        free(head);
        head = NULL;
        return;
    }
    NODE temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("Deleted employee with SSN: %s\n", temp->ssn);
    temp->prev->next = NULL;
    free(temp);
}

void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    NODE temp = head;
    if (head->next == NULL) {
        printf("Deleted employee with SSN: %s\n", head->ssn);
        free(head);
        head = NULL;
        return;
    }
    head = head->next;
    head->prev = NULL;
    printf("Deleted employee with SSN: %s\n", temp->ssn);
    free(temp);
}

void displayAndCount() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int count = 0;
    NODE temp = head;
    printf("\n--- Employee List ---\n");
    while (temp != NULL) {
        printf("SSN: %s | Name: %s | Dept: %s | Designation: %s | Salary: %.2f | Phone: %s\n",
               temp->ssn, temp->name, temp->dept, temp->designation, temp->sal, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("Total employees: %d\n", count);
}

void doubleEndedQueueDemo() {
    int choice;
    while (1) {
        printf("\nDouble Ended Queue Operations:\n");
        printf("1. Insert at Front (Push)\n");
        printf("2. Insert at End (Enqueue)\n");
        printf("3. Delete from Front (Pop)\n");
        printf("4. Delete from End (Dequeue)\n");
        printf("5. Exit\n");
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
                insertEnd();
                break;
            case 2:
                displayAndCount();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                insertFront();
                break;
            case 6:
                deleteFront();
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
