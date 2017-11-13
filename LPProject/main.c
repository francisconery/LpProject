//
//  main.c
//  LPProject
//
//  Created by Suse Ribeiro & Francisco Nery on 11/11/17.
//  Copyright © 2017 Suse Ribeiro. All rights reserved.
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
	
	int matrizSize = 1, matrizUsedLines = 0;
	char **matriz = criarMatrizDinamica(matrizSize); //matriz inicializada com 10x10
	char * fileMessages = carregarDoTxt(); //input do ficheiro txt
	insertLinha(matriz, &matrizSize, &matrizUsedLines, fileMessages); //carrega do txt para a matriz
	printMatriz(matriz, matrizUsedLines);
	
	
    return 0;
}
