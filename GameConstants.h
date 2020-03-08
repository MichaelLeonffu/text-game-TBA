// GameConstants.h

#include <string>
#include <vector>

// Defines all the constants for this game; also known as parameters


/////////////
// IO
/////////////

const int MAX_LINE_SIZE_LOOP 	= 25; // loop after this point


/////////////
// COMMANDS
/////////////

struct Command{
  int		id;
  string 	name;
  //char	shortName;
};

int CMD_ID_HELP		= 0;
int CMD_ID_LOOK 	= 1;
int CMD_ID_LOOK_AT 	= 2;
int CMD_ID_GO 		= 3;
int CMD_ID_TAKE 	= 4;
int CMD_ID_THROW 	= 5;
int CMD_ID_TALK_TO 	= 6;
int CMD_ID_EAT 		= 7;
int CMD_ID_PUT 		= 8;

Command CMD_HELP	= { 0, "HELP"	};
Command CMD_LOOK 	= { 1, "LOOK"	};
Command CMD_LOOK_AT 	= { 2, "LOOK AT"};
Command CMD_GO 		= { 3, "GO"	};
Command CMD_TAKE 	= { 4, "TAKE"	};
Command CMD_THROW 	= { 5, "THROW"	};
Command CMD_TALK_TO 	= { 6, "TALK_TO"};
Command CMD_EAT 	= { 7, "EAT"	};
Command CMD_PUT 	= { 8, "PUT"	};

const vector<Command> commands =
  {
   CMD_HELP,
   CMD_LOOK,				
   CMD_LOOK_AT,
   CMD_GO,
   CMD_TAKE,
   CMD_THROW,
   CMD_TALK,
   CMD_EAT,
   CMD_PUT,
  };

