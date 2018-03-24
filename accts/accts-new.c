#include <stdio.h>
#include "accts.h"

Field_Value *AC;
Field_Value *Balance;

FS_CGI_arg FSexpect[] = {
  { "AC", &AC, "12345"},
  { "Balance", &Balance, "1000"},
  NULL
};

int FSquery()
{
  FS_panel p1;
  int err;

  p1 = FSsetPanel(1);
  acctsHeader("Adding Account...");
  err = FScreateRec(p1,FSfList(p1,AC,Balance));
  if (err == FS_OK) {
    FSequalRec(p1,FSifList(p1,1,AC));
    printf("Account # %s created with balance %s.\n",
      FSfield(p1,1)->field_data,
      FSfield(p1,2)->field_data);
  } else {
    printf("Account # %s could not be created (err=%d).\n",
      AC->field_data, err);
  }
  acctsTrailer();
  return FS_OK;
}
