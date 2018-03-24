#include <stdio.h>
#include "accts.h"

Field_Value *AC;
Field_Value *Amount;

FS_CGI_arg FSexpect[] = {
  { "AC", &AC, "12345"},
  { "Amount", &Amount, "1000"},
  NULL
};

int FSquery()
{
  FS_panel p1;
  int err;

  p1 = FSsetPanel(1);
  acctsHeader("Account Withdrawal...");
  err = FSequalRec(p1,FSifList(p1,1,AC));
  if (err == FS_OK) {
    err = FSupdateField(p1,FSifList(p1,1,AC),2,'-',Amount);
    if (err == FS_OK) {
      err = FSequalRec(p1,FSifList(p1,1,AC));
      printf("Withdrew $%s from # %s.\n",
	Amount->field_data,
	FSfield(p1,1)->field_data);
      if (*(FSfield(p1,2)->field_data) == '-') {
	printf("Account is overdrawn.\n");
      } else {
	printf("New balance is %s.\n",
	  FSfield(p1,2)->field_data);
      }
    } else {
      printf("Cannot withdraw $%s from # %s.\n",
	Amount->field_data,
	AC->field_data);
    }
  } else {
    printf("Account # %s could not be found (err=%d).\n",
      AC->field_data,
      err);
  }
  acctsTrailer();
  return FS_OK;
}
