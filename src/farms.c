#include "farms.h"
#include "database.h"
#include <stdio.h>
#include <stdlib.h>

void manage_farms() {
    int choice;
    do {
        printf("\nУправление зверофермами:\n");
        printf("1. Добавить звероферму\n");
        printf("2. Список звероферм\n");
        printf("0. Назад\n");
        printf("Выберите: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: add_farm(); break;
            case 2: list_farms(); break;
            case 0: break;
            default: printf("Неверный выбор\n");
        }
    } while(choice != 0);
}

void add_farm() {
    Farm farm;
    printf("Номер зверофермы: ");
    scanf("%d", &farm.id);
    printf("Адрес: ");
    scanf(" %[^\n]", farm.address);
    printf("Директор: ");
    scanf(" %[^\n]", farm.director);
    printf("Телефон: ");
    scanf(" %[^\n]", farm.phone);

    char sql[500];
    sprintf(sql, "INSERT INTO farms (id, address, director, phone) VALUES (%d, '%s', '%s', '%s');",
            farm.id, farm.address, farm.director, farm.phone);

    if (execute_sql(sql, NULL)) {
        printf("Звероферма добавлена успешно\n");
    }
}

void list_farms() {
    char *sql = "SELECT id, address, director, phone FROM farms;";
    execute_sql(sql, print_farms_callback);
}

int print_farms_callback(void *data, int argc, char **argv, char **colNames) {
    printf("\nЗвероферма #%s\n", argv[0]);
    printf("Адрес: %s\n", argv[1]);
    printf("Директор: %s\n", argv[2]);
    printf("Телефон: %s\n", argv[3]);
    return 0;
}

Farm* find_farm_by_id(int id) {
    // Реализация поиска зверофермы по ID
    return NULL;
}
