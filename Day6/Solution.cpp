#include <iostream>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<set>
#include<stack>
#include<string.h>
#include<queue>

using namespace std;

std::ifstream fileIn("a.in");

string str1, str2, str;

struct Node {
	int sum = 0;
	string str;
	Node* parent = NULL;
	vector<Node*> child;
}*root;

struct MyString {
	string str1;
	string str2;
};
vector<MyString> inputString;
vector<Node*> orbits;
Node *san, *you;

bool findStr(string str) {
	for (int i = 0; i < orbits.size(); i++) {
		if (orbits[i]->str == str)
			return true;
	}
	return false;
}

Node* findNode(string str) {
	for (int i = 0; i < orbits.size(); i++) {
		if (orbits[i]->str == str) {
			return orbits[i];
		}
	}
	return NULL;
}

void createNode(string str) {
	if (findNode(str) == NULL) {
		Node* newNode;
		newNode = new Node;
		newNode->str = str;
		orbits.push_back(newNode);
	}
}

struct Remember {
	Node* parent, * child;
};
vector<Remember> rememberNode;

void findSan() {
	Node* p;
	san = findNode("SAN");
	you = findNode("YOU");
	queue<Node*> path;
	vector<Node*> visited;
	unordered_map<Node*, int> distance;
	//bool isVisited = false;
	p = you->parent;
	path.push(p);

	while (!path.empty()){
		p = path.front();
		path.pop();
		visited.push_back(p);
		/*if (p->parent != NULL)
			path.push(p->parent);*/
		for (int i = 0; i < p->child.size(); i++) {
			if (find(visited.begin(), visited.end(), p->child[i]) != visited.end())
				continue;
			path.push(p->child[i]);
			distance[p->child[i]] = distance[p] + 1;
		}
	}
	cout << distance[san->parent];
	//int j = -1;
	/*while (path.empty() == false) {
		p = path.front();
		//isVisited = false;
		//for (int i = 0; i < visited.size(); i++) {
		//	if (p == visited[i])
		//		isVisited = true;
		//}
		if (isVisited == true)
			path.pop();
		else {
			visited.push_back(p);
			path.pop();
			path.push(p->parent);
			for (int i = 0; i < p->child.size(); i++) {
				path.push(p->child[i]);
			}
		}
	}*/
	
}

int main() {

	while (fileIn >> str){
		str1 = str.substr(0, str.find(')') );
		str2 = str.substr(str.find(')')+1, str.size() );
		createNode(str1);
		createNode(str2);
		inputString.push_back(MyString());
		inputString[inputString.size() - 1].str1 = str1;
		inputString[inputString.size() - 1].str2 = str2;
	}
	
	int i = -1;
	Node* p1, *p2;
	while (i != inputString.size() - 1){
		i++;
		p1 = findNode(inputString[i].str1);
		p2 = findNode(inputString[i].str2);
		p1->child.push_back(p2);
		p2->child.push_back(p1);
		p2->parent = p1;
	}
	Node* p;
	int Sum = 0;

	for (int i = 0; i < orbits.size(); i++) {
		p = orbits[i];
		while (p->parent!= NULL){
			++Sum;
			p = p->parent;
		}
	}
	findSan();
	//cout << Sum;

	fileIn.close();
	return 1;
}
