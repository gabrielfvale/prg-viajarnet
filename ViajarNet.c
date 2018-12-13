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

// Funções de auxílio
int sobreposta(Reg *reg, Info *info) {
  if(reg != NULL) {
    sobreposta(visita_esq_reg(reg), info);
    Info* atual = acessa_info_reg(reg);
    if(atual->dia == info->dia && 
       atual->mes == info->mes && 
       atual->ano == info->ano) {
      return 1;
    }
    sobreposta(visita_dir_reg(reg), info);
  }
}

Info *percurso_ordem(Reg *reg, char *cod) {
  if(reg != NULL){
    percurso_ordem(visita_esq_reg(reg), cod);
    Info* info_no = acessa_info_reg(reg);
    if(!strcmp(info_no->cod, cod)) return info_no;
    percurso_ordem(visita_esq_reg(reg), cod);
  }
}

int percuso_viagens(Reg *reg) {
  if(reg != NULL){
    return 
    percuso_viagens(visita_esq_reg(reg)) + 
    percuso_viagens(visita_dir_reg(reg)) + 1;
  }
  return 0;
}

void percurso_ordem_tipo(int ordem, Reg *reg, char *resultado, int tipo, int data, char *local) {
  int comparacao;
  Info *info = acessa_info_reg(reg);
  if(info == NULL) return; // Para a função caso info seja nulo.

  switch(tipo) {
    case 1: // Todos
      comparacao = 1; break;
    case 2: // Mes
      comparacao = (info->mes == data); break;
    case 3: // Ano
      comparacao = (info->ano == data); break;
    case 4: // Cidade
      comparacao = (!strcmp(info->cidade, local)); break;
    case 5: // País
      comparacao = (!strcmp(info->pais, local)); break;
  }
  
  switch(ordem) {
    case 1:
      if(comparacao) strcat(resultado, strcat(info->cod, " | "));
      percurso_ordem_tipo(ordem, visita_esq_reg(reg), resultado, tipo, data, local);
      percurso_ordem_tipo(ordem, visita_dir_reg(reg), resultado, tipo, data, local);
    break;
    case 2:
      percurso_ordem_tipo(ordem, visita_esq_reg(reg), resultado, tipo, data, local);
      if(comparacao) strcat(resultado, strcat(info->cod, " | "));
      percurso_ordem_tipo(ordem, visita_dir_reg(reg), resultado, tipo, data, local);
    break;
    case 3:
      percurso_ordem_tipo(ordem, visita_esq_reg(reg), resultado, tipo, data, local);
      percurso_ordem_tipo(ordem, visita_dir_reg(reg), resultado, tipo, data, local);
      if(comparacao) strcat(resultado, strcat(info->cod, " | "));
    break;
  }
}


// Funções predefinidas
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
  while(rede->perfis[i] != NULL) i++;
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
  if(perfil == NULL || info == NULL) return 0;
  Reg* reg = novo_reg(info);
  if(perfil->reg == NULL) {
    perfil->reg = reg;
    return reg != NULL ? 1 : 0;
  } else {
    if(!sobreposta(perfil->reg, info)) {
      nodecmp(acessa_info_reg(perfil->reg), info) ? 
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
  Reg* raiz = perfil->reg;
  return percurso_ordem(raiz, cod);
}

int numero_viagens_perf(Perfil *perfil) {
  return percuso_viagens(perfil->reg);
}

char *listar_todas_viagens_perf(int ordem, Perfil *perfil) {
  int tam = (numero_viagens_perf(perfil) * 4) + 1;
  char *resultado = (char*) malloc(tam * sizeof(char));
  strcpy(resultado, " | ");

  percurso_ordem_tipo(ordem, perfil->reg, resultado, 1, 0, NULL);
  if(!strcmp(resultado, " | ")) return NULL;
  return resultado;
}

char *buscar_viagem_por_mes_perf(int ordem, Perfil *perfil, int mes) {
  int tam = (numero_viagens_perf(perfil) * 4) + 1;
  char *resultado = (char*) malloc(tam * sizeof(char));
  strcpy(resultado, " | ");

  percurso_ordem_tipo(ordem, perfil->reg, resultado, 2, mes, NULL);
  if(!strcmp(resultado, " | ")) return NULL;
  return resultado;
}

char *buscar_viagem_por_ano_perf(int ordem, Perfil *perfil, int ano) {
  int tam = (numero_viagens_perf(perfil) * 4) + 1;
  char *resultado = (char*) malloc(tam * sizeof(char));
  strcpy(resultado, " | ");

  percurso_ordem_tipo(ordem, perfil->reg, resultado, 3, ano, NULL);
  if(!strcmp(resultado, " | ")) return NULL;
  return resultado;
}

char *buscar_viagem_por_cidade_perf(int ordem, Perfil *perfil, char *cidade) {
  int tam = (numero_viagens_perf(perfil) * 4) + 1;
  char *resultado = (char*) malloc(tam * sizeof(char));
  strcpy(resultado, " | ");

  percurso_ordem_tipo(ordem, perfil->reg, resultado, 4, 0, cidade);
  if(!strcmp(resultado, " | ")) return NULL;
  return resultado;
}

char *buscar_viagem_por_pais_perf(int ordem, Perfil *perfil, char *pais) {
  int tam = (numero_viagens_perf(perfil) * 4) + 1;
  char *resultado = (char*) malloc(tam * sizeof(char));
  strcpy(resultado, " | ");

  percurso_ordem_tipo(ordem, perfil->reg, resultado, 5, 0, pais);
  if(!strcmp(resultado, " | ")) return NULL;
  return resultado;
}
