#include <stdio.h>
#include "../fs.h"

void main()
{
  FS_panel p1;
  int err;
  Field_Value *Demo = NewField(1,'9',4,"DEMO");
  Field_Value *One = NewField(2,'3',1,"1");

  FSopen();
  p1 = FSsetPanel(1);
  err = FSequalRec(p1,FSifList(p1,1,Demo));
  if (err == FS_OK) {
    err = FSupdateField(p1,FSifList(p1,1,Demo),2,'+',One);
  } else {
    err = FScreateRec(p1,FSfList(p1,Demo,One));
  }
  err = FSfirstRec(p1,1);
  printf("Content-type: text/html\n\n");
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
  printf("<a href=http://www.sanbachs.com/firestorm/>");
  printf("<font face=Arial>Powered by Sanbachs</font></a>\n");
  printf("</BODY>\n");
  printf("</HTML>\n");
  FSclose();
}
