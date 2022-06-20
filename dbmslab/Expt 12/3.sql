set serveroutput on

DECLARE
  A NUMBER;
  B NUMBER;
  C NUMBER;
  D NUMBER;
 
PROCEDURE root_quad(A IN NUMBER,B IN NUMBER,C IN NUMBER) IS
BEGIN
   D:= B*B-4*A*C;
   IF(D=0) THEN
    DBMS_OUTPUT.put_line('x = ' || (-B/2*A));
   ELSIF(D>0) THEN
    DBMS_OUTPUT.put_line('x1 = ' || (-B-SQRT(D))/2*A);
    DBMS_OUTPUT.put_line('x2 = ' || (-B+SQRT(D))/2*A);
   ELSE
    DBMS_OUTPUT.put_line('x1 = (' || (-B/2*A) || ', ' || (SQRT(-D)/2*A) || ')');
    DBMS_OUTPUT.put_line('x2 = (' || (-B/2*A) || ', ' || (-SQRT(-D)/2*A) || ')');
   END IF;
END;
   
 
BEGIN
  A:=&A;
  B:=&B;
  C:=&C;
  IF(A=0)THEN
    DBMS_OUTPUT.put_line('Not a quadratic equation.');
  ELSE
    root_quad(A,B,C);
  END IF;
END;
/