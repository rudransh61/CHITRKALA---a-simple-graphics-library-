// SimpleGraphics.cpp

#include "SimpleGraphics.h"

SimpleGraphics::SimpleGraphics(int width, int height) : width(width), height(height) {
    pixels = new Pixel*[width];
    for (int i = 0; i < width; ++i) {
        pixels[i] = new Pixel[height];
    }
}

SimpleGraphics::~SimpleGraphics() {
    for (int i = 0; i < width; ++i) {
        delete[] pixels[i];
    }
    delete[] pixels;
}

void SimpleGraphics::fillCanvas(unsigned char red, unsigned char green, unsigned char blue) {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            pixels[i][j] = {red, green, blue};
        }
    }
}

void SimpleGraphics::drawLine(int x1, int y1, int x2, int y2, unsigned char red, unsigned char green, unsigned char blue) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (true) {
        pixels[x1][y1] = {red, green, blue};

        if (x1 == x2 && y1 == y2) {
            break;
        }

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void SimpleGraphics::saveImagePPM(const char* filepath) {
    std::ofstream ppmFile(filepath, std::ios::binary);
    if (!ppmFile) {
        std::cerr << "Error opening PPM file: " << filepath << std::endl;
        return;
    }

    ppmFile << "P6\n" << width << " " << height << "\n255\n";

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            ppmFile.put(pixels[i][j].red);
            ppmFile.put(pixels[i][j].green);
            ppmFile.put(pixels[i][j].blue);
        }
    }

    ppmFile.close();
}
