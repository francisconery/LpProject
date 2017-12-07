//
//  header.h
//  LPProject
//
//  Created by Suse Ribeiro & Francisco Nery on 11/11/17.
//

#ifndef header_h
#define header_h
#define M10 10
#define M200 200

char *carregarDoTxt(char filename[]);
char ** criarMatrizDinamica(int size);
void alocarMemoriaParaLinha(char **matriz, int position, long size);
char ** addicionaMaisLinhas(char **matriz, int * matrizSize, int numPositionsToAdd);
void insertLinha(char ** matriz, int * tamanhoMatriz, int * numeroLinhas, char * string);
void printMatriz(char ** matriz, int numLinesUsed);
void token(char **matriz, int *tamanhoMatriz, int *numeroLinhas, char * string, char *conjunto);
char** verificaRepeatedWords(char ** dicionario, int * dicionarioSize,int *numeroPalavras);
//void delimiterPalavra(char ** dicionario, int * dicionarioSize, char * string);
//void delimiterPalavra(char ** dicionario, int * dicionarioSize,char * string, char *conjunto);
int verificaDicionario(char *string,char **aux,int *size);

#endif /* header_h */
