# Środowisko programisty (II etap OI)

Nasze środowisko składa się z kilku narzędzi. Wszystkie potrzebne są tutaj wymienione.

## Edytor kodu (VS Code)

**Dlaczego VS Code?**
* Bardzo prosty w obsłudze
* Dostępny na olimpiadzie
* Posiada wbudowany terminal 
* Duża i zaangażowana społeczność i pluginy, które pomagają w nauce i współpracy (np. Live Share).

**Instalacja i konfiguracja**
1. Pobrać według instrukcji na stronie https://code.visualstudio.com/
2. Po pobraniu zainstalować rozszerzenie C/C++ oraz Live Share

| Skrót klawiszowy | Efekt                                                       |
| ---------------- | ----------------------------------------------------------- |
| Ctrl + Shirt + ~ | Otwiera nowy terminal                                       |
| Tab              | Dodaje wcięcie na zaznaczonym obszarze                      |
| Shift + Tab      | Usuwa wcięcie na zaznaczonym obszarze                       |
| Ctrl + /         | Zakomentowuje/odkomentowuje zaznaczone linijki              |
| Shift + Alt + A  | Zakomentowuje/odkomentowuje zaznaczony obszar               |
| Ctrl + F         | Pokazuje GUI do znajdowania i zmianiania określonego tekstu |

Reszta potrzebnych skrótów jest analogiczna do innych narzędzi (Ctrl + C, Ctrl + V itp.)

## Język programowania (C++)

**Dlaczego C++?** 
 * Jest jednym z najbardziej wydajnych języków programowania
 * Dostępny na olimpiadzie
 * Jego biblioteka standardowa (algorytmy i struktury danych) jest bardzo rozbudowana i upraszcza sporą część pisania algorytmów
 * Duża i zaangażowana społeczność (zwłaszcza ta, która interesuje się programowaniem konkursowym)

**Ściągawka (dostępna na olimpiadzie):**
https://en.cppreference.com/w/
Głównie interesują nas w niej trzy sekcje:
 * Strings library
 * Containers library
 * Algorithms library

## Kompilator (G++)

**Dlaczego G++?**
* Jest kompilatorem używanym przez system automatycznego oceniania rozwiązań (SIO2)

**Instalacja i konfiguracja**
1. W bashu wykonać `sudo apt-get update`
2. W bashu wykonać `sudo apt install g++`

Kompilujemy w następujący sposób: `g++ <prog>.cpp`
Dodatkowo możemy kożystać z rozmaitych flag kompilacji.

| Flaga          | Efekt                                                                    |
| -------------- | ------------------------------------------------------------------------ |
| `-o <output>`  | Zmienia nazwę pliku wykonywalnego z `a.out` na `<output>`                |
| `-std=c++17`   | Zmienia standard C++, z jakiego korzysta kompilator na ten używany na OI |
| `-ggdb3`       | Kompilator zapisuje w programie dodatkowe informacje do debugowania      |
| `-Wall`        | Dołącza rekomendowane przez kompilator ostrzeżenia                       |
| `-Wextra`      | Dołącza dodatkowe ostrzeżenia                                            |
| `-Wconversion` | Dołącza jeszcze inne ostrzeżenia                                         |
| `-Wshadow`     | I jeszcze inne...                                                        |
| `-pedantic`    | To już ostatnie                                                          |

## Powłoka systemowa (Bash)

**Dlaczego Bash?**
* Jest to domyślna powłoka używana przez system Linux, czyli tym używanym na olimpiadzie
* Daje proste rozwiązania do instalacji aplikacji
* Jest to proste narzędzie do pisania skryptów, szczególnie takich, gdzie ważne jest łączenie ze sobą różnych programów

**Instalacja i konfiguracja**

Jeżeli jesteś użytkownikiem linuxa lub maca, to bash jest domyślną powłoką dostępną w aplikacji terminala na Twoim systemie.

