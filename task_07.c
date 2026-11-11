#include <stdio.h>

int findMax(int *p, int n) {
    int max = *p;
    for (int i = 0; i < n; i++) {
        if (*(p + i) > max) {
            max = *(p + i);
        }
    }
    return max;
}

int findMin(int *p, int n) {
    int min = *p;
    for (int i = 0; i < n; i++) {
        if (*(p + i) < min) {
            min = *(p + i);
        }
    }
    return min;
}

double findAverage(int *p, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(p + i);
    }
    return sum / n;
}

/* Counts students whose marks are above the average */
int countAbove(int *p, int n, double avg) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(p + i) > avg) {
            count++;
        }
    }
    return count;
}

/* Counts students who passed (marks 40 or more) */
int countPass(int *p, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (*(p + i) >= 40) {
            count++;
        }
    }
    return count;
}

/* Reverses the array using two pointers moving towards each other */
void reverseArray(int *p, int n) {
    int *start = p;
    int *end = p + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int searchMark(int *p, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (*(p + i) == key) {
            return i;
        }
    }
    return -1;
}

void printMarks(int *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("Student %d: %d\n", i + 1, *(p + i));
    }
}

int main(void) {
    int marks[10];
    int key, pos;

    for (int i = 0; i < 10; i++) {
        while (1) {
            printf("\nEnter Marks of Student %d: ", i + 1);
            scanf("%d", &marks[i]);
            if (marks[i] >= 0 && marks[i] <= 100) {
                break;
            }
            printf("Invalid Marks. Please enter marks between 0 and 100.\n");
        }
    }

    printf("\n--- Marks before reversing ---\n");
    printMarks(marks, 10);

    printf("\nHighest Mark: %d\n", findMax(marks, 10));
    printf("Lowest Mark: %d\n", findMin(marks, 10));

    double avg = findAverage(marks, 10);
    printf("Average Mark: %.2f\n", avg);
    printf("Students above average: %d\n", countAbove(marks, 10, avg));
    printf("Pass Count (40 or more): %d\n", countPass(marks, 10));

    reverseArray(marks, 10);
    printf("\n--- Marks after reversing ---\n");
    printMarks(marks, 10);

    printf("\nEnter a mark to search for: ");
    scanf("%d", &key);
    pos = searchMark(marks, 10, key);
    if (pos != -1) {
        printf("Mark %d found at position %d (Student %d)\n", key, pos, pos + 1);
    } else {
        printf("Mark %d not found in the class.\n", key);
    }

    return 0;
}