g++ -Wall -Wextra -Wno-sign-conversion -Wshadow brut.cpp -o brut.exe
g++ -Wall -Wextra -Wno-sign-conversion -Wshadow x.cpp -o x.exe
g++ -Wall -Wextra -Wno-sign-conversion -Wshadow gen.cpp -o gen.exe

for ((i=1; ;++i)) {
    ./gen.exe > in.txt
    diff -w <(./brut.exe < in.txt) <(./x.exe < in.txt) || break
    echo TEST $i: OK
}