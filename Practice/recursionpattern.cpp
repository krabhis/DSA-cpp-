#include <iostream>

// Recursive function to print spaces
void printSpaces(int spaces) {
    if (spaces <= 0) {
        return;
    }
    std::cout << " ";
    printSpaces(spaces - 1);
}

// Recursive function to print stars
void printStars(int stars) {
    if (stars <= 0) {
        return;
    }
    std::cout << "* ";
    printStars(stars - 1);
}

// Recursive function to print each level of the pyramid
void printPyramid(int currentLevel, int totalLevels) {
    if (currentLevel > totalLevels) {
        return;
    }
    // Print leading spaces
    printSpaces(totalLevels - currentLevel);

    // Print stars
    printStars(currentLevel);

    // Move to the next line
    std::cout << std::endl;

    // Recur to the next level
    printPyramid(currentLevel + 1, totalLevels);
}

int main() {
    int totalLevels = 5;
    printPyramid(1, totalLevels);
    return 0;
}
