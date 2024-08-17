#ifndef POLISH_CALCULATING
#define POLISH_CALCULATING

// ВСЕ ДЛЯ РАСЧЕТА ПО ПОЛЬСКОЙ НОТАЦИИ

typedef struct NUMBERS {
    double num;             //числа
    struct NUMBERS *point;  //указатель
} NUMBERS;

typedef struct HEAD {
    struct NUMBERS *point;  //указатель на последний элемент в стеке
} HEAD;

void calculate_coordinates_in_polish(char **matrix, char *expression);
double calculate(char *output_string, HEAD *head, double x);
void define_stack(HEAD *head);
void pushing(double num, HEAD *head);
double pop(HEAD *head);
void calculate_coordinates(char **graph, int height, int width, char *output_string, HEAD *head);

#endif