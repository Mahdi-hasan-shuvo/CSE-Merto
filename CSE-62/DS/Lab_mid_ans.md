

---

## ✅ **1️⃣ Bubble Sort + Binary Search (Iterative) — C Program**

```c
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n, i, target, index;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Enter value to search: ");
    scanf("%d", &target);

    index = binarySearch(arr, n, target);

    if (index != -1)
        printf("Value found at index: %d\n", index);
    else
        printf("Value not found in the array\n");

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

---

## ✅ **2️⃣ Queue Implementation Using Array — C Program**

```c
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return rear == SIZE - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("%d enqueued\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("%d dequeued\n", queue[front]);
    front++;
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nEnter choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. IsEmpty\n5. IsFull\n6. Display\n7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                peek();
                break;
            case 4:
                printf(isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
                break;
            case 5:
                printf(isFull() ? "Queue is full\n" : "Queue is not full\n");
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Program exited.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
```



## ✅ **1️⃣ Insertion Sort + Linear Search — C Program**

```c
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Enter value to search: ");
    scanf("%d", &x);

    int index = linearSearch(arr, n, x);
    if (index != -1)
        printf("Value found at index: %d\n", index);
    else
        printf("Value not found in the array\n");

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

---

## ✅ **2️⃣ Stack Implementation Using Array — C Program**

```c
#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == SIZE - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed onto stack\n", value);
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}

void peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nChoose operation:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. IsEmpty\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                display();
                break;
            case 2:
                pop();
                display();
                break;
            case 3:
                peek();
                display();
                break;
            case 4:
                printf(isEmpty() ? "Stack is empty.\n" : "Stack is not empty.\n");
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Program exited.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
```

---

