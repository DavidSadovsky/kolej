#include <iostream>
#include <vector>
using namespace std;

static void error(string problem) {
	throw runtime_error(problem);
}

static vector<double> func(double a, double b, double c) {
	vector<double> x;
	double discriminant = sqrt(pow(b, 2) - 4.0 * a * c);
	if (discriminant >= 0) {
		cerr << "Discriminant: " << discriminant << endl;
		if (discriminant > 0) {
			double x1 = (-b - discriminant) / (2.0 * a);
			double x2 = (-b + discriminant) / (2.0 * a);
			x.push_back(x1);
			x.push_back(x2);
		}
		if (discriminant == 0) {
			double x3 = -b / (2.0 * a);
			x.push_back(x3);
		}
	}
	else error("Discriminant less than 0");
	return x;
}

int main() {
	try {
		double a, b, c;
		cout << "Enter the values for square equation (a , b , c)\n";
		cin >> a >> b >> c;
		vector<double> roots = func(a, b, c);
		cout << "The roots: \n";
		for (double r : roots) {
			cout << r << endl;
		}
		return 0;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what();
		return 1;
	}
	catch (...) {
		cerr << "Unmatched error.";
		return 2;
	}
}