set serveroutput on

DECLARE
    fact INTEGER;
    n INTEGER;
    temp INTEGER;
BEGIN
  fact := 1;
  n := &n;
  temp := n;
  WHILE(n > 0) LOOP
    fact := fact * n;
    n := n - 1;
  END LOOP;
  DBMS_OUTPUT.put_line('Factorial is ' ||fact);
END;
/