#include <stdio.h>
#include "accts.h"

FS_CGI_arg FSexpect[] = {
  NULL
};

int FSquery()
{
  FS_panel p1;
  int err;

  p1 = FSsetPanel(1);
  acctsHeader("Account List...");
  err = FSfirstRec(p1,1);
  while (err == FS_OK) {
    printf("Account # %s has balance %s.\n",
      FSfield(p1,1)->field_data,
      FSfield(p1,2)->field_data);
    printf("<BR>\n");
    err = FSnextRec(p1);
  }
  acctsTrailer();
  return FS_OK;
}
