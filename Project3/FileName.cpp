#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Converter_result {
	vector<double> renums;
	double first_num;
};

Converter_result converter(vector<double> nums_to_convert, vector<string> types_of_num, double num, string type) {
	Converter_result result;
	double renum;
	
	//Перевычесляем все значения в метры
	for (int i = 0; i < nums_to_convert.size() && i < types_of_num.size(); i++) {
		if (types_of_num[i] == "cm" || types_of_num[i] == "Cm") {
			renum = nums_to_convert[i] / 100.0;
			result.renums.push_back(renum);
		}
		else if (types_of_num[i] == "in" || types_of_num[i] == "In") {
			renum = nums_to_convert[i] * 0.0254;
			result.renums.push_back(renum);
		}
		else if (types_of_num[i] == "ft" || types_of_num[i] == "Ft") {
			renum = nums_to_convert[i] * 0.3048;
			result.renums.push_back(renum);
		}
		else if (types_of_num[i] == "M" || types_of_num[i] == "m") {
			result.renums.push_back(nums_to_convert[i]);
		}
	}
	//Перевычисляем последнее веденное значение в метры
	if (type == "cm" || type == "Cm") {
		result.first_num = num / 100.0;
	}
	else if (type == "in" || type == "In") {
		result.first_num = num * 0.0254;
	}
	else if (type == "ft" || type == "Ft") {
		result.first_num = num * 0.3048;
	}
	else if (type == "m" || type == "M") {
		result.first_num = num;
	}
	return result;
}

int main() {
	vector<double> nums;
	vector<string> types;
	vector<string> allowed{"cm", "Cm", "in", "In", "Ft", "ft", "M", "m"};
	double num;
	string type;
	int a = 1;
	int b = 1;
	double sum_of_renums = 0;
	cout << "Enter value and the type of(cm/in/m/ft): \n";
	
	while (cin >> num >> type) {
		nums.push_back(num);
		bool type_is_valid = false;
		for (int i1 = 0; i1 < allowed.size(); ++i1) {
			if (type == allowed[i1]) {
				types.push_back(type);
				type_is_valid = true;
				break;
			}
			
		}
		if (!type_is_valid) {
			cout << "Error...";
			cout << "Enter num: ";
			// Пропускаем текущую итерацию цикла
			continue;
		}
		Converter_result returned_values = converter(nums, types, num, type);
		
		for (int i = 0; i < returned_values.renums.size(); ++i) {
			if (returned_values.first_num < returned_values.renums[i]) {
				++a;
			}
			else if (returned_values.first_num > returned_values.renums[i]) {
				++b;
			}
		}
		if (b == 1 && a == nums.size()) {

			cout << "The lowest of all: " << num << type << "\n";
		}
		else if (a == 1 && b == nums.size()) {
			cout << "The highest of all: " << num << type << "\n";
		}
		for (int i = 0;i < nums.size() && i < types.size(); ++i) {
			cout << nums[i] << types[i] << "\n";
		}
		for (int i = 0; i < returned_values.renums.size(); ++i) {
			sum_of_renums += returned_values.renums[i];
		}
		cout << "Sum of all nums: " << sum_of_renums << "m" << endl;
		cout << "\n";
		cout << "Enter num: ";
		b = 1;
		a = 1;
	}
}