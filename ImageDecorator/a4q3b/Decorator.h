
#ifndef _DECORATOR_H
#define _DECORATOR_H
#include "image.h"

class Decorator: public Image{
protected:
    Image *comp;
public:
    Decorator(Image *comp);
    virtual ~Decorator();
};
#endif
