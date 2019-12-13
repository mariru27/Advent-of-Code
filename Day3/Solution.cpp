#include<iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

std::ifstream fileIn("a.in");

int val = 0;
char c = ',', direction = ' ';
struct stru
{
	int x = 0;
	int y = 0;
};

void makePositiv(vector<stru>& location) {
	for (int i = 0; i < location.size(); i++) {
		location[i].x = abs(location[i].x);
		location[i].y = abs(location[i].y);
	}
}

void read(vector<stru> &location) {
	location.push_back(stru());

	bool readAll = false;

	while (readAll == false){
		fileIn >> direction >> val >> c;
		if (c == '.') {
			readAll = true;
		}

		switch (direction){
		case'R': {
			for (int i = 1; i <= val; i++) {
				location.push_back(stru());
				location[location.size() - 1].y = location[location.size() - 2].y;
				location[location.size() - 1].x = location[location.size() - 2].x + 1;
			
			}
			continue;
		}
		case'U': {
			for (int i = 1; i <= val; i++) {
				location.push_back(stru());
				location[location.size() - 1].x = location[location.size() - 2].x;
				location[location.size() - 1].y = location[location.size() - 2].y + 1;
			}
			continue;
		}
		case'D': {
			for (int i = 1; i <= val; i++) {
				location.push_back(stru());
				location[location.size() - 1].x = location[location.size() - 2].x;
				location[location.size() - 1].y = location[location.size() - 2].y - 1;
			}
			continue;
		}
		case'L': {
			for (int i = 1; i <= val; i++) {
				location.push_back(stru());
				location[location.size() - 1].y = location[location.size() - 2].y;
				location[location.size() - 1].x = location[location.size() - 2].x - 1;
			}
			continue;
		}
		default:
			break;
		}
	}
}

bool compare(stru a,stru b) {
	if (a.x + a.y < b.x + b.y) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	vector<stru>location1;
	vector<stru>location2;

	read(location1);
	read(location2);

	sort(location1.begin(), location1.end(), compare);
	sort(location2.begin(), location2.end(), compare);
	
	bool solution = false;
	int distance = 0;

	for (int i = 0; i < location1.size(); i++) {
		for (int j = 0; j < location2.size(); j++) {
			if (location1[i].x == location2[j].x && location1[i].y == location2[j].y) {
				distance = abs(location1[i].x) + abs(location1[i].y);
				break;
			}
		}
		if (distance != 0)
			break;
	}
	cout << distance;

	fileIn.close();
	return 1;
}
