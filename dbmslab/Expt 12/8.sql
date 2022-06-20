set serveroutput on

DECLARE
  n NUMBER;
  s NUMBER;
  r NUMBER;
  len NUMBER;
  temp NUMBER;
  res NUMBER;
 
FUNCTION armstrong(n NUMBER)
RETURN NUMBER IS res NUMBER;
BEGIN
   s:=0;
   temp := n;
   len := LENGTH(TO_CHAR(temp));
   WHILE(temp>0) LOOP
       r := MOD(temp,10);
       s := s+POWER(r,len);
       temp := TRUNC(temp/10);
   END LOOP;
   IF(n=s) THEN
      res:=1;
   ELSE
      res:=0;
   END IF;
   RETURN res;
END;
 
BEGIN
  n:=&n;
  res:=armstrong(n);
  IF(res=1) THEN
    DBMS_OUTPUT.put_line('Yes,The number ' ||n|| ' is an Armstrong number');
  ELSE
    DBMS_OUTPUT.put_line('No,The number ' ||n|| ' is NOT an Armstrong number');
  END IF;
END;
/