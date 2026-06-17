/* Write your T-SQL query statement below */
SELECT 
        product_name,
        SUM(unit) AS unit
FROM Products AS P
INNER JOIN Orders AS O
ON P.product_id=O.product_id
WHERE order_date>='2020-02-01' AND order_date<'2020-03-01'
GROUP BY product_name
HAVING SUM(unit)>=100;
