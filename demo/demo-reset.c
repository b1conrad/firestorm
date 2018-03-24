#include <stdio.h>
#include "../fs.h"

void main()
{
  FS_panel p1;
  int err;
  Field_Value *Demo = NewField(1,'9',4,"DEMO");

  FSopen();
  p1 = FSsetPanel(1);
  err = dpe_DeleteRec(p1->pba,FSifList(p1,1,Demo));
  printf("Content-type: text/html\n\n");
  printf("<HTML>\n");
  printf("<HEAD>\n");
  printf("<TITLE>Demo 2</TITLE>\n");
  printf("</HEAD>\n");
  printf("<BODY>\n");
  if (err == FS_OK) {
    printf("Thank you!\n");
  } else {
    printf("Error deleting DEMO record: %d\n", err);
  }
  printf("<BR>\n");
  printf("<a href=http://www.sanbachs.com/firestorm/>");
  printf("<font face=Arial>Powered by Sanbachs</font></a>\n");
  printf("</BODY>\n");
  printf("</HTML>\n");
  FSclose();
}
