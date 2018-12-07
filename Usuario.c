#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"

struct usuario {
	int id;
	char nome[31];
};


Usu *novo_usu(int id, char *nome) {
	/* Checa por valores válidos e aloca Usu */
  if(id > 0 && strlen(nome) <= 30) {
    Usu* usr = (Usu*) malloc(sizeof(Usu));
    usr->id = id;
    strcpy(usr->nome, nome);
    return usr;
  }
  return NULL;
}

int libera_usu(Usu **usu) {
  if(*usu != NULL){
    free(*usu);
    *usu = NULL;
    return 1;
  }
  return 0;
}

int acessa_usu(Usu *usu, int *id, char *nome) {
  *id = usu->id;
  strcpy(nome, usu->nome);
  /* Checa se de fato houve a mudança das variáveis */
  if(*id == usu->id && strcmp(nome, usu->nome)) {
    return 1;
  }
  return 0;
}

int atribui_usu(Usu *usu, int id, char *nome) {
  /* Checa por valores válidos */
  if(id > 0 && strlen(nome) <= 30) {
    usu->id = id;
    strcpy(usu->nome, nome);
    return 1;
  }
  return 0;
}

int tamanho_usu() {
  return sizeof(Usu);
}
