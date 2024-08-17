#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculate_in_polish.h"
#include "defines.h"
#include "rendering_field.h"
#include "transform_to_polish.h"

int main() {
    char input_string[80];   //заводим массив для изначального выражения
    char output_string[80];  //для польской нотации
    // считываем выражение
    fgets(input_string, 80, stdin);
    char* expression =
        polish_translate(input_string, output_string);  // переводим в польскую -> transform_to_polish.c
    char** matrix = define_matrix();  // рендерим пустое поле -> rendering_field.c
    calculate_coordinates_in_polish(matrix,
                                    expression);  // вычисление по польской нотации -> calculate_in_polish.c
    print(matrix);  // вывод графика в терминал -> rendering_field.c
    return 0;
}
