//
//  functions.c
//  LPProject
//  Users/FranciscoNery/Documents/XCode/LpProject/LPProject/main.c
//  Created by Suse Ribeiro & Francisco Nery on 11/11/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

/**
 * @brief Função que vai carregar do txt para o programa
 */
char * carregarDoTxt(char filename[]){
	
	FILE * fp = fopen(filename, "r");
	char buffer[M200];
	char * content = (char*)calloc(sizeof(char), 1);
	int readed = 1;
	
	if (fp != NULL){
		while(fgets(buffer, M200, fp)){
			
			readed+=strlen(buffer);
			content = (char*)realloc(content, sizeof(char) * readed);
			strcat(content, buffer);
		}
		fclose(fp);
		printf("carregarDoTxt(): content = %s\n", content);
		return content;
	}
	return NULL;
}

/**
 * @brief Função que cria uma matriz
 * @param size numero de linhas a criar a matriz
 */
char ** criarMatrizDinamica(int size){
	return (char**)calloc(sizeof(char*), size);
}

/**
 * @brief Função que vai alocar memoria para uma linha da matriz dinamica
 * @param matriz matriz a entrar
 * @param position posicao da matriz onde vai alocar a memoria ( linha)
 * @param size numero de linhas
 */
void alocarMemoriaParaLinha(char **matriz, int position, long size){
	if (matriz != NULL){
		*(matriz + position) = (char*)calloc(sizeof(char), size);
	}
}

/**
 * @brief Função que recebe uma matriz e aloca mais espaço para ela, retornando a nova
 * @param matriz matriz a entrar
 * @param matrizSize numero de linhas total que a matriz tem
 * @param numPositionsToAdd numero de posições a adicionar
 */
char ** addicionaMaisLinhas(char **matriz, int * matrizSize, int numPositionsToAdd){
	(*matrizSize) = (*matrizSize) + numPositionsToAdd;
	matriz = (char**)realloc(matriz, sizeof(char*) * (*matrizSize));
	return matriz;
}

/**
 * @brief Função que vai carregar o conteudo do txt para a matriz
 * @param matriz matriz a entrar
 * @param tamanhoMatriz numero de linhas total que a matriz tem
 * @param numeroLinhas numero de linahs utilizadas até agora
 * @param string string do txt a ser carregada numa linha
 */
void insertLinha(char **matriz, int *tamanhoMatriz, int *numeroLinhas, char *string){
	if (matriz == NULL){
		matriz = criarMatrizDinamica(M10);
		(*tamanhoMatriz) = 0;
		(*numeroLinhas) = 0;
	}
	
	if ((*numeroLinhas) >= (*tamanhoMatriz)){
		matriz = addicionaMaisLinhas(matriz, tamanhoMatriz, M10);
	}
	
	long stringSize = strlen(string)+1; //Contar com '\0'
	int aux = *numeroLinhas;
	alocarMemoriaParaLinha(matriz, aux, stringSize);
	strcpy(*(matriz + aux), string);
	printf("insertLinha(): string = %s\n", string);
	printf("insertLinha(): *(matriz + %d) = %s\n", aux, *(matriz + aux));
	*numeroLinhas = aux + 1;
}

/**
 * @brief função de print matriz
 * @param matriz matriz a entrar
 * @param numLinesUsed numero de linahs utilizadas até ao momento
 */
void printMatriz(char ** matriz, int numLinesUsed){
	if (matriz != NULL)
	{
		printf("printMatriz(): Matrix content: numLinesUsed = %d\n", numLinesUsed);
		for (int i = 0; i<numLinesUsed; i++)
		{
			printf("Line[%d]=%s\n", i, *(matriz + i));
			//printf("Line[%d]=\n", i);
		}
	}
}


/**
 * @brief Função que vai verificar com o token enviado e vai usar isso como delimiter para as palavras
 * @param matriz matriz a entrar
 * @param tamanhoMatriz numero de linhas total que a matriz tem
 * @param numeroLinhas numero de linahs utilizadas até agora
 * @param string string do txt a ser carregada numa linha
 * @param conjunto delimitadores do token
 */
void token(char **matriz, int *tamanhoMatriz, int *numeroLinhas, char * string, char *conjunto){
	char * t=NULL;
	char * strstrResult = NULL;
	char * finalMessage = NULL;
	char * stringClone = (char*)malloc(sizeof(char) * (strlen(string)+1));
	
	strcpy(stringClone, string);
	
	t = strtok(stringClone, conjunto);
	
	while (t!=NULL) {
		printf("token(): t = %s\n", t);
		finalMessage = (char*)calloc(sizeof(char), strlen(t) + 2);
		strcpy(finalMessage, t);
		strstrResult = strstr(string, t);
	
		finalMessage[strlen(t)] = strstrResult[strlen(t)];
		finalMessage[strlen(t)+1] = '\0';
		
		printf("token(): finalMessage = %s\n", finalMessage);
		
		insertLinha(matriz, tamanhoMatriz, numeroLinhas, finalMessage);
		free(finalMessage);
		t=strtok(NULL, conjunto);
	}
	//print_array();
	free(stringClone);
}
/**
 * @brief Função que vai verificar se as palavras sao repetidas e se nao forem insere uma nova na matriz dicionario
 * @param dicionario matriz
 * @param dicionarioSize tamanho da matriz
 * @param numeroPalavras numero de palavras a receber
 */
char** verificaRepeatedWords(char ** dicionario, int * dicionarioSize,int *numeroPalavras){
	int n=10;
	char ** mtx = criarMatrizDinamica(n);
	int number = *numeroPalavras;
	int v=0;
	
	for(int i=0;i<number;i++){
		
		if(*(dicionario+i)!=NULL&&verificaDicionario(*(dicionario+i),mtx,&v)==0){
			*(mtx+v)=(char*)malloc(sizeof(char)*strlen(*(dicionario+i))+1);
			strcpy(*(mtx+v), *(dicionario+i));
			v++;
		}
	}
	
	return mtx;
}

/**
 * @brief Funsao que verifica individualmente se a palavra hexiste ja ou nao
 * @param string palavra
 * @param aux palavra a comparar
 * @param size tamanho da palavra
 */
int verificaDicionario(char *string,char **aux,int *size){
	
	for(int i=0;i<(*size);i++){
		if(strcmp(string,*(aux+i))==0)
			return 0;
	}
	return 0;
	}
 
/**
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
/** //Feito pelo prof
for(i=0;i<size;i++){
	if(existe_anterior(argv,i))
		strcat((str,arg[i]))int size);

}

existe_anterior(){
	for(int k=i-1;i>=0;i++){
		if(strcmp(argv[k],argv[i]);
	}
}
*/
