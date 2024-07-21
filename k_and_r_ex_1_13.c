#include <stdio.h>


#define MAXLEN 15

int a[MAXLEN+2];

int main() {
  int c;
  int curr_word_length = 0;
  while ((c=getchar()) != EOF) {
    if (c==' ' || c=='\n' || c=='\t') {
      if (curr_word_length > 0) {
        if (curr_word_length > MAXLEN) a[MAXLEN+1]++; else a[curr_word_length]++;
      }
      curr_word_length = 0;
    } else {
      curr_word_length++;
    }
  }

  for (int i=1;i<=MAXLEN;i++) {
    printf("len(%d) -> %d\n", i, a[i]);
  }
  printf("len(>%d) -> %d\n", MAXLEN, a[MAXLEN+1]);

  return 0;
}
