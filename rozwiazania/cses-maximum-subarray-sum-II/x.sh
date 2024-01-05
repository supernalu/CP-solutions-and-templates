g++ x.cpp -o x.exe
for var in "$@"
do 
    echo "INPUT:" in/"$var"
    cat in/"$var"
    echo ""
    echo ""
    echo "OUTPUT:" in/"$var"
    ./x.exe < in/"$var"
    echo ""
done
