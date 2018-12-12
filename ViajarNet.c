#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ViajarNet.h"

struct perfil {
  Usu *usu;
  Reg *reg;
};

struct rede {
  Perfil **perfis;
  int tamanho;
};

int sobreposta(Reg *reg, Info *info) {
  if(reg != NULL) {
    sobreposta(visita_esq_reg(reg), info);
    Info* atual = acessa_info_reg(reg);
    if(atual->dia == info->dia && atual->mes == info->mes && atual->ano == info->ano) {
      return 1;
    }
    sobreposta(visita_dir_reg(reg), info);
  }
}

Rede *nova_rede(int tamanho) {
  if(tamanho > 0) {
    Rede* rede = (Rede*) malloc(sizeof(Rede));
    rede->tamanho = tamanho;
    rede->perfis = (Perfil**) malloc(tamanho * sizeof(int*));
    return rede;
  }
  return NULL;
}

int add_perfil_rede(Rede *rede, Perfil *perfil) {
  if(rede != NULL && perfil != NULL) {
    int id; char nome[100];
    acessa_usu(perfil->usu, &id, nome);
    int n_perfis = numero_perfis_rede(rede);
    Perfil* t_perfil = recupera_perfil_rede(rede, id);
    if(t_perfil == NULL && n_perfis < rede->tamanho) {
      rede->perfis[n_perfis] = perfil;
      return 1;
    }
  }
  return 0;
}

Perfil *recupera_perfil_rede(Rede *rede, int id_usu) {
  int i = 0;
  while(rede->perfis[i] != NULL && i < rede->tamanho) {
    int id; 
    char nome[100];
    Perfil* atual = rede->perfis[i];
    acessa_usu(atual->usu, &id, nome);
    if(id == id_usu) {
      return atual;
    }
    i++;
  }
  return NULL;
}

int numero_perfis_rede(Rede *rede) {
  int i = 0;
  while(rede->perfis[i] != NULL) { i++; }
  return i;
}

Perfil *novo_perf(Usu *usu) {
  if(usu != NULL) {
    Perfil* perfil = (Perfil*) malloc(sizeof(Perfil));
    perfil->usu = usu;
    perfil->reg = NULL;
  }
  return NULL;
}

int libera_perf(Perfil **perfil) {
  if(*perfil != NULL) {
    libera_usu(&(*perfil)->usu);
    libera_reg(&(*perfil)->reg);
    free(*perfil);
    *perfil = NULL;
    return 1;
  }
  return 0;
}

Usu *acessa_usuario_perf(Perfil *perfil) {
  return perfil->usu;
}

int add_viagem_perf(Perfil *perfil, Info *info) {
  if(perfil == NULL || info == NULL) { return 0; }
  Reg* reg = novo_reg(info);
  if(perfil->reg == NULL) {
    perfil->reg = reg;
    return reg != NULL ? 1 : 0;
  } else {
    if(!sobreposta(perfil->reg, info)) {
      pos_insert(acessa_info_reg(perfil->reg), info) ? 
      add_dir_reg(perfil->reg, reg) : 
      add_esq_reg(perfil->reg, reg);
    }
  }
  return 0;
}

int remove_viagem_perf(Perfil *perfil, char *cod) {
  return 0;
}

Info *buscar_viagem_perf(Perfil *perfil, char *cod) {
  return NULL;
}

int numero_viagens_perf(Perfil *perfil) {
  return 0;
}

char *listar_todas_viagens_perf(int ordem, Perfil *perfil) {
  return NULL;
}

char *buscar_viagem_por_mes_perf(int ordem, Perfil *perfil, int mes) {
  return NULL;
}

char *buscar_viagem_por_ano_perf(int ordem, Perfil *perfil, int ano) {
  return NULL;
}

char *buscar_viagem_por_cidade_perf(int ordem, Perfil *perfil, char *cidade) {
  return NULL;
}

char *buscar_viagem_por_pais_perf(int ordem, Perfil *perfil, char *pais) {
  return NULL;
}
