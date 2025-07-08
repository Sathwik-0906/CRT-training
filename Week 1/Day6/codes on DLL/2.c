#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
} *nn, *head = NULL, *temp, *tail = NULL, *cur, *prev1;

void insert() {
    int d, val;
    printf("Entet the No of Node: ");
    scanf("%d", &d);
    for (int i = 1; i <= d; i++) {
        nn = (struct node*)malloc(sizeof(struct node));
        printf("Enter the %d Node data: ", i);
        scanf("%d", &val);
        nn->prev = NULL;
        nn->data = val;
        nn->next = NULL;
        if (head == NULL) {
            head = nn;
            tail = nn;
        } else {
            nn->prev = tail;
            tail->next = nn;
            tail = nn;
        }
    }
}

void display() {
    temp = head;
    while (temp) {
        printf("%d", temp->data);
        temp = temp->next;
        printf(" --> ");
    }
    printf("NULL\n");
}

void rev() {
    prev1 = NULL;
    cur = head;
    while (cur) {
        temp = cur->next;
        cur->next = prev1;
        cur->prev = temp;
        prev1 = cur;
        cur = temp;
    }
    head = prev1;
}

void main() {
    insert();
    display();
    rev();
    display();
}
    