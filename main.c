#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Usuario.h"
#include "Registro.h"



int testa_novo_usu() {
  int id;
  char nome[100];
  Usu *usu = NULL;
  
  scanf("%d", &id);
  scanf("%s", nome);

  usu = novo_usu(id, nome);
  if(usu != NULL) {
    return 1;
  }
  
  return 0;
}

int testa_libera_usu() {
  int id;
  char nome[100];
  Usu *usu = NULL;
  
  if(libera_usu(&usu) == 1) {
    return 0;
  }
  
  scanf("%d",&id);
  scanf("%s",nome);
  usu = novo_usu(id, nome);
  
  if(usu != NULL) {
    if(libera_usu(&usu) == 1 && usu == NULL) {
        return 1;
    }
  }
  
  return 0;
}

int testa_acessa_usu() {
  int id, id2;
  char nome[100], nome2[80];
  Usu *usu = NULL;
  
  scanf("%d",&id);
  scanf("%s",nome);
  
  if(acessa_usu(usu, &id, nome) == 1) {
    return 0;
  }
  
  usu = novo_usu(id, nome);
  
  if(usu != NULL) {
    if(acessa_usu(usu, &id2, nome2) == 1) {
      if(id == id2 && strcmp(nome, nome2) == 0) {
        return 1;
      }
    }
  }
  return 0;
}

