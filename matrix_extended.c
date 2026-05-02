#include <limits.h>
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
        int matrix[max_size][max_size];
        int row_max[rows];
        int col_min[cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (scanf("%d", &matrix[i][j]) != 1) {
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
        printf("\n");
        for (int i = 0; i < rows; i++) {
            row_max[i] = matrix[i][0];
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] > row_max[i]) {
                    row_max[i] = matrix[i][j];
                }
            }
        }
        for (int j = 0; j < cols; j++) {
            col_min[j] = matrix[0][j];
            for (int i = 1; i < rows; i++) {
                if (matrix[i][j] < col_min[j]) {
                    col_min[j] = matrix[i][j];
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            printf("%d", row_max[i]);
            if (i < rows - 1) printf(" ");
        }
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%d", col_min[j]);
            if (j < cols - 1) printf(" ");
        }
    }
    if (choice == 2) {
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

        int row_max[rows];
        int col_min[cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (scanf("%d", &matrix[i][j]) != 1) {
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
        printf("\n");
        for (int i = 0; i < rows; i++) {
            row_max[i] = matrix[i][0];
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] > row_max[i]) {
                    row_max[i] = matrix[i][j];
                }
            }
        }
        for (int j = 0; j < cols; j++) {
            col_min[j] = matrix[0][j];
            for (int i = 1; i < rows; i++) {
                if (matrix[i][j] < col_min[j]) {
                    col_min[j] = matrix[i][j];
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            printf("%d", row_max[i]);
            if (i < rows - 1) printf(" ");
        }
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%d", col_min[j]);
            if (j < cols - 1) printf(" ");
        }

        for (int i = 0; i < rows; i++) free(matrix[i]);
        free(matrix);
    }
    if (choice == 3) {
        int *matrix = malloc(rows * cols * sizeof(int));
        if (matrix == NULL) {
            printf("n/a");
            return 0;
        }

        int row_max[rows];
        int col_min[cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (scanf("%d", &matrix[i * cols + j]) != 1) {
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
        printf("\n");
        for (int i = 0; i < rows; i++) {
            row_max[i] = matrix[i * cols + 0];
            for (int j = 1; j < cols; j++) {
                if (matrix[i * cols + j] > row_max[i]) {
                    row_max[i] = matrix[i * cols + j];
                }
            }
        }
        for (int j = 0; j < cols; j++) {
            col_min[j] = matrix[0 * cols + j];
            for (int i = 1; i < rows; i++) {
                if (matrix[i * cols + j] < col_min[j]) {
                    col_min[j] = matrix[i * cols + j];
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            printf("%d", row_max[i]);
            if (i < rows - 1) printf(" ");
        }
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%d", col_min[j]);
            if (j < cols - 1) printf(" ");
        }

        free(matrix);
    }
    if (choice == 4) {
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

        int row_max[rows];
        int col_min[cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (scanf("%d", &matrix[i][j]) != 1) {
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
        printf("\n");
        for (int i = 0; i < rows; i++) {
            row_max[i] = matrix[i][0];
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] > row_max[i]) {
                    row_max[i] = matrix[i][j];
                }
            }
        }
        for (int j = 0; j < cols; j++) {
            col_min[j] = matrix[0][j];
            for (int i = 1; i < rows; i++) {
                if (matrix[i][j] < col_min[j]) {
                    col_min[j] = matrix[i][j];
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            printf("%d", row_max[i]);
            if (i < rows - 1) printf(" ");
        }
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%d", col_min[j]);
            if (j < cols - 1) printf(" ");
        }
        free(data);
        free(matrix);
    }
    return 0;
}
