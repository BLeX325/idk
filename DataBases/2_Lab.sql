-- создаем таблицу SUPPLIER
CREATE TABLE SUPPLIER 
(
SNO INTEGER PRIMARY KEY,
SNAME VARCHAR(20) NOT NULL,
CITY VARCHAR(20));
-- создаем таблицу PART
CREATE TABLE PART
(
PNO INTEGER PRIMARY KEY,
PNAME VARCHAR(20) NOT NULL,
PRICE INTEGER CHECK (PRICE>0),
COLOR VARCHAR(20) NOT NULL,
WEIGHT REAL NOT NULL);
-- создаем таблицу SELLS 
CREATE TABLE SELLS
(
sells_id INTEGER PRIMARY KEY,
SNO INTEGER REFERENCES SUPPLIER(SNO) ON DELETE CASCADE ,
PNO INTEGER REFERENCES PART(PNO) ON DELETE CASCADE
);
 
-- помещаем значения в таблицу SUPPLIER
INSERT INTO SUPPLIER VALUES (1, 'Smith', 'London');
INSERT INTO SUPPLIER VALUES (2, 'Jones', 'Paris');
INSERT INTO SUPPLIER VALUES (3, 'Adams', 'Vienna');
INSERT INTO SUPPLIER VALUES (4, 'Blake', 'Rome');
-- помещаем значения в таблицу PART
INSERT INTO PART VALUES (1, 'Screw', '10', 'R', '2');
INSERT INTO PART VALUES (2, 'Nut', '8', 'G', '4');
INSERT INTO PART VALUES (3, 'Bolt', '15', 'B', '5');
INSERT INTO PART VALUES (4, 'Cam', '25', 'R', '3' );
INSERT INTO PART VALUES (5, 'Bearing', '40', 'B', '7');
-- помещаем значения в таблицу SELLS
INSERT INTO SELLS VALUES (1, 1, 1);
INSERT INTO SELLS VALUES (2, 1, 2);
INSERT INTO SELLS VALUES (3, 2, 4);
INSERT INTO SELLS VALUES (4, 3, 1);
INSERT INTO SELLS VALUES (5, 3, 3);
INSERT INTO SELLS VALUES (6, 3, 5);
INSERT INTO SELLS VALUES (7, 4, 2);
INSERT INTO SELLS VALUES (8, 4, 3);
INSERT INTO SELLS VALUES (9, 4, 4);
INSERT INTO SELLS VALUES (10, 2, 5);
 
-- Ex.2 DATA BASES:
-- 1)
UPDATE PART SET PRICE = 31 WHERE PNAME = 'Cam';
-- 2)
UPDATE PART SET PRICE = 13 WHERE PNAME = 'Nut';
UPDATE PART SET COLOR = 'B' WHERE PNAME = 'Nut';
-- 3)
UPDATE SUPPLIER SET SNAME = 'William' WHERE CITY = 'Paris';
-- 4)
DELETE FROM PART WHERE PNAME = 'Bearing';
-- 5)
-- В таблице SELLS пропали строчки содержашие PNO = 5, который принадлежал товару с именем 'Bearing'
-- это происходит из-за отношения предок / потомок которое было установлено посредством внешнего ключа
-- 6)
INSERT INTO SUPPLIER VALUES (5, 'Alex', 'Moskow');
-- 7)
DELETE FROM SUPPLIER WHERE SNAME = 'Alex';
-- 8)
ALTER TABLE SUPPLIER ADD COLUMN PHONE_NUMBERS INTEGER;
ALTER TABLE SUPPLIER ADD COLUMN CONTACT_PERSON VARCHAR(20);

UPDATE SUPPLIER SET PHONE_NUMBERS = 9173261830 WHERE SNO = 1;
UPDATE SUPPLIER SET PHONE_NUMBERS = 9174563040 WHERE SNO = 2;
UPDATE SUPPLIER SET PHONE_NUMBERS = 4443264530 WHERE SNO = 3;
UPDATE SUPPLIER SET PHONE_NUMBERS = 9173261890 WHERE SNO = 4;
UPDATE SUPPLIER SET CONTACT_PERSON = 'Will_Byers' WHERE SNO = 1;
UPDATE SUPPLIER SET CONTACT_PERSON = 'Mike_Willer' WHERE SNO = 2;
UPDATE SUPPLIER SET CONTACT_PERSON = 'Dustin_Henderson' WHERE SNO = 3;
UPDATE SUPPLIER SET CONTACT_PERSON = 'Lucas_Sinclair' WHERE SNO = 4;
-- 9)
ALTER TABLE SUPPLIER DROP COLUMN CONTACT_PERSON; 
-- 10)
ALTER TABLE SUPPLIER RENAME COLUMN PHONE_NUMBERS TO NUMBERS;
-- 11)
ALTER TABLE SUPPLIER ALTER COLUMN NUMBERS SET NOT NULL; 
-- 12)
ALTER TABLE part ALTER COLUMN color TYPE character varying (255);

-- Выводим результаты:
SELECT * FROM SUPPLIER;
-- SELECT * FROM PART;
-- SELECT * FROM SELLS;
