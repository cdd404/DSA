#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COMPARE(x, y) ((x == y) ? 0 : ((x > y) ? 1 : -1))

struct node {
    int coef;
    int xexp, yexp, zexp;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode() {
    NODE x = (NODE) malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return x;
}

NODE attach(int coef, int xexp, int yexp, int zexp, NODE head) {
    if (coef == 0) return head;
    NODE temp = getnode();
    temp->coef = coef;
    temp->xexp = xexp;
    temp->yexp = yexp;
    temp->zexp = zexp;
    NODE cur = head;
    while (cur->link != head)
        cur = cur->link;
    cur->link = temp;
    temp->link = head;
    return head;
}

NODE read_poly(NODE head) {
    int n, coef, xexp, yexp, zexp;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("\nTerm %d:\n", i);
        printf("Coefficient: ");
        scanf("%d", &coef);
        printf("Powers of x, y, z: ");
        scanf("%d %d %d", &xexp, &yexp, &zexp);
        head = attach(coef, xexp, yexp, zexp, head);
    }
    return head;
}

void display(NODE head) {
    NODE temp = head->link;
    if (temp == head) {
        printf("0\n");
        return;
    }
    while (temp != head) {
        printf("%+dx^%dy^%dz^%d ", temp->coef, temp->xexp, temp->yexp, temp->zexp);
        temp = temp->link;
    }
    printf("\n");
}

int poly_evaluate(NODE head) {
    int x, y, z;
    double sum = 0;
    printf("Enter the values of x, y, z: ");
    scanf("%d %d %d", &x, &y, &z);
    NODE temp = head->link;
    while (temp != head) {
        sum += temp->coef * pow(x, temp->xexp) * pow(y, temp->yexp) * pow(z, temp->zexp);
        temp = temp->link;
    }
    return (int)sum;
}

int compare_terms(NODE a, NODE b) {
    if (a->xexp != b->xexp)
        return COMPARE(a->xexp, b->xexp);
    if (a->yexp != b->yexp)
        return COMPARE(a->yexp, b->yexp);
    return COMPARE(a->zexp, b->zexp);
}

NODE poly_sum(NODE head1, NODE head2, NODE head3) {
    NODE a = head1->link;
    NODE b = head2->link;
    while (a != head1 && b != head2) {
        int cmp = compare_terms(a, b);
        if (cmp == 0) {
            int sum_coef = a->coef + b->coef;
            head3 = attach(sum_coef, a->xexp, a->yexp, a->zexp, head3);
            a = a->link;
            b = b->link;
        } else if (cmp > 0) {
            head3 = attach(a->coef, a->xexp, a->yexp, a->zexp, head3);
            a = a->link;
        } else {
            head3 = attach(b->coef, b->xexp, b->yexp, b->zexp, head3);
            b = b->link;
        }
    }
    while (a != head1) {
        head3 = attach(a->coef, a->xexp, a->yexp, a->zexp, head3);
        a = a->link;
    }
    while (b != head2) {
        head3 = attach(b->coef, b->xexp, b->yexp, b->zexp, head3);
        b = b->link;
    }
    return head3;
}

int main() {
    NODE head, head1, head2, head3;
    int ch, res;
    head = getnode(); head->link = head;
    head1 = getnode(); head1->link = head1;
    head2 = getnode(); head2->link = head2;
    head3 = getnode(); head3->link = head3;
    while (1) {
        printf("\n===== Menu =====");
        printf("\n1. Represent and Evaluate a Polynomial P(x,y,z)");
        printf("\n2. Find the Sum of Two Polynomials POLY1(x,y,z) and POLY2(x,y,z)");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                head = getnode(); head->link = head;
                printf("\n--- Polynomial Evaluation ---\n");
                head = read_poly(head);
                printf("Polynomial: ");
                display(head);
                res = poly_evaluate(head);
                printf("Evaluated result: %d\n", res);
                break;
            case 2:
                head1 = getnode(); head1->link = head1;
                head2 = getnode(); head2->link = head2;
                head3 = getnode(); head3->link = head3;
                printf("\n--- Enter POLY1 ---\n");
                head1 = read_poly(head1);
                printf("POLY1: ");
                display(head1);
                printf("\n--- Enter POLY2 ---\n");
                head2 = read_poly(head2);
                printf("POLY2: ");
                display(head2);
                head3 = poly_sum(head1, head2, head3);
                printf("\nSum of POLY1 and POLY2: ");
                display(head3);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
