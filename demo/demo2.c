#include <stdio.h>
#include "../fs.h"

void main()
{
  FS_panel p1;
  int err;

  FSopen();
  p1 = FSsetPanel(1);
  err = FSfirstRec(p1,1);
  printf("<HTML>\n");
  printf("<HEAD>\n");
  printf("<TITLE>Demo 2</TITLE>\n");
  printf("</HEAD>\n");
  printf("<BODY>\n");
  printf("<table border=1>\n");
  printf("<tr>\n");
  printf("<th align=left>Name</th>\n");
  printf("<th align=right>Count</th>\n");
  printf("</tr>\n");
  while (err == FS_OK) {
    printf("<tr>\n");
    printf("<td align=left>%s</td><td align=right>%s</td>\n",
      FSfield(p1,1)->field_data,
      FSfield(p1,2)->field_data);
    printf("</tr>\n");
    err = FSnextRec(p1);
  }
  printf("</table>\n");
  printf("</BODY>\n");
  printf("</HTML>\n");
  FSclose();
}
