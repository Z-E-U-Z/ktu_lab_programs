set serveroutput on

declare
    r number;
    a number;
    b number;
    h number;
    a1 number;
    b1 number;
    c1 number;
    r1 number;
    h1 number;

begin
    r := &radius;
    area.area_circle(r,a);
    dbms_output.put_line('Area of Circle of radius ' || r || ' is: ' || a || ' cm2');
    
    b := &base;
    h := &height;
    area.area_right_angled(b,h,a);
    dbms_output.put_line('Area of Right Angled Triangle of base ' || b || ' and height ' || h || ' is: ' || a || ' cm2');
    
    a1 := &side1;
    b1 := &side2;
    c1 := &side3;
    a := area.area_triangle(a1,b1,c1);
    dbms_output.put_line('Area of Triangle with sides ' || a1 || ', ' || b1 || ', ' || c1 || ' is: ' || ROUND(a,2) || ' cm2');
    
    r1 := &radius_cylinder;
    h1 := &height_cylinder;
    a := area.volume(r1,h1);
    dbms_output.put_line('Volume of Cylinder with radius ' || r1 || ' and height ' || h1 || ' is: ' || a || ' cm2');
end;
/
