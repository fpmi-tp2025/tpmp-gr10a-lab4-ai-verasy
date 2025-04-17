#ifndef AUCTIONS_H
#define AUCTIONS_H

// Структура результатов аукциона
typedef struct {
    int id;
    int fur_id;
    int sold_quantity;
    float sale_price;
    char buyer_category[20];  // "фабрика", "ателье", "частное лицо"
} AuctionResult;

// Основное меню работы с аукционами
void manage_auctions();

// Добавление результата аукциона
void add_auction_result();

// Проверка корректности данных аукциона
int validate_auction_data(const AuctionResult *result);

// Генерация отчётов
void generate_reports();

#endif
