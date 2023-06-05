#include <stdio.h> // Підключення стандартних функцій введення/виведення для мови C.
#include <locale.h> // Підключення функцій для роботи з локалізацією.

#define RIGHT_NUM_MARGIN 4

int readMagicSqr(int sqrSize, int magicSqr[sqrSize][sqrSize]) {
    printf("\nВведіть по одному числу в магічний квадрат, у:\n");
    for (int colNum = 0; colNum < sqrSize; colNum++) {
        for (int rowNum = 0; rowNum < sqrSize; rowNum++) {
            printf("· стовпець з № %d та рядком з № %d: ", colNum, rowNum);
            if (scanf("%d", &magicSqr[colNum][rowNum]) != 1) {
                printf("\nПомилка: Введено некоректне число.");
                return -1;
            }
        }
    }
}

void printMagicSqr(int sqrSize, int magicSqr[sqrSize][sqrSize]) {
    printf("\nЗаповнений магічний квадрат:\n\n");
    for (int colNum = 0; colNum < sqrSize; colNum++) {
        for (int rowNum = 0; rowNum < sqrSize; rowNum++) {
            printf("%*d ", RIGHT_NUM_MARGIN, magicSqr[colNum][rowNum]);
        }
        printf("\n");
    }
}

int checkMagicSqr(int sqrSize, int magicSqr[sqrSize][sqrSize]) {
    int sum = 0;
    
    for (int colNum = 0; colNum < sqrSize; colNum++) {
        sum += magicSqr[colNum][colNum];
    }
    
    int diagSum = 0;
    for (int colNum = 0, rowNum = sqrSize - 1; colNum < sqrSize; colNum++, rowNum--) {
        diagSum += magicSqr[colNum][rowNum];
    }
    
    if (sum != diagSum) {
        printf("\nКвадрат не є магічним.");
        return -1;
    }
    
    for (int colNum = 0; colNum < sqrSize; colNum++) {
        int sumRow = 0;
        int sumCol = 0;
        
        for (int rowNum = 0; rowNum < sqrSize; rowNum++) {
            sumRow += magicSqr[colNum][rowNum];
            sumCol += magicSqr[rowNum][colNum];
        }
        
        if (sum != sumRow || sum != sumCol) {
            printf("\nКвадрат не є магічним.");
            return -1;
        }
    }
    
    printf("\nЦей квадрат є магічним. Та має спільну сумму = %d.", sum);
    return 0;
}

int main() {
    setlocale(LC_CTYPE, "ukr");
    
    int sqrSize;
    
    printf("Введіть розмір магічного квадрату: ");
    scanf("%d", &sqrSize);
    
    if (sqrSize <= 0) {
        printf("\nПомилка: Введено некоректний розмір квадрату.");
        return -1;
    }
    
    int magicSqr[sqrSize][sqrSize];
    
    readMagicSqr(sqrSize, magicSqr);
    printMagicSqr(sqrSize, magicSqr);
    checkMagicSqr(sqrSize, magicSqr);
    
    return 0;
}
