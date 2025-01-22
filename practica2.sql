/*
roblema 2
Tienes la siguiente tabla sobre pedidos y el status de cada uno.

TABLE NAME: PEDIDOS

ID  PRODUCT         STATUS          CLIENT
1   avatar book     ACCEPTED        Teodoro
2   laptop          INPROGRESS      Mayra
3   chocolates      ACCEPTED        Teodoro
4   cup package     DELIVERED       Teodoro
5   wallet          DELIVERED       Juan
6   hiking hat      ACCEPTED        Hector

Necesitamos
* una query en la que obtengas los pedidos hechos por Teodoro
* una query en la que obtengamos cuantos productos tenemos en cada status
*/

SELECT * FROM PEDIDOS WHERE CLIENT="Teodoro"
SELECT count(*), STATUS FROM PEDIDOS GROUP BY STATUS