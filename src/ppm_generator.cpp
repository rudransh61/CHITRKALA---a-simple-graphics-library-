#include "ppm_generator.h"

void fill(Pixel image[WIDTH][HEIGHT], Pixel color) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j] = color;
        }
    }
}

void drawLine(Pixel image[WIDTH][HEIGHT], int x1, int y1, int x2, int y2, Pixel color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (true) {
        image[x1][y1] = color;

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

void saveImagePPM(Pixel image[WIDTH][HEIGHT], const char* filepath) {
    std::ofstream ppmFile(filepath, std::ios::binary);
    if (!ppmFile) {
        std::cerr << "Error opening PPM file: " << filepath << std::endl;
        return;
    }

    ppmFile << "P6\n" << WIDTH << " " << HEIGHT << "\n255\n";

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            ppmFile.put(image[i][j].red);
            ppmFile.put(image[i][j].green);
            ppmFile.put(image[i][j].blue);
        }
    }

    ppmFile.close();
}
