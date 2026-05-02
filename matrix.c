#include <stdio.h>
#include <stdlib.h>
#define max_size 100

int main() {
    int choice, rows, cols;
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
        printf("n/a");
        return 0;
    }
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        printf("n/a");
        return 0;
    }
    if (choice == 1 && (rows > max_size || cols > max_size)) {
        printf("n/a");
        return 0;
    }
    if (choice == 1) {
        char q;
        int matrix[max_size][max_size];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (scanf("%d%c", &matrix[i][j], &q) != 2 || (q != '\n' && q != ' ')) {
                    printf("n/a");
                    return 0;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d", matrix[i][j]);
                if (j < cols - 1) printf(" ");
            }
            if (i < rows - 1) printf("\n");
        }
    }
    if (choice == 2) {
        char q;
        int **matrix = malloc(rows * sizeof(int *));
        if (matrix == NULL) {
            printf("n/a");
            return 0;
        }
        for (int i = 0; i < rows; i++) {
            matrix[i] = malloc(cols * sizeof(int));
            if (matrix[i] == NULL) {
                for (int k = 0; k < i; k++) free(matrix[k]);
                free(matrix);
                printf("n/a");
                return 0;
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (scanf("%d%c", &matrix[i][j], &q) != 2 || (q != '\n' && q != ' ')) {
                    for (int k = 0; k < rows; k++) free(matrix[k]);
                    free(matrix);
                    printf("n/a");
                    return 0;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d", matrix[i][j]);
                if (j < cols - 1) printf(" ");
            }
            if (i < rows - 1) printf("\n");
        }
        for (int i = 0; i < rows; i++) free(matrix[i]);
        free(matrix);
    }
    if (choice == 3) {
        char q;
        int *matrix = malloc(rows * cols * sizeof(int));
        if (matrix == NULL) {
            printf("n/a");
            return 0;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (scanf("%d%c", &matrix[i * cols + j], &q) != 2 || (q != '\n' && q != ' ')) {
                    free(matrix);
                    printf("n/a");
                    return 0;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d", matrix[i * cols + j]);
                if (j < cols - 1) printf(" ");
            }
            if (i < rows - 1) printf("\n");
        }
        free(matrix);
    }
    if (choice == 4) {
        char q;
        int **matrix = malloc(rows * sizeof(int *));
        if (matrix == NULL) {
            printf("n/a");
            return 0;
        }
        int *data = malloc(rows * cols * sizeof(int));
        if (data == NULL) {
            free(matrix);
            printf("n/a");
            return 0;
        }
        for (int i = 0; i < rows; i++) {
            matrix[i] = data + i * cols;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (scanf("%d%c", &matrix[i][j], &q) != 2 || (q != '\n' && q != ' ')) {
                    free(data);
                    free(matrix);
                    printf("n/a");
                    return 0;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d", matrix[i][j]);
                if (j < cols - 1) printf(" ");
            }
            if (i < rows - 1) printf("\n");
        }
        free(data);
        free(matrix);
    }
    return 0;
}
