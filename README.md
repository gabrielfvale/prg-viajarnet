#Trabalho CK0226

Instruções:

##TAD Registro

Restrições de Info
- O cod deve ser uma letra de tamanho 1
- A data (dia, mes, ano) deve ser válida
- A cidade deve ser de tamanho máximo 60, e não pode ser vazia
- O pais deve ser de tamanho máximo 30, e não pode ser vazio

Reg *novo_reg(Info *info)
- Cria o novo registro com *info válida
- Retorna o novo registro criado se a operação obteve sucesso, NULL caso contrário

int libera_reg(Reg **reg)
- Libera o registro válido
- Retorna 1 se a operação ocorreu com sucesso, 0 em caso contrário

int atribui_info_reg(Reg *reg, Info *info)
- Atribui uma *info válida ao registro
- Retorna 1 se a operação ocorreu com sucesso, 0 em caso contrário

Info *acessa_info_reg(Reg *reg)
- Retorna a Info de *reg se a operação ocorreu com sucesso, NULL caso contrário

int add_dir_reg(Reg *atual, Reg *dir)
- Adiciona o registro *dir à direita do registro *atual
- Retorna  1 se a operação ocorreu com sucesso, 0 caso contrário

int add_esq_reg(Reg *atual, Reg *esq)
- Adiciona o registro *esq à esquerda do registro *atual
- Retorna  1 se a operação ocorreu com sucesso, 0 caso contrário 

Reg *visita_dir_reg(Reg *atual)
- Visita o registro à direita do registro *atual
- Retorna  o registro à direita se a operação ocorreu com sucesso, NULL caso contrário

Reg *visita_esq_reg(Reg *atual)
- Visita o registro à esquerda do registro *atual
- Retorna  o registro à esquerda se a operação ocorreu com sucesso, NULL caso contrário

int tamanho_reg()
- Retorna o tamanho de Reg


============================================================


##TAD Usuário

Restrições de Usu
- O id deve ser um inteiro positivo
- O nome deve ser de tamanho máximo 30, e não pode ser vazio

Usu *novo_usu(int id, char *nome)
- Cria um Usu válido
- Retorna o Usu criado se a operação ocorreu com sucesso, NULL caso contrário

int libera_usu(Usu **usu)
- Libera o espaço de memória alocado para um usuário válido
- Retorna 1 se a operação ocorreu com sucesso, 0 em caso contrário

int acessa_usu(Usu *usu, int *id, char *nome)
- Acessa dados de *usu e copia para *id e *nome
- Retorna 1 se a operação ocorreu com sucesso, 0 em caso contrário

int atribui_usu(Usu *usu, int id, char *nome)
- Atribui dados válidos armazenados em *id e *nome para os respectivos campos de *usu
- Retorna 1 se a operação ocorreu com sucesso, 0 em caso contrário

int tamanho_usu()
- Retorna o tamanho de Usu


============================================================


##TAD ViajarNet


Rede *nova_rede(int tamanho)
- Cria uma Rede válida (tamanho > 0)
- Retorna a rede criada se a operação ocorreu com sucesso, NULL caso contrário

int add_perfil_rede(Rede *rede, Perfil *perfil)
- Adiciona um perfil válido à rede
- Não é permitido adicionar mais de um perfil para um mesmo usuário (usuário com o mesmo id)
- Retorna 1 se a operação ocorreu com sucesso, 0 em caso contrário

Perfil *recupera_perfil_rede(Rede *rede, int id_usu)
- Recupera um perfil de uma rede válida com base no identificador do usuário (id_usu)
- Retorna o perfil buscado se a operação ocorreu com sucesso, NULL caso contrário 

int numero_perfis_rede(Rede *rede)
- Calcula o número de perfis de uma rede válida
- Retorna o número de perfis calculado

Perfil *novo_perf(Usu *usu)
- Cria um perfil novo para um usuário (usu) válido fornecido
- Retorna o perfil criado se a operação ocorreu com sucesso, NULL caso contrário  

int libera_perf(Perfil **perfil)
- Libera o espaço de memória alocado para um perfil válido
- Retorna 1 se a operação ocorreu com sucesso, 0 em caso contrário

Usu *acessa_usuario_perf(Perfil *perfil)
- Acessa o registro de dados do usuário
- Retorna o registro acessado se a operação ocorreu com sucesso, NULL caso contrário  

int add_viagem_perf(Perfil *perfil, Info *info)
- Adiciona um registro de viagem (info) ao perfil do usuário (perfil)
- A inserção deve respeitar o seguinte critério de ordem da árvore de agendamentos: data da vigem. Quanto maior a data, mais à direita ela deve ficar.
- É proibido o agendamento de viagens  sobrepostas. Isto é, uma viagem não pode ser agendada em uma data que coincida com a data de outra viagem já agendada
- Retorna 1 se a operação ocorreu com sucesso, 0 em caso contrário

