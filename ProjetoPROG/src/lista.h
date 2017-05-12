/*
 * lista.h
 *
 *  Created on: 18/04/2017
 *      Author: NunoDuarte
 */

#ifndef LISTA_H_
#define LISTA_H_

#include <stdlib.h>
#include <string.h>

#define maxSize 200

typedef struct{

	char paragem[maxSize];

}lista_paragens;

typedef struct linha{	//Lista Duplamente Ligada

	int ID;
	int freq;
	lista_paragens* paragens;
	int* tempoViagem;
	struct linha* next;
	struct linha* back;

}linha;

typedef struct{		//Apontadores para início e fim da lista das linhas

	linha* primeiro;
	linha* ultimo;

}listas;

listas* criar_listas(){		//Aloca memória e cria uma lista sem linhas

	listas *list;
	list = (listas*)malloc(sizeof(listas));
	list->primeiro = NULL;
	list->ultimo = NULL;

	return list;
}

void remover_listas(listas *list){		//Liberta a memória de todos os elementos necessários da lista

	linha *l = list->primeiro;

	while(l != NULL){
		free(l->paragens);
		l = l->next;
	}
	free(list);
}

listas* adicionar_linha(listas* list, int ID, int freq, lista_paragens *paragens, int *tempoViagem){
	//Adiciona uma linha à lista indicada com os respetivos parâmetros

	linha *l = (linha*)malloc(sizeof(linha));
	l->ID = ID;
	l->freq = freq;
	l->paragens = paragens;
	l->tempoViagem = tempoViagem;
	l->next = NULL;

	if(list->primeiro == NULL){
		list->primeiro = l;
		list->ultimo = l;
		l->back = NULL;
	}
	else{
		list->ultimo->next = l;
		l->back = list->ultimo;
		list->ultimo = l;
	}

	return list;
}

listas* alterar_freq(listas *list, int ID, int freq){	//Altera o valor da Frequência

	linha *l = list->primeiro;

	while(l->ID != ID){
		l = l->next;
		if(l == NULL){
			printf("Linha não existe!\n");
			return list;
		}
	}

	l->freq = freq;

	return list;
}

listas* alterar_paragens(listas *list, int ID, lista_paragens *paragens){	//Altera as Paragens do percurso

	linha *l = list->primeiro;

	while(l->ID != ID){
		l = l->next;
		if(l == NULL){
			printf("Linha não existe!\n");
			return list;
		}
	}

	l->paragens = paragens;

	return list;
}

listas* alterar_tempoViagem(listas *list, int ID, int* tempoViagem){	//Altera o Tempo de cada Viagem entre Paragens

	linha *l = list->primeiro;

	while(l->ID != ID){
		l = l->next;
		if(l == NULL){
			printf("Linha não existe!\n");
			return list;
		}
	}

	l->tempoViagem = tempoViagem;

	return list;
}

listas* remover_linha(listas *list, int ID){	//Remove e liberta a memória de uma linha, ajusta os apontadores das linhas que a "rodeiam"

	linha *l = list->primeiro;

	while(l->ID != ID){
		l = l->next;
		if(l == NULL){
			printf("Linha não existe!\n");
			return NULL;
		}
	}

	l->back->next = l->next;
	l->next->back = l->back;
	free(l);

	return list;
}

listas* ler_listas(listas *list, FILE* ficheiro){
	//Lê os dados de um ficheiro e preenche uma lista com as linhas identificadas

	int ID = 0, freq = 0, i = 0, j = 0, *tempoViagem = (int*)malloc(sizeof(int));
	char paragem[200] = {0}, buffer[200] = {0}, lixo[10], chr = '\0';
	lista_paragens *paragens = malloc(sizeof(lista_paragens));

	while(fscanf(ficheiro, "%d", &ID) != EOF){

	fscanf(ficheiro, "%d", &ID);
	if(fscanf(ficheiro, "%s", lixo) == EOF)
		printf("Error reading file(EOF returned)!\n");
	if(fscanf(ficheiro, "%d", &freq) == EOF)
		printf("Error reading file(EOF returned)!\n");
	if(fscanf(ficheiro, "%s", lixo) == EOF)
		printf("Error reading file(EOF returned)!\n");

	while(fscanf(ficheiro, "%s", buffer) != EOF){
		strcat(paragem, buffer);
		if(paragem[strlen(paragem)-1] == ','){
			paragem[strlen(paragem)-1] = '\0';
			strcpy(paragens[i].paragem, paragem);
			i++;
			paragens = (lista_paragens*)realloc(paragens, (i+1)*sizeof(lista_paragens));
			strcpy(paragem, "");
		}
		else if(paragem[strlen(paragem)-1] == ';'){
			paragem[strlen(paragem)-1] = '\0';
			strcpy(paragens[i].paragem, paragem);
			break;
		}
		else
			strcat(paragem, " ");
	}
	j = i+1;

	for(i = 0; i < j-1; i++){
		fscanf(ficheiro, " %d", &tempoViagem[i]);
		tempoViagem = (int*)realloc(tempoViagem, (i+2)*sizeof(int));
		if(i < j-2)
			fscanf(ficheiro, " %c", &chr);
	}
	adicionar_linha(list, ID, freq, paragens, tempoViagem);
	j = 0;
	i = 0;
	strcpy(paragem, "");
	paragens = malloc(sizeof(lista_paragens));
	tempoViagem = (int*)malloc(sizeof(int));
	}

	free(paragens);
	free(tempoViagem);

	return list;
}

