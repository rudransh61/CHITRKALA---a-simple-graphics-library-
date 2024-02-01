// main.cpp

#include "SimpleGraphics.h"

int main() {
    SimpleGraphics graphics(512, 512);

    graphics.fillCanvas(255, 0, 0);  // Red canvas

    graphics.drawLine(100, 100, 400, 400, 0, 255, 0);  // Green line

    graphics.saveImagePPM("output.ppm");

    return 0;
}
