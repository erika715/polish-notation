#include "rendering_field.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defines.h"

// создаем поле из .
char** define_matrix() {
    char** matrix = malloc(HEIGHT * sizeof(char*));  //заводим указатель на массивы
    for (int i = 0; i < HEIGHT; i++) {
        matrix[i] = malloc(WIDTH * sizeof(char));  //в ячейки подвязываем память (размером с ширину)
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            matrix[i][j] = field_dot;  //заполняем точками
        }
    }

    return matrix;
}

// вывод поля в терминал
void print(char** matrix) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {  //последнюю точку выводим без пробела
            if (j + 1 == WIDTH) {
                printf("%c", matrix[i][j]);
            } else {
                printf("%c ", matrix[i][j]);
            }
        }
        if (i + 1 != HEIGHT) {  //заканчиваем на последней строчке без переноса
            printf("\n");
        }
    }
    free_matrix(matrix);
}

// чистим память
void free_matrix(char** matrix) {
    for (int i = 0; i < HEIGHT; i++) {  //очищаем все ссылки
        free(matrix[i]);
    }
    free(matrix);
}