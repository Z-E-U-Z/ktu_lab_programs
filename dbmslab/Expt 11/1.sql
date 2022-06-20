set serveroutput on

DECLARE
 
message VARCHAR2(20) := 'Hello World!';
 
BEGIN
  DBMS_OUTPUT.put_line(message);
END;
/