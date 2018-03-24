#include <stdio.h>
#include "../fs.h"

char *WhatFilename = "what-demo.txt";

Field_Value *Prefix;

FS_CGI_arg FSexpect[] = {
  { "Prefix", &Prefix, ""},
  NULL
};

int FSquery()
{
  FS_panel p1;
  int err;
  int recordCount;

  FSopen();
  p1 = FSsetPanel(1);
  err = FSsubFirstRec(p1,FSifList(p1,1,Prefix));
  recordCount = FSrecCount(p1);
  printf("Content-type: text/html\n\n");
  printf("<HTML>\n");
  printf("<HEAD>\n");
  printf("<TITLE>Demo 2</TITLE>\n");
  printf("</HEAD>\n");
  printf("<BODY>\n");
  if (recordCount == 0) {
    printf("No records matching \"%s\"<BR>\n",
      Prefix->field_data);
  } else {
    printf("%d record%s matching \"%s\"\n",
      recordCount, 
      (recordCount==1) ? "" : "s",
      Prefix->field_data);
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
      err = FSsubNextRec(p1);
    }
    printf("</table>\n");
  }
  printf("<a href=http://www.sanbachs.com/firestorm/>");
  printf("<font face=Arial>Powered by Sanbachs</font></a>\n");
  printf("</BODY>\n");
  printf("</HTML>\n");
  FSclose();
}
