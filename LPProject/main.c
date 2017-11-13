//
//  main.c
//  LPProject
//
//  Created by Suse Ribeiro & Francisco Nery on 11/11/17.
//  Copyright © 2017 Suse Ribeiro. All rights reserved.
//

#include <stdio.h>
#include "header.h"
#define M 50 // macro 50

/**
 * Metodo Main, onde o programa é executado
 */
int main(int argc, const char * argv[]) {
	char **matriz = criarMatrizDinamica(10);//matriz inicializada com 10x10
	carregarDoTxt(matriz); // input do ficheiro txt
	
	for(int i =0; i<10;i++){
		//printf("%s\n",&matriz);
	}
    
    //char *matriz[10][10] = {};
    //matriz[0][0] = string1;
    //printf("%s", matriz[0][0]);
    //printMensagens(*matriz, 2, M);
	
	//printf("ola Mundo Vou acabar\n");
	
    return 0;
}