int remove_viagem_perf(Perfil *perfil, char *cod)
- Remove uma viagem válida do perfil, fazendo o devido rearranjo da arvore de agendamentos
- Retorna 1 se a operação ocorreu com sucesso, 0 em caso contrário

int numero_viagens_perf(Perfil *perfil)
- Calcula o número de viagens agendadas para um perfil válido
- Retorna o número de agendamentos calculado

Info *buscar_viagem_perf(Perfil *perfil, char *cod)
- Recupera uma viagem válida (cod) do perfil
- Retorna a viagem se a operação ocorreu com sucesso, NULL em caso contrário

char *listar_todas_viagens_perf(int ordem, Perfil *perfil)
- Calcula uma string com a concatenação dos códigos das viagens do perfil
- O campo ordem estabelece a ordem de caminhamento a ser usada para gerar a string concatenada:
-- Se ordem == 1 : a string deve ser gerada via pré-ordem: visita nó, percorre sub-arvore da esquerda, percorre sub-arvore da direita
-- Se ordem == 2 : a string deve ser gerada via ordem simétrica: percorre sub-arvore da esquerda, visita nó, percorre sub-arvore da direita
-- Se ordem == 3 : a string deve ser gerada via pós-ordem: percorre sub-arvore da esquerda, percorre sub-arvore da direita, visita nó
- Retorna a string concatenadase a operação ocorreu com sucesso, NULL em caso contrário

char *buscar_viagem_por_mes_perf(int ordem, Perfil *perfil, int mes)
- Calcula uma string com a concatenação dos códigos das viagens do perfil selecionados em função do mês fornecido
- O campo ordem estabelece a ordem de caminhamento a ser usada para gerar a string concatenada:
-- Se ordem == 1 : a string deve ser gerada via pré-ordem: visita nó, percorre sub-arvore da esquerda, percorre sub-arvore da direita
-- Se ordem == 2 : a string deve ser gerada via ordem simétrica: percorre sub-arvore da esquerda, visita nó, percorre sub-arvore da direita
-- Se ordem == 3 : a string deve ser gerada via pós-ordem: percorre sub-arvore da esquerda, percorre sub-arvore da direita, visita nó
- Retorna a string concatenada se a operação ocorreu com sucesso, NULL em caso contrário

char *buscar_viagem_por_ano_perf(int ordem, Perfil *perfil, int ano)
- Calcula uma string com a concatenação dos códigos das viagens do perfil selecionados em função do ano fornecido
- O campo ordem estabelece a ordem de caminhamento a ser usada para gerar a string concatenada:
-- Se ordem == 1 : a string deve ser gerada via pré-ordem: visita nó, percorre sub-arvore da esquerda, percorre sub-arvore da direita
-- Se ordem == 2 : a string deve ser gerada via ordem simétrica: percorre sub-arvore da esquerda, visita nó, percorre sub-arvore da direita
-- Se ordem == 3 : a string deve ser gerada via pós-ordem: percorre sub-arvore da esquerda, percorre sub-arvore da direita, visita nó
- Retorna a string concatenada se a operação ocorreu com sucesso, NULL em caso contrário

char *buscar_viagem_por_cidade_perf(int ordem, Perfil *perfil, char *cidade)
- Calcula uma string com a concatenação dos códigos das viagens do perfil selecionados em função da cidade de destino
- O campo ordem estabelece a ordem de caminhamento a ser usada para gerar a string concatenada:
-- Se ordem == 1 : a string deve ser gerada via pré-ordem: visita nó, percorre sub-arvore da esquerda, percorre sub-arvore da direita
-- Se ordem == 2 : a string deve ser gerada via ordem simétrica: percorre sub-arvore da esquerda, visita nó, percorre sub-arvore da direita
-- Se ordem == 3 : a string deve ser gerada via pós-ordem: percorre sub-arvore da esquerda, percorre sub-arvore da direita, visita nó
- Retorna a string concatenada se a operação ocorreu com sucesso, NULL em caso contrário

char *buscar_viagem_por_pais_perf(int ordem, Perfil *perfil, char *pais)
- Calcula uma string com a concatenação dos códigos das viagens do perfil selecionados em função da pais de destino
- O campo ordem estabelece a ordem de caminhamento a ser usada para gerar a string concatenada:
-- Se ordem == 1 : a string deve ser gerada via pré-ordem: visita nó, percorre sub-arvore da esquerda, percorre sub-arvore da direita
-- Se ordem == 2 : a string deve ser gerada via ordem simétrica: percorre sub-arvore da esquerda, visita nó, percorre sub-arvore da direita
-- Se ordem == 3 : a string deve ser gerada via pós-ordem: percorre sub-arvore da esquerda, percorre sub-arvore da direita, visita nó
- Retorna a string concatenada se a operação ocorreu com sucesso, NULL em caso contrário
