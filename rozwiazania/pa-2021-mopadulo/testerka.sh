for ((i=1; i<=1016;i++)) {
    diff -w <(./x.exe < ${i}.in) ${i}.out || break

    echo TEST $i: OK
}

