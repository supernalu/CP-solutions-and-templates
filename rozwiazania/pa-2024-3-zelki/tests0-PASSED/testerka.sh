for ((i=1; i<=10000;i++)) {
    diff -w <(./x.exe < ${i}.in) ${i}.out || break

    echo TEST $i: OK
}
