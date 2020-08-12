#include <stdio.h>
#include <stdlib.h>
#include "svg.h"


void drawRectangles(void);
void drawallshapes(void);

int main()
{
    //drawRectangles();
    drawallshapes();
    return 0;
}


void drawallshapes(void)
{
    svg* psvg;
    psvg = svg_create(192, 320);

    if(psvg == NULL)
    {
        puts("psvg is NULL");
    }
    else
    {
        svg_fill(psvg, "#DADAFF");

        svg_text(psvg, 32, 32, "sans-serif", 16, "#000000", "#000000", "drawallshapes");
        svg_circle(psvg, "#000080", 4, "#0000FF", 32, 64, 96);
        svg_ellipse(psvg, 64, 160, 32, 16, "#FF0000", "#800000", 4);

        svg_line(psvg, "#000000", 2, 32, 192, 160, 192);

        svg_rectangle(psvg, 64, 64, 32, 224, "#00FF00", "#008000", 4, 4, 4);

        svg_finalize(psvg);
        svg_print(psvg);
        svg_save(psvg, "allshapes.svg");
        svg_free(psvg);
    }
}

void drawRectangles(void)
{
    svg *psvg;

    psvg = svg_create(512, 512);

    if(psvg == NULL)
    {
        printf("PSVG IS NULL");
    }
    else
    {
        svg_rectangle(psvg, 512, 512, 0, 0, "white", "white", 0, 0, 0);

        svg_rectangle(psvg, 384, 384, 64, 64, "#00FF00", "#000000", 4, 0, 0);
        svg_rectangle(psvg, 320, 320, 96, 96, "#FFFF00", "#000000", 2, 8, 8);
        svg_rectangle(psvg, 256, 256, 128, 128, "#00FFFF", "#000000", 2, 8, 8);
        svg_rectangle(psvg, 192, 192, 160, 160, "#FF80FF", "#000000", 2, 8, 8);

        svg_finalize(psvg);
        svg_save(psvg, "rectangles.svg");

        svg_free(psvg);
    }

}
