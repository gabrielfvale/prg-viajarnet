#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ViajarNet.h"

int testa_rede() {
	Rede* r = nova_rede(3);
	if(r != NULL) {
		return 1;
	}
	return 0;
}

int testa_novo_perfil() {
  int id;
  char nome[100];
  Usu *usu = NULL;
  
  scanf("%d", &id);
  scanf("%s", nome);

  usu = novo_usu(id, nome);

  Perfil* perf = novo_perf(usu);

  if(perf != NULL) {
    return 1;
  }

  return 0;
}

int testa_add_perfil() {
  int id;
  char nome[100];
  Usu *usu = NULL;
  
  scanf("%d", &id);
  scanf("%s", nome);

  usu = novo_usu(id, nome);

  Perfil* perf = novo_perf(usu);
  Rede* rede = nova_rede(3);
  return add_perfil_rede(rede, perf);
}

int testa_recupera_perfil() {
  int id;
  char nome[100];
  Usu *usu = NULL;
  
  scanf("%d", &id);
  scanf("%s", nome);

  usu = novo_usu(id, nome);

  Perfil* perf = novo_perf(usu);
  Rede* rede = nova_rede(3);
  add_perfil_rede(rede, perf);
  Perfil* puta = recupera_perfil_rede(rede, id);
  if(puta != NULL) {
    return 1;
  }
  return 0;
}

int testa_add_viagem() {
  int id;
  char nome[100];
  Usu *usu = NULL;
  
  scanf("%d", &id);
  scanf("%s", nome);

  usu = novo_usu(id, nome);

  Perfil* perf = novo_perf(usu);
  Rede* rede = nova_rede(3);
  add_perfil_rede(rede, perf);

  Info info;
  scanf("%s", &info.cod);
  scanf("%d", &info.dia);
  scanf("%d", &info.mes);
  scanf("%d", &info.ano);
  scanf("%s", info.cidade);
  scanf("%s", info.pais);
  scanf("%d", &info.periodo);

  return add_viagem_perf(perf, &(info));
}

int main(void) {
  int op;
  scanf("%d", &op);
  
  switch(op) {
    case 1: printf("%d", testa_rede());
            break;
    case 2: printf("%d", testa_novo_perfil());
            break;
    case 3: printf("%d", testa_add_perfil());
            break;
    case 4: printf("%d", testa_recupera_perfil());
            break;
    case 5: printf("%d", testa_add_viagem());
            break;
  }
	return 0;
}
