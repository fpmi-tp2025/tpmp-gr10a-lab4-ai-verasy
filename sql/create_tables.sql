-- Таблица звероферм
CREATE TABLE IF NOT EXISTS farms (
    id INTEGER PRIMARY KEY,
    address TEXT NOT NULL,
    director TEXT NOT NULL,
    phone TEXT NOT NULL
);

-- Таблица пушнины
CREATE TABLE IF NOT EXISTS furs (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    farm_id INTEGER NOT NULL,
    name TEXT NOT NULL,
    grade INTEGER NOT NULL CHECK (grade BETWEEN 1 AND 3),
    quantity INTEGER NOT NULL CHECK (quantity > 0),
    asking_price REAL NOT NULL CHECK (asking_price > 0),
    FOREIGN KEY (farm_id) REFERENCES farms(id)
);

-- Таблица результатов аукциона
CREATE TABLE IF NOT EXISTS auction_results (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    fur_id INTEGER NOT NULL,
    sold_quantity INTEGER NOT NULL CHECK (sold_quantity >= 0),
    sale_price REAL NOT NULL CHECK (sale_price > 0),
    buyer_category TEXT NOT NULL CHECK (buyer_category IN ('фабрика', 'ателье', 'частное лицо')),
    FOREIGN KEY (fur_id) REFERENCES furs(id)
);
