// GameHelper.h

#include <iostream>
#include <bits/stdc++.h>

#include "GameConstants.h"

// simple things such as parsing commands and printing lines

// printing long lines
void printLineWithMax(const string &line){
  int currentLineCount = 0;
  for(int i = 0; i < line.length(); ++i){
    cout << line[i];
    currentLineCount++;
    if(currentLineCount >= MAX_LINE_SIZE_LOOP)
      if(line[i] == ' '){ //delim
	cout << endl;
	currentLineCount = 0;
      }
  }
};

// converting string to lower case
void toUpperString(string &line){
  for(int i = 0; i < line.length(); ++i)
    line[i] = toupper(line[i]);
};

// takes inputs, detemrines their commands
int getInputInterface(){
  // first take in the input
  string input;
  getline(cin, input);

  // next check if it matches any commands
  
  
};