Jeżeli jesteś użytkownikiem windowsa, to polecam skorzystać z WSL (https://www.ssl.com/how-to/enable-linux-subsystem-install-ubuntu-windows-10/). Jeżeli uda się zainstalować, to w visual studio code przy ikonce + w oknie terminala jest dropdown menu, gdzie możemy wybrać nasz nowo zainstalowany terminal linux i pracować na nim.

| Komenda                            | Efekt                                                                                    |
| ---------------------------------- | ---------------------------------------------------------------------------------------- |
| `man <program-name>`               | Pokazuje instrukcję obsługi programu `<program-name>`                                    |
| `cd <path>`                        | Przechodzi do innego miejsca w drzewie katalogów                                         |
| `ls -a`                            | Wypisuje wszystkie pliki i foldery dostępne w aktualnym miejscu                          |
| `cat <message>`                    | Wypisuje `<message>` na ekran                                                            |
| `mkdir <folder-name>`              | Tworzy nowy folder o nazwie `<folder-name>`                                              |
| `touch <file-name>`                | Tworzy nowy plik o nazwie `<file-name>`                                                  |
| `rm -rf <name>`                    | Usuwa plik lub folder o nazwie `<name>` z całą zawartością                               |
| `cp <path-a> <path-b>`             | Kopiuje folder lub plik `<path-a>` do miejsca `<path-b>`                                 |
| `mv <path-a> <path-b>`             | Przenosi folder lub plik `<path-a>` do miejsca `<path-b>`                                |
| `<program-a>` &#124; `<program-b>` | Łączy dwa programy: bierze wyjście `<program-a>` i daje je na wejście `<program-b>`      |
| `<program-file> > <program>`       | Podobne do powyższego, tylko to, co po lewej może być plikiem                            |
| `<program> < <program-file>`       | To samo, co powyżej, tylko w drugą stronę                                                |
| `<program-file> >> <file>`         | Dołącza na koniec pliku `<file>` wyjście programu (lub zawartość pliku) `<program-file>` |
| `diff -w <file-a> <file-b>`        | Porównuje zawartość dwóch plików (nie bierze pod uwagi różnic w znakach białych)         |


## System kontroli wersji (Git)

**Dlaczego Git?**
* Możemy dzięki niemu wspólnie pracować nad jednym folderem
* Ten folder ma zapisane wszystkie zmiany chronologicznie, czyli możemy sprawdzić stan folderu z dowolnej chwili jego istnienia

**Instalacja i konfiguracja**
1. Założyć konto na https://github.com/
2. W bashu wykonać `sudo apt-get update`
3. W bashu wykonać `sudo apt-get install git-all`
4. W bashu wykonać `ssh-keygen`, następnie skopiować plik `id_rsa.pub`, który został stworzony i dodać ten klucz SSH na profil na githubie https://github.com/settings/ssh/new
5. W bashu wykonać `git config --global user.name <username>`
6. W bashu wykonać `git config --global user.email <email>`

| Komenda                   | Efekt                                                         |
| ------------------------- | ------------------------------------------------------------- |
| `git add .`               | Dodaje wszystkie pliki z folderu do przestrzeni roboczej      |
| `git commit -m <message>` | Dodaje wszystkie pliki z przestrzeni roboczej do repozytorium |
| `git push`                | Wysyła aktualny stan repozytorium na GitHuba (chmura)         |
| `git pull`                | Pobiera aktualny stan repozytorium z GitHuba (chmura)         |

## Klasyczny debugger (GDB)

**Dlaczego GDB?**
* Dostępny na olimpiadzie
* Pomaga w znajdowaniu błędów (zwłaszcza takich z dużą ilością ifów lub rekurencją)
* Dzięki niemu możemy prześledzić działanie programu linijka po linijce bezbłędnie

**Instalacja i konfiguracja**
1. W bashu wykonać `sudo apt-get update`
2. W bashu wykonać `sudo apt-get install gdb`

| Komenda           | Efekt                                                                              |
| ----------------- | ---------------------------------------------------------------------------------- |
| `gdb ./<program>` | Wystartuj `gdb` na programie `<program>`                                           |
| `r`               | Skrót od run - Wystartuj program w `gdb`                                           |
| `b <line>`        | Skrót od break - Dodaj punkt stopu w linijce `<line>`                              |
| `p <expr>`        | Skrót od print - Wypisz na ekran wartość `<expr>`                                  |
| `bt`              | Sktót od backtrace - Wypisz na ekran stos wywołań funkcji                          |
| `c`               | Skrót od continue - Kontynuuj program do następnego punktu stopu                   |
| `s`               | Skrót od step - Kontynuuj program do następnego punktu stopu lub wywołania funkcji |
| `n`               | Skrót od next - Przejdź do kolejnej instrukcji                                     |
| `q`               | Skrót od quit - Wyjdź z programu `gdb`                                             |

## Debugger pamięci (Valgrind)

**Dlaczego Valgrind?**
* Dostępny na olimpiadzie
* Pomaga w znajdowaniu błędów wykonania (błędy powiązane ze złym zarządzaniem pamięcią)

**Instalacja i konfiguracja**
1. W bashu wykonać `sudo apt-get update`
2. W bashu wykonać `sudo apt-get install valgrind`

Żeby użyć valgrinda wystarczy uruchomić program valgrind z programem jako argument w ten sposób: `valgrind ./<program>`.

## Szkielety programów

wzor.cpp brut.cpp
```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
}
```

gen.cpp
```cpp
#include <bits/stdc++.h>

using namespace std;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);

// Zwraca liczbę całkowitą z przedziału <L, R>. Każda liczba ma taką samą szansę wystąpienia
long long randInt(long long L, long long R) {
    uniform_int_distribution<long long> dis(L, R);
    return dis(rng);
}

// Zwraca liczby naturalne z prawdopodobieństwem ważonym
// {40, 10, 10, 40}
// 0 generated 4028 times
// 1 generated 978 times
// 2 generated 1012 times
// 3 generated 3982 times
long long randWeightedInt(vector<int> weights) {
    discrete_distribution<> dis(weights.begin(), weights.end());
    return dis(rng);
}

// Zwraca liczbę rzeczywistą z przedziału <L, R>. Każda liczba ma taką samą szansę wystąpienia
long double randReal(long double L, long double R) {
    uniform_real_distribution<long double> dis(L, R);
    return dis(rng);
}

// Zwraca true z prawdopodobieństwem P, fałsz z prawdopodobieństwem 1 - P
bool randBool(long double P) {
    bernoulli_distribution dis(P);
    return dis(rng);
}

// Zwraca losową permutację liczb od 1 do N
vector<int> randPermutation(int N) {
    vector<int> permutation(N);
    for (int i = 0; i < N; ++i) {
        permutation[i] = i + 1;
    }
    shuffle(permutation.begin(), permutation.end(), rng);
    return permutation;
}

// Zwraca losowy ciąg N liczb od L do R
vector<long long> randSequence(int N, long long L, long long R) {
    vector<long long> sequence(N);
    for (int i = 0; i < N; ++i) {
        sequence[i] = randInt(L, R);
    }
    return sequence;
}

// Zwraca losowy ciąg N liczb od L do R (bez duplikatów)
vector<long long> randSequenceUnique(int N, long long L, long long R) {
    if (N > R - L + 1) {
        return vector<long long>();
    }
    vector<long long> sequence(R - L + 1);
    for (int i = L; i <= R; ++i) {
        sequence[i - L] = i;
    }
    shuffle(sequence.begin(), sequence.end(), rng);
    sequence.erase(sequence.begin() + N, sequence.end());
    return sequence;
}

// Zwraca losowy przedział mieszczący się w (L, R)
pair<long long, long long> randRange(long long L, long long R) {
    long long left = randInt(L, R);
    long long right = randInt(L, R);
    return {min(left, right), max(left, right)};
}

// Zwraca losowy wyraz składający się z konkretnych liter alfabetu
string randomString(int N, string s = "abcdefghijklmnopqrstuvwxyz") {
    string res = "";
    int len = s.length();
    for (int i = 0; i < N; ++i) {
        res += s[randInt(0, len - 1)];
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
}
```

compile.sh
```sh
#!/bin/bash
if [ -z "$2" ]
then
	g++ -ggdb3 -Wall -Wextra -Wconversion -Wshadow -pedantic -std=c++17 $1.cpp -o $1.exe && ./$1.exe
else
	if [ -z "$3" ]
	then
		g++ -ggdb3 -Wall -Wextra -Wconversion -Wshadow -pedantic -std=c++17 $1.cpp -o $1.exe && ./$1.exe < $2.txt
	else
		g++ -ggdb3 -Wall -Wextra -Wconversion -Wshadow -pedantic -std=c++17 $1.cpp -o $1.exe && ./$1.exe < $2.in > $3.out
	fi
fi
```
| Komenda                       | Działanie                                      |
| ----------------------------- | ---------------------------------------------- |
| `./compile.sh <prog>`         | Kompiluje i uruchamia kod z pliku `<prog>.cpp` |
| `./compile.sh <prog> <a>`     | To, co powyżej z wejściem z pliku `<a>.in`     |
| `./compile.sh <prog> <a> <b>` | To, co powyżej z wyjściem do pliku `<b>.out`  |

test.sh
```sh
#!/bin/bash
g++ -ggdb3 -Wall -Wextra -Wconversion -Wshadow -pedantic -std=c++17 wzor.cpp -o wzor.exe
g++ -ggdb3 -Wall -Wextra -Wconversion -Wshadow -pedantic -std=c++17 brut.cpp -o brut.exe
g++ -ggdb3 -Wall -Wextra -Wconversion -Wshadow -pedantic -std=c++17 gen.cpp -o gen.exe

for ((i=1; ;++i)) {
	./gen.exe > 0.in
	./wzor.exe < 0.in > 0.out
	./brut.exe < 0.in > 0.ok
	diff -w 0.out 0.ok || break
	echo TEST $i: OK
}
```

Fast input (znacznie szybszy niż cin i scanf dla intów)
```cpp
inline int readInt() {
    int c = getchar_unlocked();
    if (isspace(c)) {
        c = getchar_unlocked();
    }
    int a = c - '0';
    while (isdigit(c = getchar_unlocked())) {
        a = a * 10 + c - '0';
    }
    return a;
}
```
