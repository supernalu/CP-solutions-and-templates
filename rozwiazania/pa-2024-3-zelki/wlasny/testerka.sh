for ((i=1; i<=10000;i++)) {
    diff -w <(./x.exe < zel${i}.in) zel${i}.out || break

    echo TEST $i: OK
}
