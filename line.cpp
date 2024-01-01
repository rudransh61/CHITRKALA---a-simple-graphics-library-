#include <iostream>
#include <stdio.h>
#define WIDTH 64
#define HEIGHT 16

// ANSI escape code for red foreground color
const char *redForegroundCode = "\033[31m";
// ANSI escape code for red background color
const char *redBackgroundCode = "\033[41m";
// ANSI escape code to reset text attributes
const char *resetAttributesCode = "\033[0m";

const char *greenForegroundCode = "\033[32m";
// ANSI escape code for green background color
const char *greenBackgroundCode = "\033[42m";
// ANSI escape code to reset text attributes
const char *resetAttributesCode2 = "\033[0m";

// ANSI escape code for blue foreground color
const char *blueForegroundCode = "\033[34m";
// ANSI escape code for blue background color
const char *blueBackgroundCode = "\033[44m";
// ANSI escape code to reset text attributes
const char *resetAttributesCode3 = "\033[0m";
void renderLine(int x1, int x2, int y1, int y2)
{
    // Clear the console
    system("cls");

    // Print the red screen by using ANSI escape codes for both foreground and background color
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    int x = x1;
    int y = y1;

    int pixels[HEIGHT][WIDTH] = {0};

    pixels[y][x] = 1; // Mark the starting point as red

    while (x != x2 || y != y2)
    {
        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err = err - dy;
            x = x + sx;
        }

        if (e2 < dx)
        {
            err = err + dx;
            y = y + sy;
        }

        pixels[y][x] = 1; // Mark the current point as red
    }

    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            if (pixels[i][j] == 1)
            {
                std::cout << redForegroundCode << redBackgroundCode << " " << resetAttributesCode;
            }
            else
            {
                std::cout << blueForegroundCode << blueBackgroundCode << " " << resetAttributesCode;
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    int x1 = 4;
    int y1 = 3;
    int x2 = 9;
    int y2 = 6;

    // int pixel[32][32] ;
    system("cls");
    renderLine(x1,x2,y1,y2);


    

    int check;
    std::cin >> check;

    return 0;
}
