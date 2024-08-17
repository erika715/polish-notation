#include "calculate_in_polish.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defines.h"

void calculate_coordinates_in_polish(char **matrix, char *expression) {
    HEAD head;
    define_stack(&head);
    calculate_coordinates(matrix, HEIGHT, WIDTH, expression, &head);
}

// вычисляем по польской системе - числа пишем в стек. видим операцию - достаем из стека нужное количество
// чисел и проводим операцию
double calculate(char *output_string, HEAD *head, double x) {
    double var1, var2;
    for (int i = 0; i < (int)strlen(output_string); ++i) {
        if (output_string[i] == 'x') {
            pushing(x, head);
        } else if (output_string[i] >= '0' && output_string[i] <= '9') {
            pushing((output_string[i] - '0'), head);
        } else if (output_string[i] == '+') {
            var2 = pop(head);
            var1 = pop(head);
            pushing(var1 + var2, head);
        } else if (output_string[i] == '-') {
            var2 = pop(head);
            var1 = pop(head);
            pushing(var1 - var2, head);
        } else if (output_string[i] == '*') {
            var2 = pop(head);
            var1 = pop(head);
            pushing(var1 * var2, head);
        } else if (output_string[i] == '/') {
            var2 = pop(head);
            var1 = pop(head);
            pushing(var1 / var2, head);
        } else if (output_string[i] == 's') {
            var1 = pop(head);
            pushing(sin(var1), head);
        } else if (output_string[i] == 'c') {
            var1 = pop(head);
            pushing(cos(var1), head);
        } else if (output_string[i] == 't') {
            var1 = pop(head);
            pushing(tan(var1), head);
        } else if (output_string[i] == 'g') {
            var1 = pop(head);
            pushing(1 / tan(var1), head);
        } else if (output_string[i] == 'q') {
            var1 = pop(head);
            pushing(sqrt(var1), head);
        } else if (output_string[i] == 'l') {
            var1 = pop(head);
            pushing(log(var1), head);
        } else if (output_string[i] == '~') {
            var1 = pop(head);
            pushing(-1 * var1, head);
        }
    }
    return pop(head);
}

void define_stack(HEAD *head) { head->point = NULL; }  //указатель на след элемент - нал

// функция добавления в стек
void pushing(double num, HEAD *head) {
    NUMBERS *t;       //временный указатель на элемент в стеке
    t = head->point;  //записываем указатель на последний элемент
    NUMBERS *new = (NUMBERS *)malloc(sizeof(NUMBERS));  //создание нового элемента в стэке
    new->num = num;                                     //добавляем значение числа
    new->point = t;     //переписываем указатель на последний элемент
    head->point = new;  //записываем указатель на новый элемент
}

// функция удаления из стека - возвращает удаленный элемент
double pop(HEAD *head) {
    double x;
    NUMBERS *t = head->point;  //создаем временнй указатель на последний эл в стеке
    x = head->point->num;  //берем значение, которое удаляем (последнее в стэке)
    head->point = head->point->point;  //переписываем указатель head на предпоследний элемент
    free(t);
    return x;
}

// расчитываем куда ставить *
void calculate_coordinates(char **graph, int height, int width, char *output_string, HEAD *head) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int y_coordinate = round(12 + 12 * calculate(output_string, head, (M_PI * x) / 20));
            if (y_coordinate >= 0 && y_coordinate < 25) graph[y_coordinate][x] = graph_dot;
        }
    }
}