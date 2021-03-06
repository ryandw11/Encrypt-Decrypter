// Cypher.cpp : Defines the entry point for the console application.
//
/*
	
	Cypher.cpp - Developer: Ryandw11
	Encryptes and decrypts messages.

*/

#include "stdafx.h"
#include "UsefulStuff.h"
#include "VectorUtils.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <random>
#include<math.h>

using namespace std;
/*
	Variable declaration area.
*/
stringUtils su;
VectorUtils vu;
string message;

string refrence[29] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", ".", "?", "!"};
vector<string> scale;
int chars = 29; //How many characters there are in refrence.
int oneLessChar = 28; //chars - 1

random_device rd;

void encrypt(string message);
int findPlace(char c);
void decrypt(string message);
int findCharInRefrence(char c);

/*
	Main Method.
*/

int main()
{
	while (true) {
		su.println("Ryan cypher! Do you want to encrypt or decrypt a message. (Cancel to stop)");
		string ans;
		cin >> ans;
		if (su.equalsIgnoreCase(ans, "encrypt")) {
			su.println("Selected encrypt. Please enter in the message you want to encrypt. (Use _ instead of spaces)");
			cin >> message;
			su.replaceAll(message, "_", " ");
			encrypt(message);
		}
		else if (su.equalsIgnoreCase(ans, "decrypt")) {
			su.println("Please enter in the message you want to decrypt.");
			cin >> message;
			decrypt(message);
		}
		else if (su.equalsIgnoreCase(ans, "cancel") || su.equalsIgnoreCase(ans, "stop") || su.equalsIgnoreCase(ans, "exit")) {
			return 0;
		}
	}
    return 0;
}
/*
	Encrypt Method
*/
void encrypt(string message) {
	int randomNumber = rd() % chars + 1; //Picks a random letter (Except a).
	string letter = refrence[randomNumber];
	string encryptedeMessage;
	int i = randomNumber;
	while (size(scale) != chars) { //Makes the scale to compare to.
		scale.push_back(refrence[i]);
		if (i == oneLessChar) {
			i = -1;
		}
		i++;
	}
	vector<char> input = su.stringToChars(message); //Changes the string to a vector of characters.
	int place;
	for (char c : input) {
		place = findPlace(tolower(c));
		if (place != -1) { //-1 equals space.
			encryptedeMessage += scale.at(place);
		}
		else {
			encryptedeMessage += " ";
		}
	}

	cout << scale.at(0) << "_" << su.replaceAll(encryptedeMessage, " ", "_") << endl;
}
/*
	Find Place Method.
	This method is responsible for finding where the character is in the refrence list.
*/
int findPlace(char c) {
	for (int i = 0; i < chars; i += 1) {
		string str(1, c);
		if (refrence[i] == str) {
			return i;
		}
	}

	return -1;
}
/*
	Find Character is Refrence method.
	It is like the one above but is used diffrently.
*/
int findCharInRefrence(char c) {
	for (int i = 0; i < chars; i++) {
		if (c == refrence[i].at(0))
			return i;
	}
}
/*
	Decrypt Function
	Used to decrypt a message.
*/
void decrypt(string message) {
	string msg = su.replaceAll(message, "_", " ");
	vector<string> split = su.split(msg, ' ');
	int splitValueTwo = findCharInRefrence(split.at(0).at(0)); //Grab the value of the letter that a is equal to. (ex. a == b. splitValueTwo == 1)
	int i = splitValueTwo; //i equals splitValueTwo so it starts filling in the scale from there.
	while (size(scale) != chars) { //Fills in the scale so it could be used to compare.
		scale.push_back(refrence[i]);
		if (i == oneLessChar) {
			i = -1;
		}
		i++;
	}

	split = vu.removeStringFromVector(split, split.at(0)); //Removes the identifier from the front of the message.

	string output = "";
	for (string sf : split) { //Puts the vector back into one string (with spaces).
		if (output == "")
			output += sf;
		else
			output += (" " + sf);
	}	
	vector<char> input = su.stringToChars(output);
	string decryptedMessage = "";
	for (char c : input) { //Translates the chars into their original characters.
		int loc = vu.findLocation(vu.stringVecToCharVec(scale), c);
		if (loc >= 0) {
			decryptedMessage += refrence[loc];
		}
		else
			decryptedMessage += " ";
	}
	cout << decryptedMessage << endl; //Prints out the message.
	string s;
	
	

}

