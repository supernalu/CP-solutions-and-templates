#!/bin/bash

g++ -std=c++17 -O2 -Wall -Wextra -Wshadow {$1}.cpp -o {$1}.exe

./{$1}.exe < in > out