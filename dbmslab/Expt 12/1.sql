set serveroutput on

DECLARE
    a NUMBER;
    b NUMBER;
    c NUMBER;
 
    PROCEDURE findMin(x IN NUMBER, y IN NUMBER, z OUT NUMBER) IS
    BEGIN
        IF x < y THEN
            z := x;
        ELSE
            z := y;
        END IF;
    END;
 
BEGIN
    a := &a;
    b := &b;
    findMin(a, b, c);
    DBMS_OUTPUT.PUT_LINE('MIN VALUE(' || a || ',' || b || '): ' || c);
END;
/