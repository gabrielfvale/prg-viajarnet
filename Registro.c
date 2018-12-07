#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Registro.h"

struct registro {
  Info info;
  Reg *esq;
  Reg *dir;
};

int info_check(Info *info) {
  /* Checagens básicas de data */
  if(info->mes < 1 || info->mes > 12 ||
     info->dia < 1 || info->dia > 31 ||
     info->ano <= 0) { return 0;}
  /* Checagens de tamanho de strings */
  if(strlen(info->cod) != 1 || *info->cod <= '0' ||
     strlen(info->cidade) < 1 && strlen(info->cidade) > 60 ||
     strlen(info->pais) < 1 && strlen(info->pais) > 30) {
    return 0;
  }
  /* 
  Checagem detalha da data, onde meses pares possuem no máximo 30 dias.
  Este comportamento inverte em Julho.
  */
  if(info->mes % 2 == 0 && info->mes < 8) {
    return info->dia <= 30 ? 1 : 0;
  } else if(info->mes % 2 != 0 && info->mes > 7) {
    return info->dia <= 30 ? 1 : 0;
  }
  return 1;
}

int pos_insert(Info *e, Info *n) {
  /* Retorna 1 se o nó deve ser inserido à direita, e 0 se à esquerda. */
  if(n->ano > e->ano) {
    return 1;
  } else if (n->ano == e->ano) {
    int diff = ((n->mes - 1) * 30 + n->dia) - ((e->mes - 1) * 30 + e->dia);
    return diff > 0 ? 1 : 0;
  } else {
    return 0;
  }
}

Reg *novo_reg(Info *info) {
  if(info_check(info)) {
    Reg* reg = (Reg*) malloc(sizeof(Reg));
    reg->info = *info;
    reg->esq = NULL;
    reg->dir = NULL;
    return reg;
  }
  return NULL;
}

int libera_reg(Reg **reg) {
  if(*reg != NULL) {
    libera_reg(&(*reg)->esq);
    libera_reg(&(*reg)->dir);
    free(*reg);
    *reg = NULL;
    return 1;
  }
  return 0;
}

int atribui_info_reg(Reg *reg, Info *info) {
  if(info_check(info)) {
    reg->info = *info;
    return 1;
  }
  return 0;
}

Info *acessa_info_reg(Reg *reg) {
  if(reg != NULL) {
    return &(reg->info);
  }
  return NULL;
}

int add_dir_reg(Reg *atual, Reg *dir) {
  if(atual != NULL) {
    if(atual->dir == NULL) {
      atual->dir = dir;
      return 1;
    } else {
      /* Recursivamente adiciona no filho  */
      pos_insert(&(atual->dir->info), &(dir->info)) ? add_dir_reg(atual->dir, dir) : add_esq_reg(atual->dir, dir);
    }
  }
  return 0;
}

int add_esq_reg(Reg *atual, Reg *esq) {
  if(atual != NULL) {
    if(atual->esq == NULL) {
      atual->esq = esq;
      return 1;
    } else {
      /* Recursivamente adiciona no filho  */
      pos_insert(&(atual->esq->info), &(esq->info)) ? add_dir_reg(atual->esq, esq) : add_esq_reg(atual->esq, esq);
    }
  }
  return 0;
}

Reg *visita_dir_reg(Reg *atual) {
  if(atual != NULL) {
    return atual->dir;
  }
  return NULL;
}

Reg *visita_esq_reg(Reg *atual) {
  if(atual != NULL) {
    return atual->esq;
  }
  return NULL;
}

int tamanho_reg() {
  /* Anteriormente estava tamanho_no() */
  return sizeof(Reg);
}