int testa_atribui_usu() {
  int id, id2;
  char nome[100], nome2[80];
  Usu *usu = NULL;
  
  scanf("%d",&id);
  scanf("%s",nome);
  
  if(atribui_usu(usu, id, nome) == 1) {
    return 0;
  }
  
  usu = novo_usu(id, nome);
  if(usu != NULL) {
    if(atribui_usu(usu, id, nome) == 1) {
      if(acessa_usu(usu, &id2, nome2) == 1) {
        if(id == id2 && strcmp(nome, nome2) == 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}

int testa_novo_reg() {
  Info info;
  Reg *reg = NULL;
  
  scanf("%s", &info.cod);
	scanf("%d", &info.dia);
	scanf("%d", &info.mes);
	scanf("%d", &info.ano);
	scanf("%s", info.cidade);
	scanf("%s", info.pais);
	scanf("%d", &info.periodo);
	
	reg = novo_reg(&info);
	if(reg != NULL) {
	  return 1;
	}
	
  return 0;
}

int testa_libera_reg() {
  Info info;
  Reg *reg = NULL;
  
  scanf("%s", &info.cod);
	scanf("%d", &info.dia);
	scanf("%d", &info.mes);
	scanf("%d", &info.ano);
	scanf("%s", info.cidade);
	scanf("%s", info.pais);
	scanf("%d", &info.periodo);
	
	if(libera_reg(&reg) == 1) {
	  return 0;
	}
	
	reg = novo_reg(&info);
	if(reg != NULL) {
	  if(libera_reg(&reg) == 1 && reg == NULL) {
	    return 1;
	  }
	}
	
  return 0;
}

int testa_atribui_info_reg() {
  Info info;
  
  scanf("%s", &info.cod);
	scanf("%d", &info.dia);
	scanf("%d", &info.mes);
	scanf("%d", &info.ano);
	scanf("%s", info.cidade);
	scanf("%s", info.pais);
	scanf("%d", &info.periodo);
	
	Reg *reg = novo_reg(&info);
	
	if(reg != NULL) {
	  Info novo;
    scanf("%s", &novo.cod);
  	scanf("%d", &novo.dia);
  	scanf("%d", &novo.mes);
  	scanf("%d", &novo.ano);
  	scanf("%s", novo.cidade);
  	scanf("%s", novo.pais);
  	scanf("%d", &novo.periodo);
  	
	  if(atribui_info_reg(reg, &novo) == 1) {
	    Info *recuperado = acessa_info_reg(reg);
	    
	    if(recuperado != NULL) {
	      
	      if(strcmp(recuperado->cod, novo.cod) != 0) {
	        return 0;
	      }
	      
	      if(recuperado->dia != novo.dia) {
	        return 0;
	      }
	      
	      if(recuperado->mes != novo.mes) {
	        return 0;
	      }
	      
	      if(recuperado->ano != novo.ano){
	        return 0;
	      }
	      
	      if(strcmp(recuperado->cidade, novo.cidade) != 0) {
	        return 0;
	      }

	      if(strcmp(recuperado->pais, novo.pais) != 0) {
	        return 0;
	      }
	      
	      if(recuperado->periodo != novo.periodo) {
	       return 0;
	      }
	      
	      return 1;
	    }
	  }
	}
}

int testa_acessa_info_reg() {
  Info info;
  
  scanf("%s", &info.cod);
	scanf("%d", &info.dia);
	scanf("%d", &info.mes);
	scanf("%d", &info.ano);
	scanf("%s", info.cidade);
	scanf("%s", info.pais);
	scanf("%d", &info.periodo);
	
	Reg *reg = novo_reg(&info);
	
	if(reg != NULL) {
	  
	  Info *recuperado = acessa_info_reg(reg);
	  
	    if(recuperado != NULL) {
	      
	      if(strcmp(info.cod, recuperado->cod)) {
	        return 0;
	      }
	      
	      if(info.dia != recuperado->dia) {
	        return 0;
	      }
	      
	      if(info.mes != recuperado->mes) {
	        return 0;
	      }
	      
	      if(info.ano != recuperado->ano){
	        return 0;
	      }
	      
	      if(strcmp(info.cidade, recuperado->cidade) != 0) {
	        return 0;
	      }

	      if(strcmp(info.pais, recuperado->pais) != 0) {
	        return 0;
	      }
	      
	      if(info.periodo != recuperado->periodo) {
	       return 0;
	      }
	      
	      return 1;
	    }
	}
	return 0;
}

int testa_add_dir_reg() {
  Info info_atual, info_dir;
  Reg *atual = NULL;
  Reg *dir = NULL;
  
  if(add_dir_reg(atual, dir) == 1) {
    return 0;
	}
  
  scanf("%s", &info_atual.cod);
	scanf("%d", &info_atual.dia);
	scanf("%d", &info_atual.mes);
	scanf("%d", &info_atual.ano);
	scanf("%s", info_atual.cidade);
	scanf("%s", info_atual.pais);
	scanf("%d", &info_atual.periodo);
	
	atual = novo_reg(&info_atual);
	if(atual != NULL) {
	  
	  if(add_dir_reg(atual, dir) == 0) {
	    return 0;
	  }
	  
	  scanf("%s", &info_dir.cod);
  	scanf("%d", &info_dir.dia);
  	scanf("%d", &info_dir.mes);
  	scanf("%d", &info_dir.ano);
  	scanf("%s", info_dir.cidade);
  	scanf("%s", info_dir.pais);
  	scanf("%d", &info_dir.periodo);
	  dir = novo_reg(&info_dir);
	  
	  if(dir != NULL) {
	    if(add_dir_reg(atual, dir) == 1) {
	      if(visita_dir_reg(atual) != NULL) {
	        return 1;
	      }
	    }
	  }
	}
  
  return 0;
}

int testa_add_esq_reg() {
  Info info_atual, info_esq;
  Reg *atual = NULL;
  Reg *esq = NULL;
  
  if(add_esq_reg(atual, esq) == 1) {
    return 0;
	}
  
  scanf("%s", &info_atual.cod);
	scanf("%d", &info_atual.dia);
	scanf("%d", &info_atual.mes);
	scanf("%d", &info_atual.ano);
	scanf("%s", info_atual.cidade);
	scanf("%s", info_atual.pais);
	scanf("%d", &info_atual.periodo);
	
	atual = novo_reg(&info_atual);
	if(atual != NULL) {
	  scanf("%s", &info_esq.cod);
  	scanf("%d", &info_esq.dia);
  	scanf("%d", &info_esq.mes);
  	scanf("%d", &info_esq.ano);
  	scanf("%s", info_esq.cidade);
  	scanf("%s", info_esq.pais);
  	scanf("%d", &info_esq.periodo);
	  esq = novo_reg(&info_esq);
	  
	  if(esq != NULL) {
	    if(add_esq_reg(atual, esq) == 1) {
  	    if(visita_esq_reg(atual) != NULL) {
  	      return 1;
  	    }
	    }
	  }
	}
  
  return 0;
}

int testa_visita_dir_reg() {
  Info info_atual, info_dir;
  Reg *atual = NULL;
  Reg *dir = NULL;
  
  if(visita_dir_reg(atual) != NULL) {
    return 0;
	}
  
  if(add_dir_reg(atual, dir) == 1) {
    return 0;
	}
  
  scanf("%s", &info_atual.cod);
	scanf("%d", &info_atual.dia);
	scanf("%d", &info_atual.mes);
	scanf("%d", &info_atual.ano);
	scanf("%s", info_atual.cidade);
	scanf("%s", info_atual.pais);
	scanf("%d", &info_atual.periodo);
	
	atual = novo_reg(&info_atual);
	if(atual != NULL) {
	  
	  if(add_dir_reg(atual, dir) == 0) {
	    return 0;
	  }
	  
	  scanf("%s", &info_dir.cod);
  	scanf("%d", &info_dir.dia);
  	scanf("%d", &info_dir.mes);
  	scanf("%d", &info_dir.ano);
  	scanf("%s", info_dir.cidade);
  	scanf("%s", info_dir.pais);
  	scanf("%d", &info_dir.periodo);
	  dir = novo_reg(&info_dir);
	  
	  if(dir != NULL) {
	    if(add_dir_reg(atual, dir) == 1) {
	      if(visita_dir_reg(atual) != NULL) {
	        Info *aux = acessa_info_reg(visita_dir_reg(atual));
	        
  	      if(strcmp(info_dir.cod, aux->cod) != 0) {
  	        return 0;
  	      }
  	      
  	      if(info_dir.dia != aux->dia) {
  	        return 0;
  	      }
  	      
  	      if(info_dir.mes != aux->mes) {
  	        return 0;
  	      }
  	      
  	      if(info_dir.ano != aux->ano){
  	        return 0;
  	      }
  	      
  	      if(strcmp(info_dir.cidade, aux->cidade) != 0) {
  	        return 0;
  	      }
  
  	      if(strcmp(info_dir.pais, aux->pais) != 0) {
  	        return 0;
  	      }
  	      
  	      if(info_dir.periodo != aux->periodo) {
  	       return 0;
  	      }	        
	        
	        return 1;
	      }
	    }
	  }
	}
  
  return 0;  
}

int testa_visita_esq_reg() {
  Info info_atual, info_esq;
  Reg *atual = NULL;
  Reg *esq = NULL;
  
  if(visita_esq_reg(atual) != NULL) {
    return 0;
	}
  
  if(add_esq_reg(atual, esq) == 1) {
    return 0;
	}
  
  scanf("%s", &info_atual.cod);
	scanf("%d", &info_atual.dia);
	scanf("%d", &info_atual.mes);
	scanf("%d", &info_atual.ano);
	scanf("%s", info_atual.cidade);
	scanf("%s", info_atual.pais);
	scanf("%d", &info_atual.periodo);
	
	atual = novo_reg(&info_atual);
	if(atual != NULL) {
	  
	  if(add_esq_reg(atual, esq) == 0) {
	    return 0;
	  }
	  
	  scanf("%s", &info_esq.cod);
  	scanf("%d", &info_esq.dia);
  	scanf("%d", &info_esq.mes);
  	scanf("%d", &info_esq.ano);
  	scanf("%s", info_esq.cidade);
  	scanf("%s", info_esq.pais);
  	scanf("%d", &info_esq.periodo);
	  esq = novo_reg(&info_esq);
	  
	  if(esq != NULL) {
	    if(add_esq_reg(atual, esq) == 1) {
	      if(visita_esq_reg(atual) != NULL) {
	        Info *aux = acessa_info_reg(visita_esq_reg(atual));
	        
  	      if(strcmp(info_esq.cod, aux->cod) != 0) {
  	        return 0;
  	      }
  	      
  	      if(info_esq.dia != aux->dia) {
  	        return 0;
  	      }
  	      
  	      if(info_esq.mes != aux->mes) {
  	        return 0;
  	      }
  	      
  	      if(info_esq.ano != aux->ano){
  	        return 0;
  	      }
  	      
  	      if(strcmp(info_esq.cidade, aux->cidade) != 0) {
  	        return 0;
  	      }
  
  	      if(strcmp(info_esq.pais, aux->pais) != 0) {
  	        return 0;
  	      }
  	      
  	      if(info_esq.periodo != aux->periodo) {
  	       return 0;
  	      }	        
	        
	        return 1;
	      }
	    }
	  }
	}
	
  return 0;
}

int main(void) {
  int op;
  scanf("%d", &op);
  
  switch(op) {
    case 1: printf("%d", testa_novo_usu());
            break;
    
    case 2: printf("%d", testa_atribui_usu());
            break;
    
    case 3: printf("%d", testa_acessa_usu());
            break;
            
    case 4: printf("%d", testa_libera_usu());
            break;
            
    case 5: printf("%d", testa_novo_reg());
            break;
    
    case 6: printf("%d", testa_libera_reg());
            break;
    
    case 7: printf("%d", testa_atribui_info_reg());
            break;
    
    case 8: printf("%d", testa_acessa_info_reg());
            break;
    
    case 9: printf("%d", testa_add_dir_reg());
            break;
    
    case 10: printf("%d", testa_add_esq_reg());
             break;
    
    case 11: printf("%d", testa_visita_dir_reg());
             break;
    
    case 12: printf("%d", testa_visita_esq_reg());
             break;
  }
	return 0;
}
