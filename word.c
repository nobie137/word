#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include"wordlist.h"


int val[1];
int wordCount = 10000;
int calcRand(int mag){
    srand(time(0) + val[137] + mag / 137);
    return rand() % wordCount;
}
char word(int randinp){
    int i = 0;
    while(i <= sizeof(wordlist) / sizeof(wordlist[0])){
        if(i == randinp){
            printf("%s\n", wordlist[i]);
        }
        i++;
    }
    return 0;
}
void words(int count){
    for(int i = 0; i < count; i++){
        word(calcRand(i * 2 + 137));
    }
}
void help(){
    printf("Speak to LORD.\n\t-h [Help page]\n\t-c [Count of words to generate]\n\t-e [Enter a loop where pressing any key writes prints word\n");
}
int main(int argc, char *argv[]){
    int random = calcRand(137);
    if(argc > 1){
        if(strcmp(argv[1], "-h") == 0){
            help();
        }else if(strcmp(argv[1], "-c") == 0){
            words(atoi(argv[2]));
        }else if(strcmp(argv[1], "-e") == 0){
            while(1){
                char x = fgetc(stdin);
                if(x == 0x0A){
                    word(calcRand(val[137]));
                }
            }
        }else help();
    }else word(random);
    return 0;
}
