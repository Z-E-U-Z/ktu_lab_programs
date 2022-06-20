set serveroutput on

DECLARE
    binary NUMBER;
    dec    NUMBER;
    temp   NUMBER;
    i NUMBER;
    y NUMBER;
   
 
    PROCEDURE convert_bin_dec(x IN NUMBER, dec OUT NUMBER) IS
    BEGIN
        i := 0;
        dec := 0;
        temp := x;
        WHILE (temp != 0)
            LOOP
                y := MOD(temp, 10);
                temp := FLOOR(temp / 10);
                dec:=dec+ y * POWER(2, i);
                i:=i+1;
            END LOOP;
    END;
 
BEGIN
    binary := &binary;
    convert_bin_dec(binary, dec);
    DBMS_OUTPUT.PUT_LINE('DECIMAL EQUIVALENT OF ' || binary || ' is ' || dec);
END;
/