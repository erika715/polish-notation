#include "transform_to_polish.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defines.h"

char* polish_translate(char* input_string, char* output_string) {
    struct st* operations = NULL;  //стек операций
    int output_index = 0;
    int input_index = 0;
    while (input_string[input_index] != '\0') {
        if (input_string[input_index] == ')') {  //Если символ ) то выталкиваем из стека в выходную стpоку все
                                                 //знаки опеpаций до ближайшей (
            while ((operations->c) != '(') {
                output_string[output_index++] = delete_element(&operations);
            }
            delete_element(&operations);  //Удаляем из стека саму откpывающую скобку
        }
        if ((input_string[input_index] >= '0' && input_string[input_index] <= '9') ||
            (input_string[input_index] == '.') ||
            (input_string[input_index] == 'x')) {  // если число или х - выписываем в строку
            output_string[output_index++] = input_string[input_index];
        }
        if (input_string[input_index] == '(') {
            operations = push(operations, '(');  // если ( то пихаем в стек
        }
        if (input_string[input_index] == 's' && input_string[input_index + 1] == 'i' &&
            input_string[input_index + 2] == 'n') {
            if (operations == NULL) {
                operations = push(operations, input_string[input_index]);
            } else if (priority(operations->c) < priority(input_string[input_index])) {
                operations = push(operations, input_string[input_index]);
            } else {
                while ((operations != NULL) &&
                       (priority(operations->c) >= priority(input_string[input_index])))
                    output_string[output_index++] = delete_element(
                        &operations);  // записываем в стpоку все опеpации с большим или pавным пpиоpитетом
                operations = push(operations, input_string[input_index]);
            }
            input_index += 2;
        }
        if (input_string[input_index] == 'c' && input_string[input_index + 1] == 'o' &&
            input_string[input_index + 2] == 's') {
            if (operations == NULL) {
                operations = push(operations, input_string[input_index]);
            } else if (priority(operations->c) < priority(input_string[input_index])) {
                operations = push(operations, input_string[input_index]);
            } else {
                while ((operations != NULL) &&
                       (priority(operations->c) >= priority(input_string[input_index])))
                    output_string[output_index++] = delete_element(
                        &operations);  // записываем в стpоку все опеpации с большим или pавным пpиоpитетом
                operations = push(operations, input_string[input_index]);
            }
            input_index += 2;
        }
        if (input_string[input_index] == 't' && input_string[input_index + 1] == 'a' &&
            input_string[input_index + 2] == 'n') {
            if (operations == NULL) {
                operations = push(operations, input_string[input_index]);
            } else if (priority(operations->c) < priority(input_string[input_index])) {
                operations = push(operations, input_string[input_index]);
            } else {
                while ((operations != NULL) &&
                       (priority(operations->c) >= priority(input_string[input_index])))
                    output_string[output_index++] = delete_element(
                        &operations);  // записываем в стpоку все опеpации с большим или pавным пpиоpитетом
                operations = push(operations, input_string[input_index]);
            }
            input_index += 2;
        }
        if (input_string[input_index] == 'c' && input_string[input_index + 1] == 't' &&
            input_string[input_index + 2] == 'g') {
            if (operations == NULL) {
                operations = push(operations, input_string[input_index + 2]);
            } else if (priority(operations->c) < priority(input_string[input_index + 2])) {
                operations = push(operations, input_string[input_index + 2]);
            } else {
                while ((operations != NULL) &&
                       (priority(operations->c) >= priority(input_string[input_index + 2])))
                    output_string[output_index++] = delete_element(
                        &operations);  // записываем в стpоку все опеpации с большим или pавным пpиоpитетом
                operations = push(operations, input_string[input_index + 2]);
            }
            input_index += 2;
        }
        if (input_string[input_index] == 's' && input_string[input_index + 1] == 'q' &&
            input_string[input_index + 2] == 'r' && input_string[input_index + 3] == 't') {
            if (operations == NULL) {
                operations = push(operations, input_string[input_index + 1]);
            } else if (priority(operations->c) < priority(input_string[input_index + 1])) {
                operations = push(operations, input_string[input_index + 1]);
            } else {
                while ((operations != NULL) &&
                       (priority(operations->c) >= priority(input_string[input_index + 1])))
                    output_string[output_index++] = delete_element(
                        &operations);  // записываем в стpоку все опеpации с большим или pавным пpиоpитетом
                operations = push(operations, input_string[input_index + 1]);
            }
            input_index += 3;
        }
        if (input_string[input_index] == 'l' && input_string[input_index + 1] == 'n') {
            if (operations == NULL) {
                operations = push(operations, input_string[input_index]);
            } else if (priority(operations->c) < priority(input_string[input_index])) {
                operations = push(operations, input_string[input_index]);
            } else {
                while ((operations != NULL) &&
                       (priority(operations->c) >= priority(input_string[input_index])))
                    output_string[output_index++] = delete_element(
                        &operations);  // записываем в стpоку все опеpации с большим или pавным пpиоpитетом
                operations = push(operations, input_string[input_index]);
            }
            input_index += 1;
        }

        if (input_string[input_index] == '-') {
            if ((input_index == 0 ||
                 (input_string[input_index - 1] != '0' && input_string[input_index - 1] != '1' &&
                  input_string[input_index - 1] != '2' && input_string[input_index - 1] != '3' &&
                  input_string[input_index - 1] != '4' && input_string[input_index - 1] != '5' &&
                  input_string[input_index - 1] != '6' && input_string[input_index - 1] != '7' &&
                  input_string[input_index - 1] != '8' && input_string[input_index - 1] != '9'))) {
                if (operations == NULL) {
                    operations = push(operations, '~');
                } else if (priority(operations->c) < priority('~')) {
                    operations = push(operations, '~');
                } else {
                    while ((operations != NULL) && (priority(operations->c) >= priority('~')))
                        output_string[output_index++] =
                            delete_element(&operations);  // записываем в стpоку все опеpации с большим или
                                                          // pавным пpиоpитетом
                    operations = push(operations, '~');
                }
            } else {
                if (operations == NULL)                                        // и стек пустой
                    operations = push(operations, input_string[input_index]);  // в стек пихаем операцию
                else if (priority(operations->c) <
                         priority(input_string[input_index]))  // если эта опеpация сильнее опеpации на
                                                               // веpшине стека
                    operations = push(operations, input_string[input_index]);  // пихаем операцию в стек
                else {
                    while ((operations != NULL) &&
                           (priority(operations->c) >= priority(input_string[input_index])))
                        output_string[output_index++] =
                            delete_element(&operations);  // записываем в стpоку все опеpации с большим или
                                                          // pавным пpиоpитетом
                    operations = push(operations,
                                      input_string[input_index]);  // записываем в стек поступившую опеpацию
                }
            }
        }
        if (input_string[input_index] == '+' || input_string[input_index] == '/' ||
            input_string[input_index] == '*') {  // если какая-то операция
            if (operations == NULL)              // и стек пустой
                operations = push(operations, input_string[input_index]);  // в стек пихаем операцию
            else if (priority(operations->c) <
                     priority(
                         input_string[input_index]))  // если эта опеpация сильнее опеpации на веpшине стека
                operations = push(operations, input_string[input_index]);  // пихаем операцию в стек
            else {
                while ((operations != NULL) &&
                       (priority(operations->c) >= priority(input_string[input_index])))
                    output_string[output_index++] = delete_element(
                        &operations);  // записываем в стpоку все опеpации с большим или pавным пpиоpитетом
                operations =
                    push(operations, input_string[input_index]);  // записываем в стек поступившую опеpацию
            }
        }
        input_index++;  // переходим на след символ входной стpоки
    }
    while (operations != NULL)  // после того как мы просмотрели всю строку
        output_string[output_index++] =
            delete_element(&operations);  // Пеpеписываем все опеpации из стека в выходную стpоку
    output_string[output_index] = '\0';
    return output_string;
}

