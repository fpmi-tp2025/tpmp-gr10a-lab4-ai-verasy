#include "auctions.h"
#include "database.h"
#include <stdio.h>
#include <string.h>

void manage_auctions() {
    int choice;
    do {
        printf("\n=== Управление аукционами ===\n");
        printf("1. Добавить результат аукциона\n");
        printf("2. Сгенерировать отчёты\n");
        printf("0. Назад\n");
        printf("Выберите: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_auction_result(); break;
            case 2: generate_reports(); break;
            case 0: break;
            default: printf("Неверный выбор!\n");
        }
    } while (choice != 0);
}

void add_auction_result() {
    AuctionResult result;
    printf("ID пушнины: ");
    scanf("%d", &result.fur_id);
    printf("Проданное количество: ");
    scanf("%d", &result.sold_quantity);
    printf("Цена продажи: ");
    scanf("%f", &result.sale_price);
    printf("Категория покупателя (фабрика/ателье/частное лицо): ");
    scanf(" %19[^\n]", result.buyer_category);

    if (!validate_auction_data(&result)) {
        printf("Ошибка: некорректные данные!\n");
        return;
    }

    char sql[256];
    sprintf(sql, "INSERT INTO auction_results (fur_id, sold_quantity, sale_price, buyer_category) "
                "VALUES (%d, %d, %.2f, '%s');",
            result.fur_id, result.sold_quantity, result.sale_price, result.buyer_category);

    if (execute_sql(sql, NULL)) {
        printf("Результат аукциона успешно добавлен!\n");
    }
}
