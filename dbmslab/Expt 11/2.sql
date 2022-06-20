set serveroutput on

DECLARE
mark INTEGER;
BEGIN
    mark := 53;
 
    DBMS_OUTPUT.put('The Grade Corresponding to '|| mark || ' is: ');
    IF (mark >= 90) THEN
        DBMS_OUTPUT.put_line('A+');
    ELSIF (mark >= 80) THEN
        DBMS_OUTPUT.put_line('A');
    ELSIF (mark >= 70) THEN
        DBMS_OUTPUT.put_line('B+');
    ELSIF (mark >= 60) THEN
        DBMS_OUTPUT.put_line('B');
    ELSIF (mark >= 50) THEN
        DBMS_OUTPUT.put_line('C+');
    ELSIF (mark >= 40) THEN
        DBMS_OUTPUT.put_line('C');
    ELSE
        DBMS_OUTPUT.put_line('D');
    END IF;
END;
/