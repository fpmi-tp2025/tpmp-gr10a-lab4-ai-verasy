# Скачиваем Catch2 автоматически
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(test_database test_database.cpp)
target_link_libraries(test_database
    database_lib
    SQLite::SQLite3
    Catch2::Catch2WithMain  # Автоматически подключит заголовки
)
