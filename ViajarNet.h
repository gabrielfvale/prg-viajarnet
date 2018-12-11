#include "Usuario.h"
#include "Registro.h"

typedef struct perfil Perfil;

typedef struct rede Rede;

int sobreposta(Reg *reg, Info *info);

Rede *nova_rede(int tamanho);

int add_perfil_rede(Rede *rede, Perfil *perfil);

Perfil *recupera_perfil_rede(Rede *rede, int id_usu);

int numero_perfis_rede(Rede *rede);

Perfil *novo_perf(Usu *usu);

int libera_perf(Perfil **perfil);

Usu *acessa_usuario_perf(Perfil *perfil);

int add_viagem_perf(Perfil *perfil, Info *info);

int remove_viagem_perf(Perfil *perfil, char *cod);

Info *buscar_viagem_perf(Perfil *perfil, char *cod);

int numero_viagens_perf(Perfil *perfil);

char *listar_todas_viagens_perf(int ordem, Perfil *perfil);

char *buscar_viagem_por_mes_perf(int ordem, Perfil *perfil, int mes);

char *buscar_viagem_por_ano_perf(int ordem, Perfil *perfil, int ano);

char *buscar_viagem_por_cidade_perf(int ordem, Perfil *perfil, char *cidade);

char *buscar_viagem_por_pais_perf(int ordem, Perfil *perfil, char *pais);
