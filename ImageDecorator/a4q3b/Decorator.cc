#include "image.h"
#include "Decorator.h"

Decorator::Decorator(Image *comp): comp{comp} {}
Decorator::~Decorator() { delete comp; }
