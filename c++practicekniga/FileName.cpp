#include <iostream>

using namespace std;

void error(string s) {
	throw runtime_error(s);
}

void celsiy(double t) {
	if (t >= -273.15) {
		double sum = (9.0 / 5) * t + 32;
		cout << sum << "\n";
	}
	else error("out of range in function celsiy");
}

void farangeit(double t) { // преобразует шкалу ÷ельси€ в шкалу  ельвина
	if (t >= -459.67) {
		double sum = (t - 32) * 5.0 / 9;
		cout << sum << "\n";
	}
	else error("out of range in function farangeit");
}

int main() {
	try {
		double t = 0; // объ€вл€ем переменную дл€ ввода
		char choose;
		cout << "Enter the temperature: \n";
		cin >> t; // вводим температуру в переменную ввода
		cout << "(f/c)";
		cin >> choose;
		switch (choose) {
		case 'f':
			farangeit(t);
			break;
		case 'c':
			celsiy(t);
			break;
		}
		return 0;
	}
	catch (exception& e) {
		cerr << "error: " << e.what();
		return 1;
	}
}