#ifndef PARSER_H_
#define PARSER_H_

#include "Command.h"
#include "CommandWords.h"

class Parser {
private:
	CommandWords *commands;

public:
	Parser();
    Command* getCommand(string inputLine);
    void showCommands();
};

#endif /*PARSER_H_*/
