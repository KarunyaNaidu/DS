#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next;
};

struct list *head = NULL;
struct list *head2 = NULL;

struct list *create(int data) {
    struct list *newlist = (struct list *)malloc(sizeof(struct list));
    newlist->data = data;
    newlist->next = NULL;
    return newlist;
}

void insertAtbeg(int data) {
    struct list *newlist = create(data);
    newlist->next = head;
    head = newlist;
    printf("%d inserted at the beginning\n", data);
}

void insertAtend(int data) {
    struct list *newlist = create(data);
    if (head == NULL) {
        head = newlist;
    } else {
        struct list *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newlist;
    }
    printf("%d inserted at the end\n", data);
}

void insertAtpos(int data, int pos) {
    struct list *newlist = create(data);
    if (pos == 1) {
        newlist->next = head;
        head = newlist;
    } else {
        struct list *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        if (temp == NULL) {
            printf("Invalid position!\n");
            free(newlist);
            return;
        }
        newlist->next = temp->next;
        temp->next = newlist;
    }
    printf("%d inserted at position %d\n", data, pos);
}

void deleteatbegin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct list *temp = head;
    head = head->next;
    printf("%d deleted from beginning\n", temp->data);
    free(temp);
}

void deleteatend() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        printf("%d deleted from end\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct list *temp = head;
    struct list *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("%d deleted from end\n", temp->data);
    prev->next = NULL;
    free(temp);
}

void deletevalue(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct list *temp = head;
    struct list *prev = NULL;

    if (temp->data == value) {
        head = temp->next;
        printf("%d deleted\n", value);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    printf("Value %d deleted\n", value);
    free(temp);
}

void deleteAtpos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        struct list *temp = head;
        head = head->next;
        printf("Node at position %d deleted\n", pos);
        free(temp);
        return;
    }

    struct list *temp = head;
    struct list *prev = NULL;

    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    prev->next = temp->next;
    printf("Node at position %d deleted\n", pos);
    free(temp);
}

int countnodes() {
    int count = 0;
    struct list *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void reverse() {
    struct list *prev = NULL, *next = NULL, *curr = head;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    printf("List reversed successfully\n");
}

void sort() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct list *i, *j;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("List sorted successfully\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct list *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void buildSecondList() {
    int data;
    head2 = NULL;

    printf("Enter values for second list (end with -1):\n");
    while (1) {
        scanf("%d", &data);
        if (data == -1) break;

        struct list *newnode = create(data);

        if (head2 == NULL)
            head2 = newnode;
        else {
            struct list *temp = head2;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }

    printf("Second list created successfully\n");
}

void concatenateSecondList() {
    if (head2 == NULL) {
        printf("Second list is empty. Nothing to concatenate.\n");
        return;
    }
    if (head == NULL) {
        head = head2;
        head2 = NULL;
        printf("Second list concatenated to main list\n");
        return;
    }

    struct list *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    head2 = NULL;
    printf("Second list concatenated to main list\n");
}

int main() {
    int ch, data, pos, value;

    while (1) {
        printf("\n\n*** MENU ***\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete by value\n");
        printf("7. Delete at position\n");
        printf("8. Count nodes\n");
        printf("9. Reverse list\n");
        printf("10. Sort list\n");
        printf("11. Build second list\n");
        printf("12. Concatenate second list\n");
        printf("13. Display main list\n");
        printf("14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertAtbeg(data);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                insertAtend(data);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtpos(data, pos);
                break;

            case 4:
                deleteatbegin();
                break;

            case 5:
                deleteatend();
                break;

            case 6:
                printf("Enter value: ");
                scanf("%d", &value);
                deletevalue(value);
                break;

            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtpos(pos);
                break;

            case 8:
                printf("Total nodes: %d\n", countnodes());
                break;

            case 9:
                reverse();
                break;

            case 10:
                sort();
                break;

            case 11:
                buildSecondList();
                break;

            case 12:
                concatenateSecondList();
                break;

            case 13:
                display();
                break;

            case 14:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
