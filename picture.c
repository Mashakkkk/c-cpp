#include <stdio.h>
#define N 15
#define M 13

void transform(int* buffer, int** matrix, int n, int m);
void make_picture(int** picture, int n, int m);
void reset_picture(int** picture, int n, int m);

int main(void) {
    int picture_data[N][M];
    int* picture[N];

    transform(&picture_data[0][0], picture, N, M);
    make_picture(picture, N, M);

    return 0;
}

void make_picture(int** picture, int n, int m) {
    int frame_width[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_height[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int trunk[] = {7, 7, 7, 7};
    int foliage[] = {3, 3, 3, 3};
    int sun[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                     {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    for (int i = 0; i < m; i++) {
        picture[0][i] = frame_width[i];
        picture[7][i] = frame_width[i];
        picture[14][i] = frame_width[i];
    }

    for (int i = 0; i < n; i++) {
        picture[i][0] = frame_height[i];
        picture[i][6] = frame_height[i];
        picture[i][12] = frame_height[i];
    }

    picture[2][3] = foliage[0];
    picture[2][4] = foliage[1];

    for (int i = 0; i < 4; i++) {
        picture[3][i + 2] = foliage[i];
        picture[4][i + 2] = foliage[i];
    }

    picture[5][3] = foliage[2];
    picture[5][4] = foliage[3];

    picture[6][3] = trunk[0];
    picture[6][4] = trunk[1];
    picture[8][3] = trunk[0];
    picture[8][4] = trunk[1];
    picture[9][3] = trunk[2];
    picture[9][4] = trunk[3];

    for (int i = 0; i < 4; i++) {
        picture[10][i + 2] = trunk[i];
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            if (sun[i][j] != 0) {
                picture[i + 1][j + 7] = sun[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", picture[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void reset_picture(int** picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int* buffer, int** matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        matrix[i] = buffer + i * m;
    }
}
