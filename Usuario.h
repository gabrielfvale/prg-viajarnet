typedef struct usuario Usu;

Usu *novo_usu(int id, char *nome);

int libera_usu(Usu **usu);

int acessa_usu(Usu *usu, int *id, char *nome);

int atribui_usu(Usu *usu, int id, char *nome);

int tamanho_usu();
