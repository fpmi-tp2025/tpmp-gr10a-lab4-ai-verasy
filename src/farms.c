#include "farms.h"
#include "database.h"
#include <stdio.h>
#include <stdlib.h>

void manage_farms() {
    int choice;
    do {
        printf("\n=== Управление зверофермами ===\n");
        printf("1. Добавить звероферму\n");
        printf("2. Список звероферм\n");
        printf("0. Назад\n");
        printf("Выберите: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_farm(); break;
            case 2: list_farms(); break;
            case 0: break;
            default: printf("Неверный выбор!\n");
        }
    } while (choice != 0);
}

void add_farm() {
    Farm farm;
    printf("Номер зверофермы: ");
    scanf("%d", &farm.id);
    printf("Адрес: ");
    scanf(" %99[^\n]", farm.address);
    printf("Директор: ");
    scanf(" %49[^\n]", farm.director);
    printf("Телефон: ");
    scanf(" %19[^\n]", farm.phone);

    char sql[256];
    sprintf(sql, "INSERT INTO farms VALUES (%d, '%s', '%s', '%s');",
            farm.id, farm.address, farm.director, farm.phone);

    if (execute_sql(sql, NULL)) {
        printf("Звероферма успешно добавлена!\n");
    }
}
