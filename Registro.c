#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Registro.h"

struct registro {
  Info info;
	Reg *esq;
	Reg *dir;
};

Reg *novo_reg(Info *info) {
  return NULL;
}

int libera_reg(Reg **reg) {
  return 0;
}

int atribui_info_reg(Reg *reg, Info *info) {
  return 0;
}

Info *acessa_info_reg(Reg *reg) {
  return 0;
}

int add_dir_reg(Reg *atual, Reg *dir) {
  return 0;
}

int add_esq_reg(Reg *atual, Reg *esq) {
  return 0;
}

Reg *visita_dir_reg(Reg *atual) {
  return NULL;
}

Reg *visita_esq_reg(Reg *atual) {
  return NULL;  
}

int tamanho_no() {
  return 0;
}
