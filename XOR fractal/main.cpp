#include <graphics.h>
#include <stdio.h>

void XORfractal(int x, int y);
float max_iterations;
float multiplier;

int main(void) {
    printf("Max iterations: ");
    scanf("%f", &max_iterations);
    printf("\nMultiplier (1 for normal): ");
    scanf("%f", &multiplier);

    int gd = DETECT, gm;
    char drive[] = "";
    initgraph(&gd, &gm, drive);

    int x = getmaxx();
    int y = getmaxy();
    XORfractal(x, y);

    getch();
    closegraph();
    return 0;
}

void XORfractal(int weight, int height) {
    for (int x = 0; x <= weight; x++) {
        for (int y = 0; y <= height; y++) {
            int z = x ^ y;

            double multi = multiplier * multiplier;
            double color = z * multi * max_iterations;

            //bug fix
            if (multiplier > 1) {
                putpixel(x, y, color+RED);
            } putpixel(x, y, color);
        }
    }
}
