//
//  header.h
//  LPProject
//
//  Created by Suse Ribeiro & Francisco Nery on 11/11/17.
//  Copyright © 2017 Suse Ribeiro. All rights reserved.
//

#ifndef header_h
#define header_h

char *carregarDoTxt(void);
char ** criarMatrizDinamica(int size);
void alocarMemoriaParaLinha(char **matriz, int position, long size);
char ** addicionaMaisLinhas(char **matriz, int * matrizSize, int numPositionsToAdd);
void insertLinha(char ** matriz, int * tamanhoMatriz, int * numeroLinhas, char * string);
void printMatriz(char ** matriz, int numLinesUsed);
void token(char **matriz, int *tamanhoMatriz, int *numeroLinhas, char * string, char *conjunto);

void verificaDicionario(char ** matriz, int * matrizSize, int * matrizUsedLines, char ** dicionario, int * dicionarioSize, int * dicionarioUsedLines, char * string);


#endif /* header_h */
