g++ gen.cpp -o gen.exe
g++ brut.cpp -o brut.exe
g++ x.cpp -o x.exe

for ((i = 1; ; ++i))
{
    ./gen.exe > test.in

    diff -w <(./brut.exe < test.in) <(./x.exe < test.in) || break

    echo "$i: OK"
}