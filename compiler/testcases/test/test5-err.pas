program example(input, output);{right example1}

    var a: array [1..10] of integer;
        b: array [20..1, 1..30, 31..40] of char; {wrong place  period范围小于0}

    procedure MyProcedure1;
        var i: integer;
            j: integer;
    begin
        for i:= 1 to 9 do read(a[i]);
    end;
        
    begin
        MyProcedure1;
    end.{end}