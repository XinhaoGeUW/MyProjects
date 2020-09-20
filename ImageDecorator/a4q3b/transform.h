
#ifndef _TRANSFORM_H
#define _TRANSFORM_H
#include "image.h"
#include "Decorator.h"



class Flip: public Decorator {
public:
    Flip(Image *comp);
    void render(PPM &ppm) override;
};


class Rotate: public Decorator {
public:
    Rotate(Image *comp);
    void render(PPM &ppm) override;
};


class Sepia: public Decorator {
public:
    Sepia(Image *comp);
    void render(PPM &ppm) override;
};

#endif //A4Q3_TRANSFORM_H
