#include <iostream>
#include<stdio.h>

void renderRedScreen(int width, int height) {
    // ANSI escape code for red foreground color
    const char* redForegroundCode = "\033[31m";
    // ANSI escape code for red background color
    const char* redBackgroundCode = "\033[41m";
    // ANSI escape code to reset text attributes
    const char* resetAttributesCode = "\033[0m";

  const char* greenForegroundCode = "\033[32m";
  // ANSI escape code for green background color
  const char* greenBackgroundCode = "\033[42m";
  // ANSI escape code to reset text attributes
  const char* resetAttributesCode2 = "\033[0m";

    // Clear the console
    // system("cls");

    // Print the red screen by using ANSI escape codes for both foreground and background color
    for (int i = 0; i < height/3; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << redForegroundCode << redBackgroundCode << " " << resetAttributesCode;
        }
        std::cout << std::endl;
    }

  for (int i = height/3; i < 2*height/3; ++i) {
      for (int j = 0; j < width; ++j) {
          std::cout << greenForegroundCode << greenBackgroundCode << " " << resetAttributesCode2;
      }
      std::cout << std::endl;
  }


  // ANSI escape code for blue foreground color
  const char* blueForegroundCode = "\033[34m";
  // ANSI escape code for blue background color
  const char* blueBackgroundCode = "\033[44m";
  // ANSI escape code to reset text attributes
  const char* resetAttributesCode3 = "\033[0m";


  for (int i = 2*height/3; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
          std::cout << blueForegroundCode << blueBackgroundCode << " " << resetAttributesCode3;
      }
      std::cout << std::endl;
  }


  
}

int main() {
    int screenWidth = 40;
    int screenHeight = 24;

    renderRedScreen(screenWidth, screenHeight);
	
	int check;
	std::cin>>check;

    return 0;
}
