for m in weebee-wobo; {
    mkdir -p $m/{a..n}
    for s in $m/{a..n}; {
        touch $s/{0..5}.{in,out,ok}
        cp t.cpp $s/w.cpp
        cp t.cpp $s/b.cpp
        cp t.cpp $s/g.cpp
        cp t.sh $s/t.sh
        cp h.sh $s/h.sh
    }
}