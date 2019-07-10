program example(input,output);
var x,y:integer;a:char;b:array[0..9]of integer;
procedure exchange (i,j: integer);
begin
end;
procedure exchange (var i:integer);  {函数重复声明}
begin
end;

begin                             
x:= 5;                             
y:= 6;
b[3] := 4;
exchange(y,x,y);                     {参数维数不匹配}
if x>=y
then x:=3;
end.
