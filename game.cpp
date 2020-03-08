// Game.cpp

#include <iostream>
#include <vector>
using namespace std;

#include "GameConstants.h"
#include "GameHelper.h"

struct Scene;

struct Noun{

};

struct Item{
  
};

struct Person{
  //nothing
};

struct Direction{

  //direction e.g "up", "u"
  string direction;
  string directionShort;

  Scene *nextScene;

  // return nullptr if no direction
  Scene* nextDirection(){
    // TODO add more than one character
    
  }
};

struct Scene{

  // name is short, description is what you see
  string name;
  string description;

  // TODO add check to see if first time visiting scene

  // other locations (scenes) to visit
  vector<Direction> directions;

  // TODO add items, players etc

  // engine
  Scene* run(){
    // runs until direction is chosen

    // tell the scene
    cout << this->name << endl;
    printLineWithMax(this->description);

    // get directions interface
  }
  
};


int main(){
  
  // define world
  Scene teaHouse = {
  		    .name = "Tea House",
  		    .description = "Small tea house at the top "
  		    "of the mountain you're visiting. "
  		    "The workers look nice. You can see a back "
		    "room. ",
  		    .directions = {
				   {
				    .direction = "exit",
				    .directionShort = "x",
				    .nextScene = nullptr
				   },
				   {
				    .direction = "enter",
				    .directionShort = "e",
				    .nextScene = nullptr
				   }
				  }
  };

  Scene backRoom = {
		    .name = "Back Room",
		    .description = "There are bags... huge bags "
		    "filled with tea. You're sick of the smell ",
		    .directions = {
				   {
				    .direction = "exit",
				    .directionShort = "x",
				    .nextScene = &teaHouse
				   }
				  }
  };

  Scene teaHouseFront = {
			 .name = "Tea House Front",
			 .description = "Looks like the Tea House "
			 "in the yelp picture. 5 stars, pretty "
			 "good! Unless...",
			 .directions = {
					{
					 .direction = "enter",
					 .directionShort = "e",
					 .nextScene = &teaHouse
					}
				       }
  };

  // connect the first scene
  teaHouse.directions[0].nextScene = &teaHouseFront;
  teaHouse.directions[1].nextScene = &backRoom;
  
  // scene engine

  Scene *currentScene = &teaHouse;

  while(true) // using the current scene to generate the next scene
    currentScene = currentScene->run();
  
  return 0;
}
