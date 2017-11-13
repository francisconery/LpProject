//
//  functions.c
//  LPProject
//  Users/FranciscoNery/Documents/XCode/LpProject/LPProject/main.c
//  Created by Suse Ribeiro on 11/11/17.
//  Copyright © 2017 Suse Ribeiro. All rights reserved.
//

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Função que vai carregar do txt para o programa
 */
void carregarDoTxt(**matriz){
	// para ti, comentas a linha a baixo e inseres a outra com o teu url de pastas
	char url[]="/Users/francisconery/Documents/XCode/LpProject/LPProject/conversa.txt";
	char caracter;
	FILE * arq;
	char * token;
	
	arq = fopen(url, "r");
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else
		while( (caracter=fgetc(arq))!= EOF){
			token = strtok(&caracter,".?!");
			while(token!= NULL){
			
				putchar(caracter);
				token = strtok (NULL, ".?!");
			}
		}
	
	
	fclose(arq);
}

/**
 * Função que vai criar uma matriz com tamanho size * size
 * @param size é o tamanho de linhas
 * ** pois é um apontador para um array de size posiçoes em que cada posição tem um * para size posições, dai a matriz ficar size * size
 */
char ** criarMatrizDinamica(int size){
	return (char**)calloc(sizeof(char*), size);
}

/**
 *
 */
void carregarMatriz(void){
	
}

