// PLCProject1.cpp : Defines the entry point for the console application.
//
// Use regex to check for correct grammar and then store lexicons on to appropriate stacks for output.

// Just testing github version control 10/2/2017 @ 9:06ish
#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <stack>
#include <regex>


using namespace std;
int main()
{
	regex var_start_rgx("[^\\d*");		// Don't want variables to start with numbers so we will invert this in our conditional
	regex var_body_rgx("[a-zA-Z0-9]");	// Everything else can be whatever
	regex symb_rgx("[:,;(){}]");
	regex op_rgx("[+*/-]");

	stack<string> variables;			// Can't start with a digit. 
	stack<int> constants;				// Must only contain digits/
	stack<char> symbols;				// : , ; () {}
	stack<char> operators;				// + - * /
	stack<string> keywords;
	stack<string> errors;

	ifstream file ("code.txt");
	string line;
	

	if (file.is_open()) {
		

		while (getline(file, line)) {
			cout << line << "\n";

		}

		
	}
	else {
		cout << "[!] Unable to open file\n";
	}
	system("pause");
    return 0;
}




