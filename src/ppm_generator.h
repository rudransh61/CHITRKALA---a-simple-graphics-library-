#ifndef PPM_GENERATOR_H
#define PPM_GENERATOR_H

#include <iostream>
#include <fstream>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    unsigned char red, green, blue;
} Pixel;

void fill(Pixel image[WIDTH][HEIGHT], Pixel color);

void saveImagePPM(Pixel image[WIDTH][HEIGHT], const char* filepath);

#endif // PPM_GENERATOR_H
