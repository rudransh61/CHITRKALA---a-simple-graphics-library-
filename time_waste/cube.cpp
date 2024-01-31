#include <iostream>
#include <cstdlib>

#define WIDTH 40
#define HEIGHT 20

// ANSI escape codes
const char *redForegroundCode = "\033[31m";
const char *resetAttributesCode = "\033[0m";

const char *redBackgroundCode = "\033[41m";
void renderCube()
{
    // Clear the console
    system("cls");

    // Cube vertices
    int vertices[][3] = {
        {-5, -5, -5}, // Vertex 0
        {5, -5, -5},  // Vertex 1
        {5, 5, -5},   // Vertex 2
        {-5, 5, -5},  // Vertex 3
        {-5, -5, 5},  // Vertex 4
        {5, -5, 5},   // Vertex 5
        {5, 5, 5},    // Vertex 6
        {-5, 5, 5}    // Vertex 7
    };

    // Cube edges (indices of connected vertices)
    int edges[][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0}, // Bottom face
        {4, 5}, {5, 6}, {6, 7}, {7, 4}, // Top face
        {0, 4}, {1, 5}, {2, 6}, {3, 7}  // Connecting edges
    };

    // Project and render the cube
    char pixels[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            pixels[i][j] = ' '; // Initialize all pixels as empty space

    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); ++i)
    {
        int v1x = vertices[edges[i][0]][0];
        int v1y = vertices[edges[i][0]][1];
        int v1z = vertices[edges[i][0]][2];

        int v2x = vertices[edges[i][1]][0];
        int v2y = vertices[edges[i][1]][1];
        int v2z = vertices[edges[i][1]][2];

        // Project the 3D coordinates to 2D screen
        int screenX1 = v1x + v1z;
        int screenY1 = v1y + v1z;

        int screenX2 = v2x + v2z;
        int screenY2 = v2y + v2z;

        // Draw the edges
        if (v1x == v2x && v1y == v2y) // Vertical edge
        {
            int minY = std::min(screenY1, screenY2);
            int maxY = std::max(screenY1, screenY2);

            for (int y = minY; y <= maxY; ++y)
                pixels[y][screenX1] = '*';
        }
        else if (v1x == v2x && v1z == v2z) // Horizontal edge
        {
            int minY = std::min(screenY1, screenY2);
            int maxY = std::max(screenY1, screenY2);

            for (int y = minY; y <= maxY; ++y)
                pixels[y][screenX1] = '*';
        }
        else if (v1y == v2y && v1z == v2z) // Depth edge
        {
            int minX = std::min(screenX1, screenX2);
            int maxX = std::max(screenX1, screenX2);

            for (int x = minX; x <= maxX; ++x)
                pixels[screenY1][x] = '*';
        }
    }

    // Print the projection
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            if (pixels[i][j] == '*')
            {
                std::cout << redForegroundCode << redForegroundCode <<" "<< resetAttributesCode;
            }
            else
            {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}


int main()
{
    renderCube();
    char a;
    std::cin>>a;
    return 0;
}
