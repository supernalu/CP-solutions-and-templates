#include "cyklib.hpp"

int main() {
	int ans = 0;
	for(int i = 0; i < 100; ++i) {
		ans += circular_shift(i) % 1234;
	}
	give_answer(ans);
}
