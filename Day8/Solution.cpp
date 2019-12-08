#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

std::ifstream fileIn("a.in");


int main() {
	vector<vector<int>> vec;
	vector<int> temp;
	char c = ' ';
	int i = -1, j = -1;
	const int pixels = (25*6)- 1;
	bool readAll = false;
	while (readAll == false) {
		++i;
		j = -1;
		while (pixels!=j && fileIn >> c) {
			if (c != '.') {
				++j;
				temp.push_back(c - '0');
			}
			else {
				readAll = true;
				break;
			}

		}
		if (readAll == false) {
			vec.push_back(temp);
			temp.clear();
		}
	}

	int min0 = 10000, numberOf0 = 0 , layer = 0;
	vector<int> finalImage;
	int image = 2;
	for (i = 0; i <= pixels; i++) {
		image = 2;
		for (j = 0; j < vec.size() ; j++) {
			if (vec[j][i] == 1 || vec[j][i] == 0) {
				image = vec[j][i];
				break;
			}
		}
		finalImage.push_back(image);
	}

	int numberOf1 = 0, numberOf2 = 0;
	for (i = 0; i < finalImage.size(); i++) {
		if (finalImage[i] == 1) {
			numberOf1++;
		}
		if (finalImage[i] == 2) {
			numberOf2++;
		}
	}

	for (int i = 0; i < finalImage.size(); i++) {
		if (finalImage[i] == 1)
			cout << '*';
		else
			cout << ' ';
		if (i % 25 == 0)
			cout << endl;
	}

	fileIn.close();
	return 1;
}
