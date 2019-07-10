program HelloWorld(input, output);          {head}
const a = 'a';                              {常量声明}
var i, j, k:integer;                        {变量声明}
function plus (i, j: integer) : integer;    {子程序声明}
begin   
    plus := i+j                             {变量以表达式赋值}
end;
begin
    read(j);                                {输入语句}
    for i := 1 to 10 do j := i;             {for循环语句}
    while j > 1 do                          {while循环语句}
        begin
        j := j - 1                          {复合语句}
        end;
    k := plus(i, j);                        {以函数赋值}
    write(i, j, k);                         {输出语句}
end.