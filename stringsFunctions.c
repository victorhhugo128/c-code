#include <stdio.h>
#include <stdlib.h>

int tamanhoString(char string[]){
  int i;

  while(string[i] != '\0'){
    i++;
  }

  return i;
}

void rmv_cadeia(char F[], int inicio, int numcar){
  int i = 0, j = 0, s;
  char R[50];

  while( F[i] != '\0'){
    if(i < inicio + numcar && i >= inicio){
      i++;
      continue;
    }
    R[j] = F[i];
    i++;
    j++;
  }

  R[j] = '\0';

  i = 0;
  j = 0;

  while( R[i] != '\0'){
    F[j] = R[i];
    i++;
    j++;
  }

  F[j] = '\0';
}

void subcadeia(char string[], int inicio, int nChar, char vetorDestino[]){
  int i, j = 0;

  for(i = inicio; i < inicio + nChar; i++){
    vetorDestino[j] = string[i];
    j++;
  }

  vetorDestino[j] = '\0';

}

void ins_cadeia(char texto[], char cadeia[], int posicao){
  int i = 0, j = 0;
  char intermediario[50];

  while(i != posicao){
    intermediario[i] = texto[i];
    i++;
  }
  while(cadeia[j] != '\0'){
    intermediario[i] = cadeia[j];
    i++;
    j++;
  }
  j = posicao;
  while(texto[j] != '\0'){
    intermediario[i] = texto[j];
    i++;
    j++;
  }
  intermediario[i] = '\0';

  i = 0;

  while(intermediario[i] != '\0'){
    if(texto[i] == '\0'){
      texto[i] = '0';
    }
    texto[i] = intermediario[i];
    i++;
  }

  texto[i] = '\0';
  }

void subst_cadeia(char sFonte[], char string1[], char string2[]){
  int i, j = 0, contagem = 0, tamanho1 = tamanhoString(string1), inicio = -1;
  char intermediario1[50], intermediario2[50];

  for(i = 0; i < tamanhoString(sFonte); i++){
    if(sFonte[i] == string1[j]){
      if(inicio == -1){
        inicio = i;
      }
      contagem++;
      j++;
    }
  }

  printf("funcionou ate aqui");
  
  if(contagem != tamanho1){
    printf("Não foi achada uma string correspondente...");
    exit(0);
  }

  else{
    rmv_cadeia(sFonte, inicio, tamanho1);
    
    int tamFonte = tamanhoString(sFonte);

    j = 0;
    
    for(i = 0; i < inicio; i++){
      intermediario1[i] = sFonte[j];
      j++;
    }

    intermediario1[i] = '\0';

    for(i = 0; i < tamFonte - inicio; i++){
      intermediario2[i] = sFonte[j];
      j++;
      
      printf("j = %i\nintermediario1 = %s\n\n", j, intermediario1);
    }
    
   
    intermediario2[i] = '\0';
    
	printf("nIntermediario2 = %s\n\n", intermediario2);



    i = 0;
    j = 0;
    while(intermediario1[i] != '\0'){
      sFonte[j] = intermediario1[i];
      i++;
      j++;
    }

    i = 0;
    
    while(string2[i] != '\0'){
      if(sFonte[j] == '\0'){
        sFonte[j] = '0';
      }
      sFonte[j] = string2[i];
      i++;
      j++;
    }

    i = 0;
    
    printf("%s", intermediario2);
    
    while(intermediario2[i] != '\0'){
      if(sFonte[j] == '\0'){
        sFonte[j] = '0';
      }
      sFonte[j] = intermediario2[i];
      i++;
      j++;
      
      printf("a\n\n");
    }

    sFonte[j] = '\0';
    
  }

  
}

int main(void) {
  char string1[] = "UFPABRASIL", string2[10];

  subst_cadeia(string1, "BRAS", "zzzz");

  printf("%s", string1);
  
  return 0;
}