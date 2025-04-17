#include "furs.h"
#include "database.h"
#include <stdio.h>
#include <stdlib.h>

void manage_furs() {
    int choice;
    do {
        printf("\n=== Управление пушниной ===\n");
        printf("1. Добавить пушнину\n");
        printf("2. Список пушнины\n");
        printf("0. Назад\n");
        printf("Выберите: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_fur(); break;
            case 2: list_furs(); break;
            case 0: break;
            default: printf("Неверный выбор!\n");
        }
    } while (choice != 0);
}

void add_fur() {
    Fur fur;
    printf("ID зверофермы: ");
    scanf("%d", &fur.farm_id);
    printf("Название меха: ");
    scanf(" %49[^\n]", fur.name);
    printf("Сорт (1-3): ");
    scanf("%d", &fur.grade);
    printf("Количество: ");
    scanf("%d", &fur.quantity);
    printf("Заявленная цена: ");
    scanf("%f", &fur.asking_price);

    char sql[256];
    sprintf(sql, "INSERT INTO furs (farm_id, name, grade, quantity, asking_price) "
                "VALUES (%d, '%s', %d, %d, %.2f);",
            fur.farm_id, fur.name, fur.grade, fur.quantity, fur.asking_price);

    if (execute_sql(sql, NULL)) {
        printf("Пушнина успешно добавлена!\n");
    }
}
