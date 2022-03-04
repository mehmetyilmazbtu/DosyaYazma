#include <stdio.h>
#include <stdlib.h>


    void main (int argc, char *argv[])
{
  FILE *fp1;
  char cdizi[80];

  if (argc!=2) {
      printf("Kullanım: deneme <Dosya1.txt>\n");
      exit(1);
  }

  if ((fp1=fopen(argv[1], "w")) == NULL) {
      printf("Dosya açılamadı!\n");
      exit(1);
  }

  do {
     printf("Bir karakter dizisi giriniz: ");
     gets(cdizi);
     strcat(cdizi, "\n");
     if (*cdizi!='\n') fputs(cdizi, fp1);
  } while (*cdizi!='\n');

  fclose (fp1);
  if ((fp1=fopen(argv[1], "r")) == NULL) {
      printf("Dosya açılamadı!\n");
      exit(1);
  }

  do {
     if (fgets(cdizi, 79, fp1)) printf(cdizi);
  } while (!feof(fp1));

  fclose (fp1);
}


