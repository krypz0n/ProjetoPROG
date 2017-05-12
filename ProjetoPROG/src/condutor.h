/*
 * condutor.h
 *
 *  Created on: 18/04/2017
 *      Author: NunoDuarte
 */

#ifndef CONDUTOR_H_
#define CONDUTOR_H_

#include <stdlib.h>
#include <string.h>

#define maxSize 200

typedef struct condutor{	//Lista Duplamente Ligada

	int ID;
	int IDTrabalho;			// 0 se disponível
	char nome[maxSize];
	int maxTurno;
	int maxSemana;
	int minDescanso;
	struct condutor* next;
	struct condutor* back;


}condutor;

typedef struct{		//Apontadores para início e fim da lista dos condutores

	condutor* primeiro;
	condutor* ultimo;

}condutores;

condutores* criar_condutores(){//Aloca memória e cria uma lista sem condutores

	condutores *list;
	list = (condutores*)malloc(sizeof(condutores));
	list->primeiro = NULL;
	list->ultimo = NULL;

	return list;
}

void remover_condutores(condutores *list){//Liberta a memória de todos os elementos necessários da lista

	free(list);
}

condutores* adicionar_condutor(condutores* list, int ID, char *nome, int maxTurno, int maxSemana, int minDescanso, int trabalho){
	//Adiciona um condutor à lista indicada com os respetivos parâmetros

	condutor *c = (condutor*)malloc(sizeof(condutor));
	c->ID = ID;
	c->IDTrabalho = trabalho;
	strcpy(c->nome, nome);
	c->maxTurno = maxTurno;
	c->minDescanso = maxSemana;
	c->next = NULL;

	if(list->primeiro == NULL){
		list->primeiro = c;
		list->ultimo = c;
		c->back = NULL;
	}
	else{
		list->ultimo->next = c;
		c->back = list->ultimo;
		list->ultimo = c;
	}

	return list;
}

condutores* alterar_nome(condutores *list, int ID, char* nome){//Altera o Nome do Condutor

	condutor *c = list->primeiro;

	while(c->ID != ID){
		c = c->next;
		if(c == NULL){
			printf("Condutor não existe!\n");
			return list;
		}
	}

	strcpy(c->nome, nome);

	return list;
}

condutores* alterar_maxTurno(condutores *list, int ID, int maxTurno){//Altera o maxTurno do Condutor

	condutor *c = list->primeiro;

	while(c->ID != ID){
		c = c->next;
		if(c == NULL){
			printf("Condutor não existe!\n");
			return list;
		}
	}

	c->maxTurno = maxTurno;

	return list;
}

condutores* alterar_maxSemana(condutores *list, int ID, int maxSemana){//Altera o maxSemana do Condutor

	condutor *c = list->primeiro;

	while(c->ID != ID){
		c = c->next;
		if(c == NULL){
			printf("Condutor não existe!\n");
			return list;
		}
	}

	c->maxSemana = maxSemana;

	return list;
}

condutores* alterar_minDescanso(condutores *list, int ID, int minDescanso){//Altera o minDescanso do Condutor

	condutor *c = list->primeiro;

	while(c->ID != ID){
		c = c->next;
		if(c == NULL){
			printf("Condutor não existe!\n");
			return list;
		}
	}

	c->minDescanso = minDescanso;

	return list;
}

condutores* remover_condutor(condutores *list, int ID){
	//Remove e liberta a memória de um Condutor, ajusta os apontadores dos Condutores que o "rodeiam"

	condutor *l = list->primeiro;

	while(l->ID != ID){
		l = l->next;
		if(l == NULL){
			printf("Condutor não existe!\n");
			return NULL;
		}
	}

	l->back->next = l->next;
	l->next->back = l->back;
	free(l);

	return list;
}

condutores* ler_condutores(condutores *list, FILE* ficheiro){
	//Lê os dados de um ficheiro e preenche uma lista com os Condutores identificados

	int ID = 0, maxTurno = 0, maxSemana = 0, minDescanso = 0, trabalho = 0;
	char nome[200] = {0}, lixo[10], buffer[maxSize] = {0};

	while(fscanf(ficheiro, "%d", &ID) != EOF){

	fscanf(ficheiro, "%s", lixo);

	while(fscanf(ficheiro, "%s", buffer) != EOF){
		strcat(nome, buffer);
		if(nome[strlen(nome)-1] == ';'){
			nome[strlen(nome)-1] = '\0';
			break;
		}
		else
			strcat(nome, " ");
	}
	nome[strlen(nome)-1] = '\0';

	fscanf(ficheiro, "%d", &maxTurno);
	fscanf(ficheiro, "%s", lixo);

	fscanf(ficheiro, "%d", &maxSemana);
	fscanf(ficheiro, "%s", lixo);

	fscanf(ficheiro, "%d", &minDescanso);
	fscanf(ficheiro, "%s", lixo);

	fscanf(ficheiro, "%d", &trabalho);

	adicionar_condutor(list, ID, nome, maxTurno, maxSemana, minDescanso, trabalho);
	strcpy(nome, "");
	}

 	return list;
}

condutores* ler_condutor(condutores *list){
	//Preenche uma lista com um único Condutor especificado pelo utilizador

	int ID = 0, maxTurno = 0, maxSemana = 0, minDescanso = 0, trabalho = 0;
	char nome[200] = {0}, lixo[10], buffer[maxSize] = {0};

	scanf("%d", &ID);

	scanf("%s", lixo);

	while(scanf("%s", buffer) != EOF){
		strcat(nome, buffer);
		if(nome[strlen(nome)-1] == ';'){
			nome[strlen(nome)-1] = '\0';
			break;
		}
		else
			strcat(nome, " ");
	}

	scanf("%d", &maxTurno);
	scanf("%s", lixo);

	scanf("%d", &maxSemana);
	scanf("%s", lixo);

	scanf("%d", &minDescanso);
	scanf("%s", lixo);

	scanf("%d", &trabalho);

	adicionar_condutor(list, ID, nome, maxTurno, maxSemana, minDescanso, trabalho);

	return list;
}

condutores* alterar_trabalho(condutores *list, int ID, int IDTrabalho){
	//Altera a linha atribuída ao Condutor

	condutor *c = list->primeiro;

		while(c->ID != ID){
			c = c->next;
			if(c == NULL){
				printf("Condutor não existe!\n");
				return list;
			}
		}

		c->IDTrabalho = IDTrabalho;

		return list;
}

void mostrar_trabalho(condutores *list, int ID){//Mostra a linha atribuída ao Condutor

	condutor *c = list->primeiro;

		while(c->ID != ID){
			c = c->next;
			if(c == NULL)
				printf("Condutor não existe!\n");
		}

	printf("Condutor : %s\n", c->nome);
	printf("Linha atribuída: %d\n", c->IDTrabalho);
}

#endif /* CONDUTOR_H_ */
