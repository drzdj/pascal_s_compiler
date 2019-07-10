program swapprogram(input, output);
    const a = 1;b = 2;d = 0.1;
    var x,y:integer;z:real;arr: array [1..4,1..5] of integer;

    begin
	  z:=0.1;

	  x:=a div z; {error"type error!"}
        x:=a div z; {error"type error!"}
        x:=a/0; {error"/0";}

        if(a=z)  then z:=0.2;   {error"The expression type should be same on both sides."}
	  
        arr[1]:=1; {error"array dimenssion error!"}

        write(x);
        write(y);
    end.