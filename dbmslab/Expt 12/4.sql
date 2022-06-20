--create table staff and insert values

set serveroutput on

DECLARE
    staff_id INTEGER;
    n INTEGER;
    salary INTEGER;
 
PROCEDURE incr_salary(staff_id IN INTEGER,n IN INTEGER) IS
BEGIN
  IF(n=1) THEN
    UPDATE staff SET salary = salary * 1.2 WHERE id = staff_id;
    SELECT salary INTO salary FROM staff WHERE id = staff_id;
    DBMS_OUTPUT.put_line('Salary Updated for staff_id '|| staff_id || ' from ' || salary / 1.2 || ' to ' || salary);
   ELSE
    DBMS_OUTPUT.put_line('Record Matching Id ' || staff_id || ' Absent');
   END IF;
END;
 
BEGIN
 staff_id := &staff_id;
 SELECT COUNT(*) INTO n FROM staff WHERE id=staff_id;
 incr_salary(staff_id,n);
END;
/