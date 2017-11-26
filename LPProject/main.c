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
#define M 50 // macro 50

/**
 * Metodo main, onde o programa inicia
 */
int main(int argc, const char * argv[]) {
	
	int matrizSize = 0, matrizUsedLines = 0;
	int dicionarioSize = 10, dicionarioUsedLines=0;
	char * fileMessages = carregarDoTxt(); //input do ficheiro txt
	
	char **matriz = criarMatrizDinamica(matrizSize); //matriz inicializada
	char **dicionario = criarMatrizDinamica(dicionarioSize); //matriz para dicionario inicializada
	
	
	token(matriz,&matrizSize,&matrizUsedLines,fileMessages,"?!.\n");//escreve o conteuno no txt para a matriz com o respetivo token como regra
	token(dicionario,&dicionarioSize, &dicionarioUsedLines,fileMessages, " ");
	
	dicionario=verificaRepeatedWords(&fileMessages, &dicionarioSize,&dicionarioUsedLines);
	
	printMatriz(matriz, matrizUsedLines);
	printf("___\n");

	printMatriz(dicionario, dicionarioUsedLines);
	printf("___\n");
    return 0;
}
