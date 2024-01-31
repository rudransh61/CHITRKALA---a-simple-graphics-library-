#include "ppm_generator.h"

void fill(Pixel image[WIDTH][HEIGHT], Pixel color) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j] = color;
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
