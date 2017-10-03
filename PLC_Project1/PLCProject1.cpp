// PLCProject1.cpp : Defines the entry point for the console application.
//
// Use regex to check for correct grammar and then store lexicons on to appropriate stacks for output.

#include "stdafx.h"

#include <iostream>
#include <stack>
#include <regex>


using namespace std;
int main()
{
	stack<string> variables;
	stack<int> constants;
	stack<char> operators;
	regex var_rgx("[a-z]*");

	string word;
	cin >> word;
	if (regex_match(word, var_rgx)) {
		cout << "Matches lower case characters.";
	}
	else {
		cout << "Does not match lower case characters.";
	}

	system("pause");
    return 0;
}




