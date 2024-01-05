for ((i=1; i<=200;i++)) {
    diff -w <(./x.exe < ${i}.in) ${i}.out || break

    echo TEST $i: OK
}

