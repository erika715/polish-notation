#ifndef TRANSFORM_TO_POLISH
#define TRANSFORM_TO_POLISH

//ВСЕ ДЛЯ ПЕРЕВОДА В ПОЛЬСКУЮ НОТАЦИЮ
struct st {
    char c;
    struct st* next;
};

char* polish_translate(char* a, char* outstring);
struct st* push(struct st* HEAD, char a);
char delete_element(struct st** HEAD);
int priority(char a);

#endif