set serveroutput on

DECLARE 
    i INTEGER;
BEGIN
  i := 0;
  LOOP
    IF(i > 10) THEN
        EXIT;
    END IF;
    DBMS_OUTPUT.put_line('3 x '|| i || ' = '|| 3 * i);
    i := i + 1;
  END LOOP;
END;
/