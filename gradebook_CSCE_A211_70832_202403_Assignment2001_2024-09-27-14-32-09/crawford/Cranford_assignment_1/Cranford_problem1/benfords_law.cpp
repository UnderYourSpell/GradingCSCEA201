#include <iostream>

int main() {
    int numbercount[9] = {0}, num;
    while (std::cin >> num) {
        while (num >=10) num /= 10;
        if (num >= 1 && num <= 9) numbercount[num -1]++;
        }
        for (int a = 0; a < 9; a++) std::cout << "Leading Number: " << a + 1 << " "  << numbercount[a] << std::endl;
        return 0;
}
