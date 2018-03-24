#include <stdio.h>
#include "accts.h"

Field_Value *AC;

FS_CGI_arg FSexpect[] = {
  { "AC", &AC, "12345"},
  NULL
};

int FSquery()
{
  FS_panel p1;
  int err;

  p1 = FSsetPanel(1);
  acctsHeader("Account Balance...");
  err = FSequalRec(p1,FSifList(p1,1,AC));
  if (err == FS_OK) {
    printf("Account # %s has balance %s.\n",
      FSfield(p1,1)->field_data,
      FSfield(p1,2)->field_data);
  } else {
    printf("Account # %s could not be found (err=%d).\n",
      AC->field_data,
      err);
  }
  acctsTrailer();
  return FS_OK;
}
