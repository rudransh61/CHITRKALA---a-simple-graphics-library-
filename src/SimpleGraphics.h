// SimpleGraphics.h

#ifndef SIMPLE_GRAPHICS_H
#define SIMPLE_GRAPHICS_H

#include <iostream>
#include <fstream>

class SimpleGraphics {
public:
    SimpleGraphics(int width, int height);
    ~SimpleGraphics();

    void fillCanvas(unsigned char red, unsigned char green, unsigned char blue);
    void drawLine(int x1, int y1, int x2, int y2, unsigned char red, unsigned char green, unsigned char blue);
    void saveImagePPM(const char* filepath);

private:
    int width;
    int height;

    typedef struct {
        unsigned char red, green, blue;
    } Pixel;

    Pixel** pixels;
};

#endif // SIMPLE_GRAPHICS_H
