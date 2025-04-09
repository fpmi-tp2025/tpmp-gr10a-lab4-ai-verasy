include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

# Создаем отдельную библиотеку для database.c
add_library(database_objects OBJECT ../src/database.c)
target_include_directories(database_objects PRIVATE ../includes)

# Основной тестовый исполняемый файл
add_executable(test_database 
    test_database.cpp
    $<TARGET_OBJECTS:database_objects>
)

# Настройки линковки
target_link_libraries(test_database
    PRIVATE
    SQLite::SQLite3
    Catch2::Catch2WithMain
)

# Отключаем coverage для Catch2
set_target_properties(Catch2 Catch2WithMain PROPERTIES 
    COMPILE_FLAGS ""
    LINK_FLAGS ""
)
