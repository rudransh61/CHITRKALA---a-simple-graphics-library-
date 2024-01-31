#include <iostream>
#include <cmath>

void renderRedCircleBlueBackground(int radius) {
    // ANSI escape code for red foreground color
    const char* redForegroundCode = "\033[31m";
    // ANSI escape code for blue background color
    const char* blueBackgroundCode = "\033[44m";
    // ANSI escape code to reset text attributes
    const char* resetAttributesCode = "\033[0m";
    const char* redBackgroundCode = "\033[41m";



    // Center of the circle
    int centerX = 40; // Adjust as needed
    int centerY = 12; // Adjust as needed

    // Draw the filled circle with red foreground and blue background
    for (int y = centerY - radius; y <= centerY + radius; ++y) {
        for (int x = centerX - radius; x <= centerX + radius; ++x) {
            float distance = std::sqrt(std::pow(x - centerX, 2) + std::pow(y - centerY, 2));
            if (distance <= radius) {
                std::cout << redForegroundCode << blueBackgroundCode << " " << resetAttributesCode;
            } else {
                std::cout << redForegroundCode << redBackgroundCode << " " << resetAttributesCode;
            }
        }
        std::cout << std::endl;
    }
}

int main() {
        // Clear the console
    system("cls");
    int circleRadius = 10;
    std::cout<<"Hapi Meri Teri Christmas"<<std::endl;
    renderRedCircleBlueBackground(circleRadius);

    int check;
    std::cin>>check;

    return 0;
}
