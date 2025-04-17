#include <stdio.h>
#include <stdlib.h>
#include "auth.h"
#include "database.h"
#include "farms.h"
#include "furs.h"
#include "auctions.h"

int main() {
    if (!authenticate()) {
        printf("Ошибка аутентификации\n");
        return 1;
    }

    init_database();

    int choice;
    do {
        printf("\nМеню:\n");
        printf("1. Управление зверофермами\n");
        printf("2. Управление пушниной\n");
        printf("3. Результаты аукционов\n");
        printf("4. Отчеты\n");
        printf("0. Выход\n");
        printf("Выберите: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: manage_farms(); break;
            case 2: manage_furs(); break;
            case 3: manage_auctions(); break;
            case 4: generate_reports(); break;
            case 0: break;
            default: printf("Неверный выбор\n");
        }
    } while(choice != 0);

    close_database();
    return 0;
}