struct st* push(struct st* HEAD, char chr) {  //кладём в стек (старая вершина-HEAD новая - new)
    struct st* new;
    new = malloc(sizeof(struct st));
    new->c = chr;
    new->next = HEAD;  //включаем в стек
    return new;        //возврат новой вершины
}

char delete_element(struct st** HEAD)  // УДАЛЯЕТ СИМВОЛ ИЗ СТЕКА И ВОЗВРАЩАЕТ ЕГО
{
    struct st* new;
    char deleting;
    if (*HEAD == NULL) return '\0';  // СТЕК ПУСТОЙ - ВЕРНЕТ ПУСТУЮ СТРОКУ
    new = *HEAD;                     // ВЕРШИНА
    deleting = new->c;
    *HEAD = new->next;  //МЕНЯЮ АДРЕС ВЕРШИНЫ
    free(new);
    return deleting;
}

int priority(char chr)  // ВОЗВРАТ ПРИОРИТЕТОВ ОПЕРАЦИЙ
{
    int t = 0;
    if (chr == 's' || chr == 'c' || chr == 't' || chr == 'g' || chr == 'q' || chr == 'l' || chr == '~') {
        t = 4;
    } else if (chr == '*' || chr == '/') {
        t = 3;
    } else if (chr == '-' || chr == '+') {
        t = 2;
    } else if (chr == '(') {
        t = 1;
    }

    return t;
}