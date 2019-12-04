#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<string>
#include <sstream> 
#include<vector>


using namespace std;

vector<int> vec;

bool isOrde(int a) {
	int* m = new int[10]{};
	for (int i = 0; i < 6; i++) {
		vec.push_back(a%10);
		a = a / 10;
	}
	bool exist=true;
	int n = 0;
	int isPairInFront = 0;
	reverse(vec.begin(), vec.end());

	for (int i = 0; i < vec.size() - 1; i++) {

		if (vec[i] > vec[i + 1]) {
			vec.clear();
			return false;
		}
	}
	for (int j = 0; j < vec.size(); j++) {
		++m[vec[j]];
	}
	bool is2 = false;
	for (int j = 0; j < 10; j++) {
		if (m[j] == 2) {
			is2 = true;
		}

	}
	vec.clear();

	delete[] m;

	if (exist == true && is2 == true)
		return true;
	else
		return false;

}

int main() {
	std::ifstream fileIn("a.in");
	string str;
	fileIn >> str;
	int a = 0;
	int b = 0;
	for (int i = 0; i < 6; i++) {
		a = (a * 10) + str[i] - '0';
	}
	for (int i = 0; i < 6; i++) {
		b = (b * 10) + str[i+7] - '0';
	}
	int k = 0;
	
	for (int i = a; i <= b; i++) {
		if (isOrde(i) == true) {
			++k;
		}
	}

	cout << k;
	fileIn.close();
	return 1;
}
