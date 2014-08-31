Const finame='';
      foname='';
      MaxN=10000000000;
Type Mg1 = array[0..2000000] of longint;
Var fi, fo:text;
    i, j, n, m, w, v, l1, l2:longint;
    max: int64;
    w1, w2, v1, v2, lmax: Mg1;

procedure Qsort(l, r: longint; var a, b: Mg1);
var i,j,x,y: longint;
begin
    i := l; j := r;
    x := a[(l + r) div 2];
    repeat
        while (a[i] < x) do inc(i);
        while (x < a[j]) do dec(j);
        if (i <= j) then
        begin
            y := a[i]; a[i] := a[j]; a[j] := y;
            y := b[i]; b[i] := b[j]; b[j] := y;
            inc(i); dec(j);
        end;
    until (i > j);
    if (l<j) then Qsort(l,j,a,b);
    if (i<r) then Qsort(i,r,a,b);
end;

Function tmax(a,b:int64):int64;
Begin
    if (a > b) then
        tmax := a
    else
        tmax := b;
end;

Procedure init;
Begin
    l1 := 1; l2 := 1;
    for i := 1 to n div 2 do
    begin
        read(fi, w, v);
        for j := 1 to l1 do
        Begin
            w1[l1 + j] := w1[j] + w;
            v1[l1 + j] := v1[j] + v;
        end;
        l1 := l1 * 2;
    end;
    for i := 1 to (n + 1) div 2 do
    begin
        read(fi, w, v);
        for j := 1 to l2 do
        Begin
            w2[l2 + j] := w2[j] + w;
            v2[l2 + j] := v2[j] + v;
        end;
        l2 := l2 * 2;
    end;
end;

Procedure solve;
Begin
    Qsort(1,l1, w1, v1); Qsort(1,l2, w2, v2);
    lmax[0] := -2147483648;
    For i := 1 to l2 do
        lmax[i] := tmax(lmax[i - 1], v2[i]);
    j := l2; max := -maxn;
    for i:=1 to l1 do
    Begin
        While (j >= 1) and (w1[i] + w2[j] > m) do dec(j);
        if j = 0 then
            break;
        max := tmax(max,lmax[j] + v1[i]);
    end;
end;

BEGIN
    Assign(fi, finame); reset(fi); readln(fi, n, m);
    Assign(fo, foname); rewrite(fo);
    init;
    solve;
    Writeln(fo, max);
    close(fi); close(fo);
END.
