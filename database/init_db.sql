-- Created by Vertabelo (http://vertabelo.com)
-- Last modification date: 2025-04-07 12:44:05.834

-- tables
-- Table: auction_results
CREATE TABLE auction_results (
    id integer NOT NULL CONSTRAINT auction_results_pk PRIMARY KEY AUTOINCREMENT,
    sold_quantity integer NOT NULL,
    final_price real NOT NULL,
    buyer_category text NOT NULL,
    fur_products_id integer NOT NULL,
    CONSTRAINT auction_results_fur_products FOREIGN KEY (fur_products_id)
    REFERENCES fur_products (id)
);

-- Table: farms
CREATE TABLE farms (
    id integer NOT NULL CONSTRAINT farms_pk PRIMARY KEY AUTOINCREMENT,
    address text NOT NULL,
    director_name TEXT NOT NULL,
    phone TEXT NOT NULL
);

-- Table: fur_products
CREATE TABLE fur_products (
    id integer NOT NULL CONSTRAINT fur_products_pk PRIMARY KEY AUTOINCREMENT,
    farms_id integer NOT NULL,
    fur_type text NOT NULL,
    grade text NOT NULL,
    quantity integer NOT NULL,
    asking_price real NOT NULL,
    CONSTRAINT fur_products_farms FOREIGN KEY (farms_id)
    REFERENCES farms (id)
);


-- Тестовые данные для ферм
INSERT INTO farms (address, director_name, phone) VALUES
('с. Листвянка, ул. Звероводческая, 15', 'Иванов П.С.', '+79151234567'),
('г. Братск, ш. Меховое, 42', 'Петрова А.К.', '+79027654321'),
('п. Култук, пер. Норковый, 3', 'Сидоров В.М.', '+79501231234');

-- Тестовые данные для пушнины
INSERT INTO fur_products (farm_id, fur_type, grade, quantity, asking_price) VALUES
(1, 'норка', 'A', 150, 2500.50),
(1, 'песец', 'B', 80, 1800.75),
(2, 'соболь', 'AA', 50, 3200.00),
(3, 'лиса', 'C', 120, 1500.25);

-- Результаты аукциона
INSERT INTO auction_results (fur_product_id, sold_quantity, final_price, buyer_category) VALUES
(1, 120, 2700.00, 'меховая фабрика'),
(2, 75, 1750.50, 'ателье'),
(3, 45, 3400.75, 'частное лицо'),
(4, 100, 1450.00, 'меховая фабрика');
-- End of file.

