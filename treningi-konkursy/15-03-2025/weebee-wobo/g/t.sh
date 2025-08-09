export CXXFLAGS="-std=c++17 -Wall -Wextra -pedantic -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -DDEBUG"

make w
for i in {0..5}; {
    [ -s "$i.in" ] && (
        ./w < $i.in > $i.out;
        diff -w $i.out $i.ok && echo "$i OK" || echo "$i WRONG"
    )
}

[ $# -eq 0 ] || (
    make {g,b}
    for ((i=1;;++i)) {
        ./g > in
        ./b < in > ok
        ./w < in > out
        diff -w out ok || break
        echo TEST $i: OK 
    }
)