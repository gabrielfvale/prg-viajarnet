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

Rede *nova_rede(int tamanho) {
  return NULL;
}

int add_perfil_rede(Rede *rede, Perfil *perfil) {
  return 0;
}


Perfil *recupera_perfil_rede(Rede *rede, int id_usu) {
  return NULL;
}

int numero_perfis_rede(Rede *rede) {
  return 0;
}

Perfil *novo_perf(Usu *usu) {
  return NULL;
}

int libera_perf(Perfil **perfil) {
  return 0;
}

Usu *acessa_usuario_perf(Perfil *perfil) {
  return NULL;
}


int add_viagem_perf(Perfil *perfil, Info *info) {
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
