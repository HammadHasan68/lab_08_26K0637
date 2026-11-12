#include <stdio.h>
#include <string.h>

/* Reads 3 marks (0 to 100) and sends them back through pointers */
void readMarks(int *m1, int *m2, int *m3) {
    do {
        printf("Enter mark 1 (0-100): ");
        scanf("%d", m1);
    } while (*m1 < 0 || *m1 > 100);

    do {
        printf("Enter mark 2 (0-100): ");
        scanf("%d", m2);
    } while (*m2 < 0 || *m2 > 100);

    do {
        printf("Enter mark 3 (0-100): ");
        scanf("%d", m3);
    } while (*m3 < 0 || *m3 > 100);
}

/* Gives back four results: total, average, highest and lowest */
void calculateStats(int m1, int m2, int m3, int *total, double *average,
                    int *highest, int *lowest) {
    *total = m1 + m2 + m3;
    *average = *total / 3.0;

    *highest = m1;
    if (m2 > *highest) *highest = m2;
    if (m3 > *highest) *highest = m3;

    *lowest = m1;
    if (m2 < *lowest) *lowest = m2;
    if (m3 < *lowest) *lowest = m3;
}

/* Swaps the values that a and b point to */
void swapMarks(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Adds grace marks to a mark from 35 to 39, only as much as needed to reach 40 (max grace) */
void addGraceMarks(int *mark, int grace) {
    if (*mark >= 35 && *mark <= 39) {
        int needed = 40 - *mark;
        *mark += (grace < needed) ? grace : needed;
    }
}

/* Gives back a grade and a remark based on the average */
void findGrade(double avg, char *grade, char *remarks) {
    if (avg >= 75) {
        *grade = 'A';
        strcpy(remarks, "Excellent");
    } else if (avg >= 50) {
        *grade = 'B';
        strcpy(remarks, "Good");
    } else {
        *grade = 'F';
        strcpy(remarks, "Needs Improvement");
    }
}

/* Receives a copy, so the change stays inside this function.
   Output is 11 but the caller's variable is not changed. */
void incrementByValue(int x) {
    x++;
    printf("Inside incrementByValue: x = %d\n", x);
}

/* Receives the address, so the change reaches the caller's variable.
   The caller's variable becomes 11. */
void incrementByReference(int *x) {
    (*x)++;
    printf("Inside incrementByReference: x = %d\n", *x);
}

int main(void) {
    int m1, m2, m3;
    int total, highest, lowest;
    double avg;
    char grade, choice;
    char remarks[30];

    int totals[5];
    double averages[5];
    char grades[5];
    char remarkList[5][30];
    int s;

    for (s = 0; s < 5; s++) {
        printf("\n--- Student %d ---\n", s + 1);
        readMarks(&m1, &m2, &m3);

        /* Sort the 3 marks from highest to lowest */
        if (m1 < m2) swapMarks(&m1, &m2);
        if (m1 < m3) swapMarks(&m1, &m3);
        if (m2 < m3) swapMarks(&m2, &m3);

        printf("Apply grace marks? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            addGraceMarks(&m1, 5);
            addGraceMarks(&m2, 5);
            addGraceMarks(&m3, 5);
        }

        calculateStats(m1, m2, m3, &total, &avg, &highest, &lowest);
        findGrade(avg, &grade, remarks);

        totals[s] = total;
        averages[s] = avg;
        grades[s] = grade;
        strcpy(remarkList[s], remarks);
    }

    printf("\n%-10s%-10s%-12s%-8s%s\n", "Student", "Total", "Average", "Grade", "Remark");
    printf("-------------------------------------------------------\n");
    for (s = 0; s < 5; s++) {
        printf("%-10d%-10d%-12.2f%-8c%s\n",
            s + 1, totals[s], averages[s], grades[s], remarkList[s]);
    }

    /* Comparison demo */
    int value = 10;
    printf("\n--- Comparison demo ---\n");
    printf("Before: value = %d\n", value);
    incrementByValue(value);
    printf("After incrementByValue: value = %d\n", value);
    incrementByReference(&value);
    printf("After incrementByReference: value = %d\n", value);

    return 0;
}