#include <iostream>
#include <vector>
using namespace std;

//forward declaration
struct Prompt;

// Pairs the options with the pointer to next prompt
struct Option{

  string dialog;

  Prompt *nextPrompt;
};


// Contains the current Prompt as well as choices
// of Options to the next Prompt
struct Prompt{

  string dialog;

  vector<Option> options;

  void run(){
    // say dialog
    cout << dialog << endl;

    // list out options
    for(int i = 0; i < options.size(); ++i){
      cout << (char)(i+65) << ": " << options[i].dialog << endl;
    }
    
    // get input
    string input;
    int choice;
    bool firstTime = true;
    do{

      //retry
      if(!firstTime)
	cout << "I don't understand." << endl;
      else
	firstTime = false;
      
      // input value
      cout << ">";
      getline(cin, input);

      if(input.length() <= 0)
	continue;
      
      // only look at first letter asume uppercase
      choice = (int)(input[0]-65);
      if(choice < 0 || choice >= options.size())
	continue;

      // input is valid!
      break;
    }while(true);

    //use input
    options[choice].nextPrompt->run();
  }
};


int main(){

  cout << "You enter a tea house" << endl;
  cout << "Your friends recommneded it to you but you're" << endl;
  cout << "not sure if you'll like it or not. They look friendly\n" << endl;

  //make the dialog

  Prompt first;
  Prompt second;
  Prompt thrid;
  first.dialog = "Can I help you?";
  Option first1;
  first1.dialog = "Yes. Can I have matcha tea?";
  first1.nextPrompt = &thrid;
  Option first2;
  first2.dialog = "No, no one can help me!";
  first2.nextPrompt = &second;
  Option first3;
  first3.dialog = "Yes. Can I have black tea?";
  first3.nextPrompt = &thrid;
  // put all together
  first.options = {first1, first2, first3};

  //next prompt
  second.dialog = "Alright.";
  Option second1;
  second1.dialog = "Wait! I'm just kidding hahaha";
  second1.nextPrompt = &first;
  Option second2;
  second2.dialog = "Sorry, it was a joke!";
  second2.nextPrompt = &first;
  // put all together
  second.options = {second1, second2};

  // last prompt
  thrid.dialog = "With milk?";
  Option thrid1;
  thrid1.dialog = "Yes please";
  thrid1.nextPrompt = &first;
  Option thrid2;
  thrid2.dialog = "No!";
  thrid2.nextPrompt = &first;
  Option thrid3;
  thrid3.dialog = "If only you want to ;)";
  thrid3.nextPrompt= &second;
  // put all together
  thrid.options = {thrid1, thrid2, thrid3};

  // start text
  first.run();
  
  return 0;
};
