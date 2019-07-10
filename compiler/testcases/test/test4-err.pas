program HelloWorld(input, output);          
var i, j : integer;
begin
                        
    for i := 100 to 10 do j := i;     {循环范围错误}            

    k := 2;                           {使用未声明变量}

    if j then i := i + 1              {条件表达式错误}                                           
end.