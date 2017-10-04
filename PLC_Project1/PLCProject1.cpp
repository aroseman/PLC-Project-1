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
void display_symbols(stack<char> symbols);
int main()
{
	regex var_start_rgx("[^\\d*");		// Don't want variables to start with numbers so we will invert this in our conditional
	regex var_body_rgx("[a-zA-Z0-9]");	// Everything else can be whatever
	regex symb_rgx("[:,;(){}]");
	regex op_rgx("[+*/-]");

	stack<string> variables;			// Can't start with a digit.  Andrew
	stack<int> constants;				// Must only contain digits/  Brett
	stack<char> symbols;				// : , ; () {} Andrew
	stack<char> operators;				// + - * / =  Brett
	stack<string> keywords;				// Andrew
	stack<string> comments;				// we need to look for/* */ ~good luck
	stack<string> errors;				// both(basically just an else to catch whatever doesn't belong)

	ifstream file ("code.txt");
	string line;
	

	if (file.is_open()) {

//	Loop through file line by line and analyze as we go.
		while (getline(file, line)) {
			
			// iterate across the line to look for symbols
			for (int i = 0; i < line.length(); i++) {

				if (regex_match(line, symb_rgx)) {
					symbols.push(line[i]);		// if the symbol is valid add it to our symbol stack
				}
			}
		

		}

		
	}
	else {
		cout << "[!] Unable to open file\n";
	}
	display_symbols(symbols);

	system("pause");
    return 0;
}

void display_symbols(stack<char> symbols) {
	cout << "Symbols found: ";
	while (!symbols.empty()) {
		cout << symbols.top();
		symbols.pop();
	}

}



