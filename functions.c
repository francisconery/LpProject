//
//  functions.c
//  LPProject
//
//  Created by Suse Ribeiro on 11/11/17.
//  Copyright © 2017 Suse Ribeiro. All rights reserved.
//

#include "header.h"
#include <stdio.h>
#include "stdlib.h"


void print_mensagens(char *matriz[], int linhas, int colunas){
    int linha=0, coluna=0;
        for(linha=0; linha < linhas+1; linha++){
            for(coluna=0; coluna <colunas+1; coluna++){
                printf(" %s ", &matriz[linha][coluna]);
            }
            printf("\n");
    }
}

