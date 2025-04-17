## Лабораторная работа №4
Этот проект реализует консольное приложение для условного Бюро Туризма, с системой аутентификации персонала и возможностью формирования отчетов.


## Структура проекта
```bash
.
├── src/                  # Исходный код программы
├── includes/             # Заголовочные файлы
├── tests/                # Юнит-тесты (GoogleTest)
├── bin/                  # Скомпилированные бинарники
├── CMakeLists.txt        # Сборка проекта через CMake
└── .github/workflows/    # GitHub Actions CI
```

## Сборка и запуск
```bash
mkdir build
cd build
cmake ..
make
./bin/tourism_bureau       # Запуск приложения
./bin/tourism_tests        # Запуск тестов
```
## Зависимости
CMake >= 3.10

GCC / Clang

SQLite3 (libsqlite3-dev)

GoogleTest


