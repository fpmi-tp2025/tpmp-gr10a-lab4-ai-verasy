-- 1. Проверка существования таблиц
SELECT name FROM sqlite_master WHERE type='table' ORDER BY name;
-- 1. Звероферма с самой высокой ценой
SELECT f.* 
FROM farms f
JOIN fur_products fp ON f.id = fp.farm_id
JOIN auction_results ar ON fp.id = ar.fur_product_id
ORDER BY ar.final_price DESC
LIMIT 1;

-- 2. Статистика по покупателям
SELECT 
    buyer_category,
    SUM(sold_quantity) as total_quantity,
    SUM(sold_quantity * final_price) as total_sum
FROM auction_results
GROUP BY buyer_category;

-- 3. Прибыль по зверофермам
SELECT 
    f.id,
    f.director_name,
    SUM(ar.sold_quantity * (ar.final_price - fp.asking_price)) as profit
FROM farms f
JOIN fur_products fp ON f.id = fp.farm_id
JOIN auction_results ar ON fp.id = ar.fur_product_id
GROUP BY f.id;

-- 4. Фермы с ценой выше средней
SELECT f.*
FROM farms f
JOIN fur_products fp ON f.id = fp.farm_id
JOIN auction_results ar ON fp.id = ar.fur_product_id
WHERE ar.final_price > (SELECT AVG(final_price) FROM auction_results);

-- 5. Ферма с максимальной прибылью
SELECT 
    f.*,
    SUM(ar.sold_quantity) as total_sold,
    SUM(ar.sold_quantity * (ar.final_price - fp.asking_price)) as total_profit
FROM farms f
JOIN fur_products fp ON f.id = fp.farm_id
JOIN auction_results ar ON fp.id = ar.fur_product_id
GROUP BY f.id
ORDER BY total_profit DESC
LIMIT 1;
