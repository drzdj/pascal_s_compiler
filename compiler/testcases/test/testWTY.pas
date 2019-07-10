program swapprogram(input, output);
    const a = 1;b = 2;d = 0.1;
    var x,y,m,n:integer;z:real;arr: array [1..4,1..5] of integer;
    
    procedure swap(var a,b:integer);
        var t:integer;
        begin
            t:=a;
		a:=b;
		b:=t;
	  end;

    function sum(var a,b:integer):integer;
	  begin
            sum:=a+b;
        end;   

    begin
	  z:=0.1;

	  x:=a div z; {error"type error!"}
        x:=a div z; {error"type error!"}
        x:=a/0; {error"/0";}

        if(a=z)  then z:=0.2;   {error"The expression type should be same on both sides."}
	  
        arr[1]:=1; {error"array dimenssion error!"}

        write(x);
        write(y);
	  swap(x,y);
        swap(x,y,m); {error"DIMENSION ERROR!"}
	  swaaap(x,y); {error"id swaaap doesn't exist"}
        a(x,y); {error"id:a is not a procedure"}
	  swap(x,z); {error"parameters don't match!"}

        x:=x+sum(x,y); 
        x:=x+sum(x,y,m); {error"DIMENSION_ERROR!"}
        x:=x+suuum(x,y); {error"id suuum doesn't exist."}
        x:=x+a(x,y); {error"addop is wrong""a is not a procedure"}
        x:=x+sum(x,z); {error"parameters don't match!"}

        if(a>b)then x:=1;
        if(a=b)then x:=1;
	  if(a=b) and (a>b) then x:=1;
    end.