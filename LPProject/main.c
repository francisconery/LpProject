//
//  main.c
//  LPProject
//
//  Created by Suse Ribeiro & Francisco Nery on 11/11/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#define M50 50 // macro 50

/**
 * Metodo main, onde o programa inicia
 */
int main(int argc, const char * argv[]) {
	
	char filename[]="/Users/francisconery/Documents/XCode/LpProject/LPProject/conversa.txt"; // para ti, comentas a linha a baixo e inseres a outra com o teu url de pastas
	
	int matrizSize = 0, matrizUsedLines = 0;
	//int dicionarioSize = 0, dicionarioUsedLines=0;
	//int indicesSize = 0, indicesUsedLines=0;
	char * fileMessages = carregarDoTxt(filename); //input do ficheiro txt
	
	char **matriz = criarMatrizDinamica(matrizSize); //matriz inicializada
	token(matriz,&matrizSize,&matrizUsedLines,fileMessages,"?!.\n");//escreve o conteuno no txt para a matriz com o respetivo token como regra
	printMatriz(matriz, matrizUsedLines);
	printf("___\n");
	
	/*
	char **dicionario = criarMatrizDinamica(dicionarioSize); //matriz para dicionario inicializada
	token(dicionario,&dicionarioSize, &dicionarioUsedLines,fileMessages, " ");

	dicionario=verificaRepeatedWords(&fileMessages, &dicionarioSize,&dicionarioUsedLines);
	printMatriz(dicionario, dicionarioUsedLines);
	printf("___\n");
	*/
	
	//int **indices=NULL;
	
    return 0;
}
