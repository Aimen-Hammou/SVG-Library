#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include "svg.h"


static void appendStringToSvg(svg *psvg, char *text)
{
    int l = strlen(psvg->svg) + strlen(text) + 1;

    //Preferisco creare una variabile diversa, così nel caso l'allocazione vada male non perdiamo il contenuto
    char *p = realloc(psvg->svg, l);

    if (p)
    {
        psvg->svg = p;
    }

    strcat(psvg->svg, text);
}

static void appendNumberToSvg(svg *psvg, int n)
{
    char sn[16];

    sprintf(sn, "%d", n);
    appendStringToSvg(psvg, sn);

}



svg *svg_create(int width, int height)
{

    svg *psvg = (svg*)malloc(sizeof(svg));

    if (psvg != NULL)
    {
        psvg->height = height;
        psvg->width = width;
        psvg->svg = NULL;
        psvg->finalized = false;

        psvg->svg = malloc(1);

        sprintf(psvg->svg, "%s", "\0");



        appendStringToSvg(psvg, "<svg width='");
        appendNumberToSvg(psvg, width);
        appendStringToSvg(psvg, "px' height='");
        appendNumberToSvg(psvg, height);
        appendStringToSvg(psvg, "px' xmlns='http://www.w3.org/2000/svg' version='1.1' xmlns:xlink='http://www.w3.org/1999/xlink'>\n");
        return psvg;
    }
    else
    {
        return NULL;
    }

}

void svg_print(svg *psvg)
{
    printf("%s", psvg->svg);
    return;
}


void svg_finalize(svg *psvg)
{
    appendStringToSvg(psvg, "</svg>");
    psvg->finalized = true;
}


void svg_rectangle(svg* psvg,
                   int width, int height,
                   int x, int y,
                   char* fill,
                   char* stroke, int strokewidth,
                   int radiusx, int radiusy)
{
    appendStringToSvg(psvg, "   <rect fill='");
    appendStringToSvg(psvg, fill);
    appendStringToSvg(psvg, "' stroke='");
    appendStringToSvg(psvg, stroke);
    appendStringToSvg(psvg, "' stroke-width='");
    appendNumberToSvg(psvg, strokewidth);
    appendStringToSvg(psvg, "px' width='");
    appendNumberToSvg(psvg, width);
    appendStringToSvg(psvg, "' height='");
    appendNumberToSvg(psvg, height);
    appendStringToSvg(psvg, "' y='");
    appendNumberToSvg(psvg, y);
    appendStringToSvg(psvg, "' x='");
    appendNumberToSvg(psvg, x);
    appendStringToSvg(psvg, "' ry='");
    appendNumberToSvg(psvg, radiusy);
    appendStringToSvg(psvg, "' rx='");
    appendNumberToSvg(psvg, radiusx);
    appendStringToSvg(psvg, "' />\n");
}

void svg_circle(svg* psvg, char* stroke, int strokewidth, char* fill, int r, int cx, int cy)
{
    appendStringToSvg(psvg, "    <circle stroke='");
    appendStringToSvg(psvg, stroke);
    appendStringToSvg(psvg, "' stroke-width='");
    appendNumberToSvg(psvg, strokewidth);
    appendStringToSvg(psvg, "px' fill='");
    appendStringToSvg(psvg, fill);
    appendStringToSvg(psvg, "' r='");
    appendNumberToSvg(psvg, r);
    appendStringToSvg(psvg, "' cy='");
    appendNumberToSvg(psvg, cy);
    appendStringToSvg(psvg, "' cx='");
    appendNumberToSvg(psvg, cx);
    appendStringToSvg(psvg, "' />\n");
}

void svg_line(svg* psvg, char* stroke, int strokewidth, int x1, int y1, int x2, int y2)
{
    appendStringToSvg(psvg, "    <line stroke='");
    appendStringToSvg(psvg, stroke);
    appendStringToSvg(psvg, "' stroke-width='");
    appendNumberToSvg(psvg, strokewidth);
    appendStringToSvg(psvg, "px' y2='");
    appendNumberToSvg(psvg, y2);
    appendStringToSvg(psvg, "' x2='");
    appendNumberToSvg(psvg, x2);
    appendStringToSvg(psvg, "' y1='");
    appendNumberToSvg(psvg, y1);
    appendStringToSvg(psvg, "' x1='");
    appendNumberToSvg(psvg, x1);
    appendStringToSvg(psvg, "' />\n");
}

void svg_text(svg* psvg, int x, int y, char* fontfamily, int fontsize, char* fill, char* stroke, char* text)
{
    appendStringToSvg(psvg, "    <text x='");
    appendNumberToSvg(psvg, x);
    appendStringToSvg(psvg, "' y = '");
    appendNumberToSvg(psvg, y);
    appendStringToSvg(psvg, "' font-family='");
    appendStringToSvg(psvg, fontfamily);
    appendStringToSvg(psvg, "' stroke='");
    appendStringToSvg(psvg, stroke);
    appendStringToSvg(psvg, "' fill='");
    appendStringToSvg(psvg, fill);
    appendStringToSvg(psvg, "' font-size='");
    appendNumberToSvg(psvg, fontsize);
    appendStringToSvg(psvg, "px'>");
    appendStringToSvg(psvg, text);
    appendStringToSvg(psvg, "</text>\n");
}


void svg_ellipse(svg* psvg, int cx, int cy, int rx, int ry, char* fill, char* stroke, int strokewidth)
{
    appendStringToSvg(psvg, "    <ellipse cx='");
    appendNumberToSvg(psvg, cx);
    appendStringToSvg(psvg, "' cy='");
    appendNumberToSvg(psvg, cy);
    appendStringToSvg(psvg, "' rx='");
    appendNumberToSvg(psvg, rx);
    appendStringToSvg(psvg, "' ry='");
    appendNumberToSvg(psvg, ry);
    appendStringToSvg(psvg, "' fill='");
    appendStringToSvg(psvg, fill);
    appendStringToSvg(psvg, "' stroke='");
    appendStringToSvg(psvg, stroke);
    appendStringToSvg(psvg, "' stroke-width='");
    appendNumberToSvg(psvg, strokewidth);
    appendStringToSvg(psvg, "' />\n");
}

void svg_fill(svg* psvg, char* Fill)
{
    svg_rectangle(psvg, psvg->width, psvg->height, 0, 0, Fill, Fill, 0, 0, 0);
}

void svg_save(svg *psvg, char *filepath)
{
    if(!psvg->finalized)
    {
        svg_finalize(psvg);
    }

    FILE *fp;

    fp = fopen(filepath, "w");
    if(fp != NULL)
    {
        fwrite(psvg->svg, sizeof(char), strlen(psvg->svg), fp);
        fclose(fp);
    }

    printf("%s", psvg->svg);

}

//Meglio tenerla esterna piuttosto che metterla dentro save.
void svg_free(svg *psvg)
{
    free(psvg->svg);
    free(psvg);
}
