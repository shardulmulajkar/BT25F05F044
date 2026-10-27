#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, j, temp, swapped, c;
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

    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }

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
