#ifndef FURS_H
#define FURS_H

// Структура пушнины
typedef struct {
    int id;
    int farm_id;
    char name[50];
    int grade;
    int quantity;
    float asking_price;
} Fur;

// Основное меню работы с пушниной
void manage_furs();

// Добавление новой партии пушнины
void add_fur();

// Вывод списка всей пушнины
void list_furs();

// Поиск пушнины по ID
Fur* find_fur_by_id(int id);

#endif
