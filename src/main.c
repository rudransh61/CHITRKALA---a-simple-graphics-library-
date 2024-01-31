#include "ppm_generator.h"

int main() {
    Pixel pixels[WIDTH][HEIGHT];

    Pixel fillColor = {255, 0, 0};  // Red color
    fill(pixels, fillColor);

    const char* ppmFilePath = "output.ppm";

    saveImagePPM(pixels, ppmFilePath);

    return 0;
}
