-- Добавляем зверофермы
INSERT INTO farms (id, address, director, phone) VALUES 
(1, 'с. Звероводское, ул. Центральная, 1', 'Иванов И.И.', '+79001234567'),
(2, 'п. Пушной, ул. Лесная, 5', 'Петров П.П.', '+79007654321');

-- Добавляем пушнину
INSERT INTO furs (farm_id, name, grade, quantity, asking_price) VALUES
(1, 'Норка', 1, 100, 5000),
(1, 'Лисица', 2, 50, 3000),
(2, 'Соболь', 1, 30, 8000);

-- Добавляем результаты аукциона
INSERT INTO auction_results (fur_id, sold_quantity, sale_price, buyer_category) VALUES
(1, 80, 5500, 'фабрика'),
(2, 40, 3200, 'ателье'),
(3, 25, 8500, 'частное лицо');
