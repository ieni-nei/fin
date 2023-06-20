#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>

void exitWithDelay(int seconds)
{
    sleep(seconds); // Затримка виконання програми на певну кількість секунд
    exit(1); // Завершення програми
}

int readMagicSqr(int sqrSize, int magicSqr[sqrSize][sqrSize])
{
    printf("\nВведіть по одному числу в квадрат, у:\n");
    for (int rowNum = 0; rowNum < sqrSize; rowNum++) {
        for (int colNum = 0; colNum < sqrSize; colNum++) {
            printf(" – рядок з № %d та стовпець з № %d: ", rowNum, colNum);
            if (scanf("%d", &magicSqr[rowNum][colNum]) != 1) {
                printf("\nПомилка: Введено некоректне число.");
                exitWithDelay(1.7); // Завершення програми з затримкою 1.7 секунди
            }
        }
    }
    return 0;
}

void printMagicSqr(int sqrSize, int magicSqr[sqrSize][sqrSize])
{
    printf("\nЗаповненим квадратом є:\n\n");
    for (int rowNum = 0; rowNum < sqrSize; rowNum++) {
        for (int colNum = 0; colNum < sqrSize; colNum++) {
            printf("%3d", magicSqr[rowNum][colNum]);
        }
        printf("\n");
    }
}

int checkMagicSqr(int sqrSize, int magicSqr[sqrSize][sqrSize])
{
    int sum = 0;

    for (int rowNum = 0; rowNum < sqrSize; rowNum++) {
        sum += magicSqr[rowNum][rowNum];
    }

    int diagSum = 0;
    for (int rowNum = 0, colNum = sqrSize - 1; rowNum < sqrSize; rowNum++, colNum--) {
        diagSum += magicSqr[rowNum][colNum];
    }

    if (sum != diagSum) {
        printf("\nКвадрат не є магічним.\n\n");
        return -1;
    }

    for (int rowNum = 0; rowNum < sqrSize; rowNum++) {
        int sumRow = 0;
        int sumCol = 0;

        for (int colNum = 0; colNum < sqrSize; colNum++) {
            sumRow += magicSqr[colNum][rowNum];
            sumCol += magicSqr[rowNum][colNum];
        }

        if (sum != sumRow || sum != sumCol) {
            printf("\nКвадрат не є магічним.\n\n");
            return -1;
        }
    }

    printf("\nЦей квадрат є магічним. Та має спільну сумму = %d.\n\n", sum);
    return 0;
}

void displayMenu()
{
    printf("************Меню:**************************************************\n");
    printf("1. Правила роботи програми;\n");
    printf("2. Почати;\n");
    printf("3. Вихід.\n");
    printf("Введіть пункт меню: ");
}

void displayRules()
{
    printf("Правила:\n");
    printf(" – магічним квадратом буде називатися матриця, в якій сума чисел у кожному ряду, стовпцю і двох діагоналях однакова.\n");
    printf(" – спочатку потрібно ввести розмір матриці, причому це має бути натуральне непарне число або двійка.\n");
    printf(" – потім по одному ввести цілі числа у квадрат.\n");
    printf(" – як тільки всі числа будуть введені, програма перевірить, чи є квадрат магічним і, якщо так, виведе суму елементів.\n");
    printf("Приклад заповненого магічного квадрата 3x3 (зліва) та матриці, що йому відповідає, з номерами (рядок;стовпець): \n\n");
    printf("   2   7   6      (0;0)  (0;1)  (0;2)\n");
    printf("   9   5   1      (1;0)  (1;1)  (1;2)\n");
    printf("   4   3   8      (2;0)  (2;1)  (2;2)\n\n");
}

int main()
{
    setlocale(LC_CTYPE, "ukr");

    int sqrSize;
    int choice;

    // безкінечний цикл 1 (true), доки не буде знайдено return()
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        printf("*******************************************************************\n");

        if (choice == 1) {
            displayRules();
            exitWithDelay(30); // Завершення програми з затримкою 30 секунд
        } else if (choice == 2) {
            printf("\nВведіть розмір квадрата: ");
            scanf("%d", &sqrSize);

            if (sqrSize <= 0 || (sqrSize % 2 != 1 && sqrSize >= 4)) {
                printf("\nПомилка: Розмір квадрата повинен бути непарним натуральним числом або бути рівним двум.");
                exitWithDelay(2); // Завершення програми з затримкою 3 секунд
            } else {
                int magicSqr[sqrSize][sqrSize];

                readMagicSqr(sqrSize, magicSqr);
                printMagicSqr(sqrSize, magicSqr);
                checkMagicSqr(sqrSize, magicSqr);
            }

        } else if (choice == 3) {
            printf("\nРобота програми завершена.\n");
            return 0;
        } else {
            printf("Помилка: Некоректний вибір. Спробуйте ввести значення включно від 1 до 3.\n");
            exitWithDelay(2); // Завершення програми з затримкою 3 секунд
        }
    }

    return 0;
}