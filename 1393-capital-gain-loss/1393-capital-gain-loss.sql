select stock_name, sum(iif(operation='Sell',price,price*(-1))) as capital_gain_loss from stocks group by stock_name;