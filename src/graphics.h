#include <iostream>

int pixels[64][64];

void vertex(int x, int y)
{
}

void show_screen(int pixels[64][64])
{
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            std::cout << pixels[i][j];
        }
        std::cout << '\n';
    }
}