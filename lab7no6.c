#include <stdio.h>
#include <stdlib.h>

void random_element(int m, int n, int array[m][n]);
int check_exist(int m, int n, int array[m][n], int value);

int main() {
    int m, n;

    scanf("%d %d", &m, &n);

    if (m > 2 && m < 20 && n > 2 && n < 20) {
        if (m*n <= 100) {
            int array[m][n]; 
            random_element(m, n, array); // ส่ง m, n เข้าไปด้วย

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d ", array[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("จำนวนสมาชิกทั้งหมดไม่อยู่ในช่วง 100-200");
        }
    } else {
        printf("ค่า m หรือ n ไม่อยู่ในช่วงที่กำหนด (3-19)");
    }

    return 0;
}

void random_element(int m, int n, int array[m][n]) {
    int value;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            do {
                value = rand() % 101 + 100;
            } while (check_exist(m, n, array, value));
            array[i][j] = value;
        }
    }
}
int check_exist(int m, int n, int array[m][n], int value) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] == value) {
                return 1;
            }
        }
    }
    return 0;
}