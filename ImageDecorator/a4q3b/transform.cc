#include "transform.h"
using  namespace std;


Flip::Flip(Image *comp): Decorator{comp} {}
void Flip::render(PPM &ppm) {
    comp->render(ppm);
    int width = ppm.getWidth(), height = ppm.getHeight();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width/2; j++) {
            Pixel p = ppm.getPixels().at(i*width + j);
            ppm.getPixels().at(i*width + j) = ppm.getPixels().at(i*width + width-j-1);
            ppm.getPixels().at(i*width + width-j-1) = p;
            
        }
    }
}


Rotate::Rotate(Image *comp): Decorator{comp} {}
void Rotate::render(PPM &ppm) {
    comp->render(ppm);
    int width = ppm.getWidth(), height = ppm.getHeight();
    vector<Pixel> pixels = ppm.getPixels();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels.at(height*j + i) = ppm.getPixels().at(width * (height-i-1) + j);
        }
    }
    ppm.getPixels() = pixels;
    ppm.getHeight() = width;
    ppm.getWidth() = height;
}


Sepia::Sepia(Image *comp): Decorator{comp} {}
void Sepia::render(PPM &ppm) {
    comp->render(ppm);
    int size = ppm.getPixels().size();
    vector<Pixel> pixels = ppm.getPixels();
    for (int i = 0; i < size; i++) {
        int r = pixels.at(i).r*0.393 + pixels.at(i).g*0.769 + pixels.at(i).b*0.189;
        int g = pixels.at(i).r*0.349 + pixels.at(i).g*0.686 + pixels.at(i).b*0.168;
        int b = pixels.at(i).r*0.272 + pixels.at(i).g*0.534 + pixels.at(i).b*0.131;
        pixels.at(i).r =  r < 255 ? r : 255;
        pixels.at(i).g =  g < 255 ? g : 255;
        pixels.at(i).b =  b < 255 ? b : 255;
    }
    ppm.getPixels() = pixels;
}
