#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int length;
    int data[NMAX];

    if (input(data, &length) != 0) {
        printf("n/a");
        return 0;
    }

    int sum = sum_numbers(data, length);

    if (sum == 0) {
        printf("n/a");
        return 0;
    }

    int result[NMAX];
    int result_length = find_numbers(data, length, sum, result);

    if (result_length == 0) {
        printf("n/a");
        return 0;
    }

    printf("%d\n", sum);
    output(result, result_length);

    return 0;
}

int input(int *buffer, int *length) {
    if (scanf("%d", length) != 1 || *length <= 0 || *length > NMAX) {
        return 1;
    }
    for (int i = 0; i < *length; i++) {
        if (scanf("%d", &buffer[i]) != 1) {
            return 1;
        }
    }
    return 0;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", buffer[i]);
        if (i < length - 1) {
            printf(" ");
        }
    }
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && buffer[i] % 2 == 0) {
            sum += buffer[i];
        }
    }
    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] == 0) continue;
        if (number % buffer[i] == 0) {
            numbers[count] = buffer[i];
            count++;
        }
    }
    return count;
}
