#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

std::ifstream fileIn("a.in");
vector <int> vec;

int main() {
	int val = 0, positionMode1 = 0, positionMode2 = 0;
	char c;
	int opcode = 0;
	bool findSolution = false;
	
	while (fileIn >> val) {
		fileIn >> c;
		vec.push_back(val);
	}
	int i = 0;
	while (!findSolution){
		if (vec[i] == 99) {
			findSolution = true;
			break;
		}
		int value1 = 0, value2 = 0;

		opcode = vec[i] % 10;
		vec[i] = vec[i] / 100;
		positionMode1 = vec[i] % 10;
		vec[i] = vec[i] / 10;
		positionMode2 = vec[i];

		switch (opcode){
		case 1: {
			if (positionMode1 == 1)
				value1 = vec[i + 1];
			else
				value1 = vec[vec[i + 1]];
			if (positionMode2 == 1)
				value2 = vec[i + 2];
			else
				value2 = vec[vec[i + 2]];
			vec[vec[i + 3]] = value1 + value2;
			i = i + 4;
			continue;
		}
		case 2: {
			if (positionMode1 == 1)
				value1 = vec[i + 1];
			else
				value1 = vec[vec[i + 1]];
			if (positionMode2 == 1)
				value2 = vec[i + 2];
			else
				value2 = vec[vec[i + 2]];
			vec[vec[i + 3]] = value1 * value2;
			i = i + 4;
			continue;
		}
		case 3: {
			vec[vec[i + 1]] = vec[i];
			i = i + 2;
			continue;
		}
		case 4: {
			cout << vec[vec[i + 1]] << endl;
			i = i + 2;
			continue;
		}
		default:
			break;
		}
	}
		

	fileIn.close();
	return 1;
}
