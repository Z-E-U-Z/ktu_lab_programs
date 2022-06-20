-- drop table result;  
-- create table result(id int primary key,odd int,even int);

set serveroutput on

DECLARE
    TYPE arr IS varray(5) OF INTEGER;
    odd arr;
    even arr;
BEGIN
    odd := arr();
    even := arr();
    FOR i IN 1..10 LOOP
        IF (MOD(i,2) = 0) THEN
            even.extend;
            even(even.LAST):= i;
        ELSE
            odd.extend;
            odd(odd.LAST) := i;
        END IF;
    END LOOP;
    FOR i IN 1..odd.COUNT LOOP
        INSERT INTO result (id,odd) VALUES ( i , odd(i));
    END LOOP;
    FOR i IN 1..even.COUNT LOOP
        UPDATE result SET even =  even(i) WHERE id = i;
    END LOOP;
END;
/
-- select * from result;