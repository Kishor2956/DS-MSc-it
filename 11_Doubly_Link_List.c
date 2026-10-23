
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

// Insert a node at the end
void insert() {
    struct node *newnode, *temp;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter integer value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Node inserted successfully.\n");
}

// Delete a node by value
void delete() {
    struct node *temp;
    int value;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted successfully.\n");
}

// Modify a node
void modify() {
    struct node *temp;
    int oldValue, newValue;

    printf("Enter value to modify: ");
    scanf("%d", &oldValue);

    temp = head;

    while (temp != NULL && temp->data != oldValue)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &newValue);

    temp->data = newValue;
    printf("Node modified successfully.\n");
}

// Display the list
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: NULL - ");

    while (temp != NULL) {
        printf("%d - ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main menu
int main() {
    int choice;

    do {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Modify\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                modify();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
