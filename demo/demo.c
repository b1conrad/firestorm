#include <stdio.h>
#include "../fs.h"

void main()
{
  FS_panel p1;
  int err;

  FSopen();
  p1 = FSsetPanel(1);
  err = FSfirstRec(p1,1);
  while (err == FS_OK) {
    printf("Name: %s Count: %s\n",
      FSfield(p1,1)->field_data,
      FSfield(p1,2)->field_data);
    err = FSnextRec(p1);
  }
  FSclose();
}
