#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generaCasuale(int dim, int m[][dim]) {
  srand(time(NULL));
  int i, j;

  for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      m[i][j] = (rand() % dim - 1) + 1;
    }
  }
}

void stampaCSV(int dim, int m[][dim]) {
  FILE *fp;
  fp = fopen("matrici.csv", "w");
  int i, j;

  for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      fprintf(fp, "%d,", m[i][j]);
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
}
void stampaMatrice(int dim, int m[][dim]) {
  int i, j;

  for (i = 0; i < dim; i++) {
    printf("\nRiga:");
    for (j = 0; j < dim; j++) {
      printf("%d\t", m[i][j]);
    }
  }
  printf("\n\n");
}

void leggiCSV(FILE *fp, int dim) {
  fp = fopen("matrici.csv", "r");
  int m[dim][dim];
  int i=0 , j;

  if (fp == NULL) {
    printf("Errore nell'apertura del file.\n");
  }

 ssize_t read;
  char* line=NULL;
  size_t len=0;

  while((read=getline(&line,&len,fp))!=-1){
    char* token=strtok(line, ",");
    
    for (j = 0; j < dim; j++) {
      m[i][j]=atoi(token);
     token=strtok(NULL,",");
    }
  i++;
    
  }
  stampaMatrice(dim, m);
  fclose(fp);
}

int main(void) {
  int scelta, dim;

  printf("inserire la dimensione della matrice\n");
  scanf("%d", &dim);
  printf("\n\n");

  int m[dim][dim];

  do {
    printf("inserire l'operazione da eseguire\t");
    scanf("%d", &scelta);

    switch (scelta) {
    case 1:
      generaCasuale(dim, m);
      break;

    case 2:
      stampaCSV(dim, m);
      break;

    case 3: {
      FILE *fp;
      leggiCSV(fp, dim);
    } break;
    }

  } while (scelta != 0);
}