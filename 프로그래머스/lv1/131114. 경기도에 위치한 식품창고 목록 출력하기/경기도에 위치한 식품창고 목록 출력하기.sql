SELECT WAREHOUSE_ID, WAREHOUSE_NAME, ADDRESS, IFNULL(FREEZER_YN,"N") FROM FOOD_WAREHOUSE
WHERE WAREHOUSE_NAME LIKE "창고_경기%";

# SELECT * FROM FOOD_WAREHOUSE;