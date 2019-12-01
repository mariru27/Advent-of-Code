#include <iostream>
#include<fstream>

using namespace std;

int main() {
	std::ifstream fileIn("a.in");

	int totalFuel1 = 0, mass = 0,totalFuel2 = 0;
	while (fileIn >> mass) {
		totalFuel1 = 0;
		while (mass > 0) {
			mass = (mass / 3 ) - 2;
			if (mass < 0)
				break;
			totalFuel1 = totalFuel1 + mass;
		}
		totalFuel2 = totalFuel2 + totalFuel1;
	}
	
	cout << totalFuel2;
	fileIn.close();
	return 1;
}
