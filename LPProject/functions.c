//
//  functions.c
//  LPProject
//  Users/FranciscoNery/Documents/XCode/LpProject/LPProject/main.c
//  Created by Suse Ribeiro on 11/11/17.
//  Copyright © 2017 Suse Ribeiro. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

/**
 * @brief Função que vai carregar do txt para o programa
 */
char * carregarDoTxt(){
	
	char url[]="/Users/francisconery/Documents/XCode/LpProject/LPProject/conversa.txt"; // para ti, comentas a linha a baixo e inseres a outra com o teu url de pastas
	FILE * fp = fopen(url, "r");
	char buffer[100];
	char * content = (char*)calloc(sizeof(char), 1);
	int readed = 0;
	
	if (fp != NULL){
		while(fgets(buffer, 100, fp)){
			readed+=strlen(buffer);
			content = (char*)realloc(content, sizeof(char) * readed);
			strcat(content, buffer);
		}
		fclose(fp);
		return content;
	}
	return NULL;
}

/**
 * @brief Função que cria uma matriz
 * @param size numero de linhas a criar a matriz
 */
char ** criarMatrizDinamica(int size){
	return (char**)malloc(sizeof(char*)*size);
}


/**
 * @brief Função que vai alocar memoria para a matriz
 * @param matriz matriz a entrar
 * @param position fsd
 * @param size numero de linhas
 */
void alocarMemoriaParaLinha(char **matriz, int position, long size){
	if (matriz != NULL)
		matriz[position] = (char*)calloc(sizeof(char), size);
}

/**
 * @brief jhf
 * @param matriz matriz a entrar
 * @param matrizSize numero de linhas total que a matriz tem
 * @param numPositionsToAdd numero de posições a adicionar
 */
char ** addicionaMaisLinhas(char **matriz, int * matrizSize, int numPositionsToAdd){
	matriz = (char**)realloc(matriz, (*matrizSize) + numPositionsToAdd);
		(*matrizSize) = (*matrizSize) + numPositionsToAdd;

	
	return matriz;
}

/**
 * @brief Função que vai carregar o conteudo do txt para a matriz
 * @param matriz matriz a entrar
 * @param matrizSize numero de linhas total que a matriz tem
 * @param matrizUsedLines numero de linahs utilizadas até agora
 * @param string string do txt a ser carregada numa linha
 */
void insertLinha(char ** matriz, int * matrizSize, int * matrizUsedLines, char * string){
	if (matriz == NULL){
		matriz = criarMatrizDinamica(10);
		//(*matrizSize) = 0;
		(*matrizUsedLines) = 0;
	}
	
	if ((*matrizUsedLines) >= (*matrizSize)){
		matriz = addicionaMaisLinhas(matriz, matrizSize, 10);
	}
	
	long stringSize = strlen(string);
	alocarMemoriaParaLinha(matriz, *matrizUsedLines, stringSize);
	strcpy(matriz[(*matrizUsedLines)++], string);
}

/**
 * @brief função de print matriz
 * @param matriz matriz a entrar
 * @param numLinesUsed numero de linahs utilizadas até ao momento
 */
void printMatriz(char ** matriz, int numLinesUsed){
	if (matriz != NULL){
		puts("Matrix content:\n");
		for (int i = 0; i<numLinesUsed; i++){
			puts(matriz[i]);
		}
	}
}


/**
 * @brief Função que vai verificar com o token enviado e vai usar isso como delimiter para as matrizes
 */
void token(char **matriz, int *tamanhoMatriz, int *numeroLinhas, char * string, char *conjunto){
	char *t;
	t= strtok(string, conjunto);
	
	while (t!=NULL) {
		insertLinha(matriz, tamanhoMatriz, numeroLinhas, t);
		t=strtok(NULL, conjunto);
	}
}
/**
 void verificaDicionario(char ** matriz, int * matrizSize, int * matrizUsedLines, char ** dicionario, int * dicionarioSize, int * dicionarioUsedLines, char * string){
 
 if (dicionario == NULL){
 dicionario = criarMatrizDinamica(1);
 (*dicionarioSize) = 0;
 (*dicionarioUsedLines) = 0;
 }
 if ((*dicionarioUsedLines) >= (*dicionarioSize)){
 dicionario = addicionaMaisLinhas(dicionario, dicionarioSize, 1);
 }
 
 long stringSize = strlen(string);
 alocarMemoriaParaLinha(dicionario, *dicionarioUsedLines, stringSize);
 
 strcpy(dicionario[(*dicionarioUsedLines)++], string);
 }
 */
