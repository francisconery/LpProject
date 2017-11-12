//
//  main.c
//  LPProject
//
//  Created by Suse Ribeiro on 11/11/17.
//  Copyright © 2017 Suse Ribeiro. All rights reserved.
//

#include <stdio.h>
#include "header.h"
#define M 50

int main(int argc, const char * argv[]) {
    
    char *matriz[][M] = {{"Ola Tudo bem"},{ "Ola, tudo e contigo?"}};
    //matriz[0][0] = string1;
    //printf("%s", matriz[0][0]);
    print_mensagens(*matriz, 2, M);
	printf("ola mundo ");
    
    Testeeeeeee
    return 0;
}
