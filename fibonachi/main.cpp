#include <iostream>
#include <vector>

int main() {
	std::vector<int> numbers = {1,1};
	int x = 0;
	for (int i = 1; i < 30; ++i) {
		x = numbers[i - 1] + numbers[i];
		numbers.push_back(x);
	}
	for (double r : numbers) {
		std::cout << r << " ";
	}
}