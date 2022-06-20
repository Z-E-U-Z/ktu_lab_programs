-- drop table result;  
-- create table result(num int primary key,square int,cube int);

set serveroutput on

BEGIN
    FOR i IN 1..10 LOOP
        INSERT INTO result VALUES ( i , i*i, i*i*i);
    END LOOP;
END;
/
-- select * from result;