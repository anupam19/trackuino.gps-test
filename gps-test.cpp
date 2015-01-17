#include <stdio.h>
#include <stdlib.h>
#include "gps.h"

int main(int argc, char **argv)
{
  FILE *fgps;
  int c;
  int valid_pos;

  if (argc <= 1) {
    fprintf(stderr, "Usage: gps-test file.txt\n");
    exit(1);
  }

  fgps = fopen(argv[1], "r");

  gps_setup();

  while ((c = fgetc(fgps)) != EOF) {
    valid_pos = gps_decode(c);
    if (valid_pos) {
      printf("time=%s, pos=%f,%f\n", gps_time, gps_lat, gps_lon);
    }
  }
}

