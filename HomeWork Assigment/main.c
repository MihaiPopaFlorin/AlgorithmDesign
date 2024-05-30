#include <stdio.h>
#include <stdlib.h>


int cmp_desc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp_desc);
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int *group1 = (int *)malloc(n * sizeof(int));
    int *group2 = (int *)malloc(n * sizeof(int));
    int *group3 = (int *)malloc(n * sizeof(int));
    int size1 = 0, size2 = 0, size3 = 0;
    for (int i = 0; i < n; i++) {
        if (sum1 <= sum2 && sum1 <= sum3) {
            sum1 += arr[i];
            group1[size1++] = arr[i];
        } else if (sum2 <= sum1 && sum2 <= sum3) {
            sum2 += arr[i];
            group2[size2++] = arr[i];
        } else {
            sum3 += arr[i];
            group3[size3++] = arr[i];
        }
    }
    int min_sum = sum1, max_sum = sum1;
    if (sum2 < min_sum) min_sum = sum2;
    if (sum3 < min_sum) min_sum = sum3;
    if (sum2 > max_sum) max_sum = sum2;
    if (sum3 > max_sum) max_sum = sum3;
    printf("Group 1: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", group1[i]);
    }
    printf("\nSum of Group 1: %d\n", sum1);

    printf("Group 2: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", group2[i]);
    }
    printf("\nSum of Group 2: %d\n", sum2);

    printf("Group 3: ");
    for (int i = 0; i < size3; i++) {
        printf("%d ", group3[i]);
    }
    printf("\nSum of Group 3: %d\n", sum3);

    printf("Smallest sum: %d\n", min_sum);
    printf("Largest sum: %d\n", max_sum);
    return 0;
}
