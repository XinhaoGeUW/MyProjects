#include "specCommand.h"
#include "block.h"
#include "lowerlevel.h"

SpecCommand::SpecCommand(Command *Command): currCom {Command} {}

char SpecCommand::displaychar() {return currCom->displaychar();}
int SpecCommand::left(Block *b) {return currCom->left(b);}
int SpecCommand::right(Block *b) {return currCom->right(b);}
int SpecCommand::down(Block *b) {return currCom->down(b);}
void SpecCommand::drop(Block *b) {currCom->drop(b);}
int SpecCommand::clockwise(Block *b) {return currCom->clockwise(b);}
int SpecCommand::counter(Block *b) {return currCom->counter(b);}

SpecCommand::~SpecCommand() {delete currCom;}
