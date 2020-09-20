#include "blind.h"

Blind::Blind(Command *c): SpecCommand{c} {}

char Blind::displaychar() {return '?';}
