#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int a[], int left, int right)
{
    int mid;

    if (left < right) {
        mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main(void)
{
    int n, i, c;
    int *a;

    printf("Enter number of elements: ");
    fflush(stdout);
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000000) {
        printf("Invalid input.\n");
        return 1;
    }

    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    fflush(stdout);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Invalid input.\n");
            free(a);
            return 1;
        }
    }

    mergeSort(a, 0, n - 1);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    free(a);

    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Press Enter to exit...");
    fflush(stdout);
    getchar();

    return 0;
}
