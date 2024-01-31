#include <iostream>
#include <stdio.h>
// ANSI escape code for red foreground color
const char *redForegroundCode = "\033[31m";
// ANSI escape code for red background color
const char *redBackgroundCode = "\033[41m";
// ANSI escape code to reset text attributes
const char *resetAttributesCode = "\033[0m";

const char *greenForegroundCode = "\033[32m";
// ANSI escape code for green background color
const char *greenBackgroundCode = "\033[42m";

// ANSI escape code for blue foreground color
const char *blueForegroundCode = "\033[34m";
// ANSI escape code for blue background color
const char *blueBackgroundCode = "\033[44m";

void renderRedScreen(int width, int height)
{

    // Clear the console
  

    // Print the red screen by using ANSI escape codes for both foreground and background color
    // for (int i = 0; i < height / 3; ++i)
    // {
    //     for (int j = 0; j < width; ++j)
    //     {
    //         std::cout << redForegroundCode << redBackgroundCode << " " << resetAttributesCode;
    //     }
    //     std::cout << std::endl;
    // }
    for(int k=0;k<100;k++){
        system("cls");
        for (int i = 0; i < height ; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if(i==k&&j==20){
                    std::cout << redForegroundCode << redBackgroundCode << " " << resetAttributesCode;
                }
                else{
                    std::cout << blueForegroundCode << blueBackgroundCode << " " << resetAttributesCode;
                }
            }
            std::cout << std::endl;
        }
        k++; // acceleration
    }
}

int main()
{
    int screenWidth = 40;
    int screenHeight = 24;

    renderRedScreen(screenWidth, screenHeight);

    int check;
    std::cin >> check;

    return 0;
}
