#include <stdio.h>

#define SIZE 10

int table[SIZE];

int hash(int key) {
    return key % SIZE;
}

void init() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

void insert(int key) {
    int index = hash(key);
    int start = index;

    while (table[index] != -1) {
        index = (index + 1) % SIZE;
        if (index == start) {
            table[start] = key;
            return;
        }
    }
    table[index] = key;
}

int search(int key) {
    int index = hash(key);
    int start = index;

    while (table[index] != -1) {
        if (table[index] == key)
            return index;
        index = (index + 1) % SIZE;
        if (index == start)
            break;
    }
    return -1;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, table[i]);
    }
}

int main() {
    int choice, key, result;
    init();

    while (1) {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                result = search(key);
                if (result != -1)
                    printf("Found at index %d\n", result);
                else
                    printf("Not found\n");
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
