#include <stdio.h>
#include <stdbool.h> // C99, defines bool, true, false

// line styles
#define SOLID 0
#define DOTTED 1
#define DASHED 2

// primary colors
#define BLUE 4
#define GREEN 2
#define RED 1

// mixed colors
#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGNETA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char * colors[8] = {"black", "red", "green", "yellow", "blue", "magneta", "cyan", "white"};

struct boxProps {
    bool opaque : 1;
    unsigned int fillColor : 3;
    unsigned int : 4;
    bool showBorder : 1;
    unsigned int borderColor : 3;
    unsigned int borderStyle : 2;
    unsigned int :2;
};

void showSettings(const struct boxProps *pb);

int main(void) {
    // create and initialize boxProps structure
    struct boxProps box = {true, YELLOW, true, GREEN, DASHED};

    printf("Original box settings:\n");
    showSettings(&box);

    box.opaque = false;
    box.fillColor = WHITE;
    box.borderColor = MAGNETA;
    box.borderStyle = SOLID;

    printf("Modified box settings:\n");
    showSettings(&box);
    
    return 0;
}

void showSettings(const struct boxProps *pb) {
    printf("Box is %s.\n", pb->opaque == true ? "opaque": "transparent");
    printf("The fill color is %s.\n", colors[pb->fillColor]);
    printf("Border %s.\n", pb->showBorder == true ? "shown": "not shown");
    printf("The border color is %s.\n", colors[pb->borderColor]);
    printf("The border style is ");

    switch (pb->borderStyle) {
    case SOLID:
        printf("solid.\n");
        break;
    case DOTTED:
        printf("dotted.\n");
        break;
    case DASHED:
        printf("dashed.\n");
        break;   
    default:
        printf("Unknown type.\n");
        break;
    }
}