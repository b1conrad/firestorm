#ifdef WIN32
#include "e:\engine\pba.h"
#else
#include "../pba.h"
#endif

/* Panel 1,  */

unsigned char panel1_pba[] = {
1,
16, 0,
8, 'd', 'e', 'm', 'o', '.', '0', '0', '1',
9, 1, 0, 1, 0, 0, 1, 1, 0, 0,
0,
5, 1, 9, 8, 0, 0,
5, 2, 3, 0, 8, 0,
0 };

unsigned char panel1_index1_fld[] = {1};

Index_Info panel1_index1 = {
1, 1, panel1_index1_fld
};

Index_Info *panel1_index[] = {
  &panel1_index1
};

unsigned char panel1_fld[] = {
1, 2};

Panel_Info panel[1] = {
{ 1, 2, "93", panel1_fld, 1, panel1_index, panel1_pba, &panel1_index1}
};

int panel_count = 1;

char *ind_name = "demo.ind";
char *txx_name = "demo.txx";
unsigned char sort_map[256] = {
0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
96, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 123, 124, 125, 126, 127,
93, 85, 69, 65, 92, 65, 95, 93, 69, 69, 69, 73, 73, 73, 92, 95,
69, 91, 91, 79, 94, 79, 85, 85, 89, 94, 85, 163, 164, 165, 166, 167,
65, 73, 79, 85, 78, 78, 65, 79, 168, 169, 170, 171, 172, 173, 174, 175,
176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191,
192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207,
208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223,
224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255
};

