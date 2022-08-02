# Write your MySQL query statement below
Select stock_name,sum(
    CASE 
    WHEN operation="BUY" THEN (-price)
    ELSE price
    END
)   AS "capital_gain_loss"
from Stocks
group by stock_name;