listas* ler_lista(listas* list){	//Preenche uma lista com uma única linha especificada pelo utilizador

	int ID = 0, freq = 0, i = 0, j = 0, *tempoViagem = (int*)malloc(sizeof(int));
	char paragem[200] = {0}, buffer[200] = {0}, lixo[10], chr = '\0';
	lista_paragens *paragens = malloc(sizeof(lista_paragens));

	scanf("%d", &ID);

	if(scanf("%s", lixo) == EOF)
	printf("Error reading file(EOF returned)!\n");
	if(scanf("%d", &freq) == EOF)
		printf("Error reading file(EOF returned)!\n");
	if(scanf("%s", lixo) == EOF)
		printf("Error reading file(EOF returned)!\n");

	while(scanf("%s", buffer) != EOF){
		strcat(paragem, buffer);
		if(paragem[strlen(paragem)-1] == ','){
			paragem[strlen(paragem)-1] = '\0';
			strcpy(paragens[i].paragem, paragem);
			i++;
			paragens = (lista_paragens*)realloc(paragens, (i+1)*sizeof(lista_paragens));
			strcpy(paragem, "");
		}
		else if(paragem[strlen(paragem)-1] == ';'){
			paragem[strlen(paragem)-1] = '\0';
			strcpy(paragens[i].paragem, paragem);
			break;
		}
		else
			strcat(paragem, " ");
	}
	j = i+1;

	for(i = 0; i < j-1; i++){
		scanf(" %d", &tempoViagem[i]);
		tempoViagem = (int*)realloc(tempoViagem, (i+2)*sizeof(int));
		if(i < j-2)
			scanf(" %c", &chr);
	}
	adicionar_linha(list, ID, freq, paragens, tempoViagem);

	return list;
}

void horario_paragem(listas *list, const char *paragem){	//Representa as horas de chegada dos transportes numa certa Paragem, na forma de uma tabela

	int i, horas = 8, minutos = 0;
	linha *l = list->primeiro;

	printf("\n|%s|\n\n", paragem);
	printf("Horário:\n");

	while(l != NULL){

		for(i = 0; i < 4; i++){
			if(strcmp(l->paragens[i].paragem, paragem) == 0){
				while(horas < 20){
					minutos += l->freq;
					while(minutos >= 60){
						minutos -= 60;
						horas++;
					}
					if(minutos >= 10)
						printf("%d | %d:%d\n", l->ID, horas, minutos);
					else
						printf("%d | %d:0%d\n", l->ID, horas, minutos);
				}
				horas = 8;
				minutos = 0;
				break;
			}
		}

		l = l->next;
	}
}

void horario_linha(listas *list, int ID){	//Representa as horas de chegada de um transporte nas respetivas Paragens ao longo de uma linha, na forma de uma tabela

	int horas = 8, minutos = 0;
	linha *l = list->primeiro;

	printf("\n|%d|\n\n", ID);
	printf("Horário:\n");

	while(l != NULL){
		for(int i = 0; i < 4; i++){
			if(l->ID == ID){
				while(horas < 20){
					for(int j = 0; j < 4; j++){
						while(minutos >= 60){
							minutos -= 60;
							horas++;
						}
						if(minutos >= 10)
							printf("%d:%d | %s\n", horas, minutos, l->paragens[j].paragem);
						else
							printf("%d:0%d | %s\n", horas, minutos, l->paragens[j].paragem);
						if(j == 0)
							minutos += l->freq;
						else{
													minutos += l->tempoViagem[j-1];
													minutos += l->freq;
												}
					}
				}
				horas = 8;
				minutos = 0;
				break;
			}
		}

		l = l->next;
	}
}

#endif /* LISTA_H_ */
