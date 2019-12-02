#include <iostream>
#include<fstream>
#include<vector>

using namespace std;

int main() {
	std::ifstream fileIn("a.in");
	int val = 0;
	char c;
	vector<int> vec;
	bool findSolution = false;
	vector<int> currentVec;

	while (fileIn >> val) {
		vec.push_back(val);
		fileIn >> c;
	}

	for (int k1 = 1; k1 <= 99; k1++) {
		if (findSolution == true)
			break;
		for (int k2 = 1; k2 <= 99; k2++) {
			for (int j = 0; j < vec.size(); j++) {
				currentVec.push_back(vec[j]);
			}
			int i = -1;
			currentVec[1] = k1;
			currentVec[2] = k2;
			while ( i != currentVec.size()-1) {
				++i;
				if (currentVec[i] == 1) {
					currentVec[currentVec[i + 3]] = currentVec[currentVec[i + 1]] + currentVec[currentVec[i + 2]];
					i = i + 3;
					continue;
				}
				if (currentVec[i] == 2) {
					currentVec[currentVec[i + 3]] = currentVec[currentVec[i + 1]] * currentVec[currentVec[i + 2]];
					i = i + 3;
					continue;
				}
				if (currentVec[i] == 99)
					break;

			}
			if (currentVec[0] == 19690720) {
				cout << 100 * k1 + k2 << " ";
				findSolution = true;
			}
			currentVec.clear();
		}
	}
	fileIn.close();
	return 1;
}
