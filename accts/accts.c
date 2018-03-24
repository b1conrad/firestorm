#include <stdio.h>
#include <time.h>
#include "accts.h"

char *WhatFilename = "what-accts.txt";

void acctsHeader(char *title)
{
  printf("Content-type: text/html\n\n");
  printf("<HTML>\n");
  printf("<HEAD>\n");
  printf("<TITLE>%s</TITLE>\n",title);
  printf("</HEAD>\n");
  printf("<BODY>\n");
  printf("<H2>%s</H2>\n", title);
}

void acctsTrailer()
{
  printf("<h5>clock = %ld (%dths of a second)</h5>\n",
    clock(),
    CLOCKS_PER_SEC);
  printf("</body>\n");
  printf("</html>\n");
}

