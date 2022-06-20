--create table test with attributes num and sum

set serveroutput on

DECLARE
  x NUMBER;
  n NUMBER;
  i NUMBER;
  sums NUMBER;
 
FUNCTION findsum(i NUMBER)
RETURN NUMBER IS SUM NUMBER;
BEGIN
  sums:=((i*(i+1))/2);
  RETURN sums;
END;
 
BEGIN
 n:=&n;
 FOR i IN 1..n LOOP
   sums:=findsum(i);
   INSERT INTO test VALUES(i,sums);
 END LOOP;
END;
/