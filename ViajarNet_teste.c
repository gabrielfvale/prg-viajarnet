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

int testa_add_perfil() {

}

int testa_recupera_perfil() {
	
}

int main(void) {
  int op;
  scanf("%d", &op);
  
  switch(op) {
    case 1: printf("%d", testa_rede());
            break;
    case 1: printf("%d", testa_rede());
            break;
    case 1: printf("%d", testa_rede());
            break;
    case 1: printf("%d", testa_rede());
            break;
  }
	return 0;
}
