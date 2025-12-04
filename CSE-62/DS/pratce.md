Absolutely! Here are **Lab Test–style** questions with **answers in C** on the topics you mentioned:

---

## ✅ **1️⃣ Binary Search Using Recursion**

### **Q1: Write a C program to perform Binary Search using Recursion.**

📌 **Answer (C Code):**

```c
#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        return binarySearch(arr, mid + 1, right, target);
    }
    return -1;
}

int main() {
    int n, i, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter sorted array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
```

---

## ✅ **2️⃣ Circular Queue – Insertion and Deletion**

### **Q2: Write a C program to implement Circular Queue using array (enqueue & dequeue).**

📌 **Answer (C Code):**

```c
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    for (i = front; i != rear; i = (i + 1) % SIZE)
        printf("%d ", queue[i]);
    printf("%d\n", queue[i]);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); // becomes full
    display();
    dequeue();
    display();

    return 0;
}
```

---

## ✅ **3️⃣ Circular Linked List – Insert & Delete**

### **Q3: Write a C program to insert and delete nodes in Circular Linked List.**

📌 **Answer (C Code):**

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteNode(int value) {
    struct Node *temp = head, *prev;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->data == value && head->next == head) {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->data != value) {
        prev = temp;
        temp = temp->next;
        if (temp == head) {
            printf("Value not found\n");
            return;
        }
    }
    prev->next = temp->next;
    if (temp == head)
        head = prev->next;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    display();
    deleteNode(20);
    display();
    return 0;
}
```

---

## 🔎 Insertion + Binary Search Combined

### **Q4: Insert a number in sorted array then apply Binary Search**

📌 **Answer (C Code):**

```c
#include <stdio.h>

void insertSorted(int arr[], int *n, int value) {
    int i = *n - 1;
    while (i >= 0 && arr[i] > value) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = value;
    (*n)++;
}

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int n = 5, target, value;
    int arr[10] = {10, 20, 30, 40, 50};

    printf("Enter value to insert: ");
    scanf("%d", &value);

    insertSorted(arr, &n, value);

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Enter value to search: ");
    scanf("%d", &target);

    int index = binarySearch(arr, n, target);
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    return 0;
}
```

---

## 📌 If you want, I can also provide:

✔ Flowcharts
✔ Short viva questions & answers
✔ Output screenshots
✔ Same codes with comments simplified for lab exam writing
✔ Bangla explanation if needed

---

Would you like Bangla translation for all questions and codes as well? 🇧🇩✨
