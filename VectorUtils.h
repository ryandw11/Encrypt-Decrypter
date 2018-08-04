/*
	Developer: Ryandw11
*/

#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class VectorUtils {
public:
	vector<string> removeStringFromVector(vector<string> vec, string s);
	bool vectorContainsString(vector<string> vec, string s);
	int findLocation(vector<char> c, char letter);
	vector<char> stringVecToCharVec(vector<string> vec);
};
/*
vector<string> vec -- The vector you want to remove the string from.
string s -- The string you want to remove.
throws "Object not found" if the string could not be found.
*/
vector<string> VectorUtils::removeStringFromVector(vector<string> vec, string s) {
	int i = 0;
	bool found = false;
	vector<string> vecTmp = vec;
	for (string st : vecTmp) {
		if (st == s) {
			found = true;
			break;
		}
		i++;
	}
	if (!found) {
		cout << "Error: Object could not be found! The object " << s << " could not be removed from the vector as it was not found. (VectorUtils)" << endl;
		throw "Object not found.";
		return vec;
	}
	vecTmp.erase(vecTmp.begin() + i);
	return vecTmp;
}

int VectorUtils::findLocation(vector<char> c, char letter) {
	int i = 0;
	if (letter == ' ')
		return -1;
	for (char ca : c) {
		if (ca == letter)
			return i;
		i += 1;
	}
	return -1;
}

bool VectorUtils::vectorContainsString(vector<string> vec, string s) {
	for (string st : vec) {
		if (st == s) {
			return true;
		}
	}
	return false;
}

vector<char> VectorUtils::stringVecToCharVec(vector<string> vec) {
	vector<char> cv;
	for (string s : vec) {
		for (char c : s) {
			cv.push_back(c);
		}
	}
	return cv;
}