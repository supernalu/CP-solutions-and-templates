g++ wzor.cpp -o wzor.exe
g++ brut.cpp -o brut.exe
g++ gen.cpp -o gen.exe

for ((i=1; ;++i)) {
    ./gen.exe > in.txt
    ./wzor.exe < in.txt > out.txt
    ./brut.exe < in.txt > ok.txt
    diff -w out.txt ok.txt || break
    echo "TEST $i: OK"
}