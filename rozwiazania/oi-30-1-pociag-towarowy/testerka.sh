for ((i=1; i<2;i++)) {
    diff -w <(./x.exe < ${i}.in) ${i}.out || break

    echo TEST $i: OK
}

