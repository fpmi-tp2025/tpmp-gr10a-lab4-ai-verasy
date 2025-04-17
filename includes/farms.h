#ifndef FARMS_H
#define FARMS_H

// Структура зверофермы
typedef struct {
    int id;
    char address[100];
    char director[50];
    char phone[20];
} Farm;

// Основное меню работы с зверофермами
void manage_farms();

// Добавление новой зверофермы
void add_farm();

// Вывод списка всех звероферм
void list_farms();

// Поиск зверофермы по ID
Farm* find_farm_by_id(int id);

#endif
