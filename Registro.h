struct informacao {
	char cod[2];
	int dia;
	int mes; 
	int ano; 
	char cidade[61];
	char pais[31];
	int periodo;
};

typedef struct informacao Info;

typedef struct registro Reg;

int nodecmp(Info *e, Info *n);

Reg *novo_reg(Info *info);

int libera_reg(Reg **reg);

int atribui_info_reg(Reg *reg, Info *info);

Info *acessa_info_reg(Reg *reg);

int add_dir_reg(Reg *atual, Reg *dir);

int add_esq_reg(Reg *atual, Reg *esq);

int sub_dir_reg(Reg *atual, Reg *dir);

int sub_esq_reg(Reg *atual, Reg *esq);

Reg *visita_dir_reg(Reg *atual);

Reg *visita_esq_reg(Reg *atual);

int tamanho_reg();
