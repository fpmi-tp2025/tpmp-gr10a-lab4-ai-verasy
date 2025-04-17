#include "auth.h"
#include <stdio.h>
#include <string.h>

int authenticate() {
    char username[50];
    char password[50];
    
    printf("=== Аутентификация ===\n");
    printf("Логин: ");
    scanf("%49s", username);
    printf("Пароль: ");
    scanf("%49s", password);
    
    // Простейшая проверка (в реальном проекте нужно хэширование)
    if (strcmp(username, "admin") == 0 && strcmp(password, "12345") == 0) {
        printf("Успешный вход!\n");
        return 1;
    } else {
        printf("Ошибка: неверный логин или пароль.\n");
        return 0;
    }
}
