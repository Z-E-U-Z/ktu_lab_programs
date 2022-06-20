set serveroutput on

DECLARE
     TYPE arr IS varray(5) OF INTEGER;
     marks1 arr;
     marks2 arr;
     no_of_students INTEGER;
BEGIN
  marks1 := arr(20,30,40,50,60);
  marks2 := arr(30,40,50,60,70);
  no_of_students := marks1.COUNT;
 
  FOR i IN 1..no_of_students LOOP
    DBMS_OUTPUT.put_line(marks1(i) + marks2(i));
  END LOOP;
END;
/