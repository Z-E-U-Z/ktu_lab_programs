-- insert into test values(10,1200);

set serveroutput on

DECLARE
    cid INTEGER;
    n INTEGER;
    emi INTEGER;
BEGIN
  cid := &cid;
  SELECT COUNT(*)
    INTO n
    FROM test
   WHERE id = cid;
 
   IF (n = 1) THEN
    UPDATE test SET emi = emi * 0.5 WHERE id = cid;
    SELECT emi
      INTO emi
      FROM test
     WHERE id = cid;
    DBMS_OUTPUT.put_line('EMI Upadated for cid '|| cid || ' from ' || emi * 2 || ' to ' || emi);
   ELSE
    DBMS_OUTPUT.put_line('Record Matching Id ' || cid || ' Absent');
   END IF;
 
END;
/

-- select * from test;