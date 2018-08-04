/*
	Developer: Ryandw11
*/
#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class stringUtils {
public:

	vector<string> split(string s, char splitee);
	void print(string s);
	void println(string s);
	string charsToString(char c[]);
	vector<char> stringToChars(string s);
	bool contains(string s, string checkString);
	string removeChar(string s, char c);
	string replaceAll(string s, string replacee, string replacer);
	string replace(string s, string replacee, string replacer);
	bool startsWith(string s, string prefix);
	string valueOfBool(bool b);
	bool stringToBool(string s);
	string vecToString(vector<string> vec);
	string vecToString(vector<bool> vec);
	string vecToString(vector<int> vec);
	string vecToString(vector<double> vec);
	bool equals(string a, string b);
	bool equalsIgnoreCase(string a, string b);
	bool isEmpty(string s);
	string replaceChar(string s, char current, char neW);

};

vector<string> stringUtils::split(string s, char splitee) {
	/*
	This annoys me.
	Y U NO BUILT IN.
	*/
	vector<string> vec;
	bool foundSpace = false;
	int numOfSpaces = 0;
	string tempStore = "";
	for (char c : s) {
		if (c != splitee)
			tempStore += c;
		if (c == splitee) {
			vec.push_back(tempStore);
			tempStore = "";
		}
	}
	vec.push_back(tempStore);
	return vec;
}

void stringUtils::print(string s) {
	cout << s;
}

void stringUtils::println(string s) {
	cout << s << endl;
}

string stringUtils::charsToString(char c[]) {
	string product;
	for (int i = 0; i < strlen(c); i++) {
		product += c[i];
	}
	return product;
}

vector<char> stringUtils::stringToChars(string s) {
	vector<char> product;
	for (char c : s) {
		product.push_back(c);
	}
	return product;
}

bool stringUtils::contains(string s, string checkString) {
	if (s.find(checkString) != string::npos) {
		return true;
	}
	return false;
}

string stringUtils::removeChar(string s, char c) {
	string product = "";
	for (char cs : s) {
		if (cs != c) {
			product += cs;
		}
	}
	return product;
}

string stringUtils::replaceAll(string s, string replacee, string replacer) {
	size_t i = 0;
	while (true) {
		i = s.find(replacee, i);
		if (i == std::string::npos) break;
		s.replace(i, replacee.size(), replacer);
		i += replacer.size();
	}
	return s;
}

string stringUtils::replace(string s, string replacee, string replacer) {
	s.replace(s.find(replacee), replacee.length(), replacer);
	return s;
}

bool stringUtils::startsWith(string s, string prefix) {
	if (s.find(prefix) == 0)
		return true;
	return false;
}
string stringUtils::valueOfBool(bool b) {
	if (b)
		return "true";
	return "false";
}
bool stringUtils::stringToBool(string s) {
	if (s == "true" || s == "True" || s == "TRUE")
		return true;
	return false;
}

string stringUtils::vecToString(vector<string> vec) {
	string ss = "";
	for (string s : vec) {
		ss += "{'" + s + "'};";
	}
	return ss;
}

string stringUtils::vecToString(vector<bool> vec) {
	string ss = "";
	for (bool s : vec) {
		if (s)
			ss += "{'true'};";
		ss += "{'false'};";
	}
	return ss;
}

string stringUtils::vecToString(vector<int> vec) {
	string ss = "";
	for (int s : vec) {
		ss += "{'" + to_string(s) + "'};";
	}
	return ss;
}
string stringUtils::vecToString(vector<double> vec) {
	string ss = "";
	for (double s : vec) {
		ss += "{'" + to_string(s) + "'};";
	}
	return ss;
}

bool stringUtils::equals(string a, string b) {
	if (a == b)
		return true;
	return false;
}

bool stringUtils::equalsIgnoreCase(string a, string b) {
	transform(a.begin(), a.end(), a.begin(), ::tolower);
	transform(b.begin(), b.end(), b.begin(), ::tolower);
	if (a == b)
		return true;
	return false;
}

bool stringUtils::isEmpty(string s) {
	if (s.length() == 0)
		return true;
	return false;
}

string stringUtils::replaceChar(string s, char current, char neW) {
	string mes = s;
	std::replace(mes.begin(), mes.end(), current, neW);
	return mes;
}