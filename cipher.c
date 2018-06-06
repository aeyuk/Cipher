/*CATE YUK
This project reads a file of text and generates a cipher of the file. The cipher disguises the text using a combination of the letters I(increment) D(decrement) L(shift left) and R(shift right) given on the command line. 
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void IncrementText(char array[]) {
    int i = 0;
    for (i = 0; i < strlen(array); i++) {
        if (isalpha(array[i]) || isdigit(array[i])) {
            array[i] = array[i] + 1;
        }
    }
}


void DecrementText(char array[]) {
    int i = 0;
    for (i = 0; i < strlen(array); i++) {
        if (isalpha(array[i]) || isdigit(array[i])) {
            array[i] = array[i] - 1;
        }
    }   
}


void ShiftLeft(char array[]) {
    
    int i;
    char temp;
    temp = array[0];    
 
    for (i = 0; i < strlen(array)-1; i++) {
        array[i] = array[i+1];
    }
     
    array[strlen(array)-1] = temp;   
}


void ShiftRight(char array[]) {
    int i;
    char temp;
    temp = array[strlen(array)-1];

    for (i = strlen(array)-1; i > 0; i--) {
        array[i] = array[i-1];
    }

    array[0] = temp;
}



int main(int argc, char**argv) {
    if (argc != 3) {
        printf("Error\n");
        return 1;
    }
    
    FILE *fp1;

    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        printf("The file specified, %s, does not exist\n", argv[1]);
        return 2;
    }
    
    char command[100];
    char word[101];
    int i = 0;
    strcpy(command, argv[2]);

    fscanf(fp1, "%s", word);
    while (!feof(fp1)) {
        while (i < strlen(command)) {  
            if (command[i] != 'I' && command[i] != 'D' && 
                command[i] != 'L' && command[i] != 'R') {
                    printf("The encryption command is invalid\n");
                    return 0;
            }
            else if (command[i] == 'I') {
                IncrementText(word);
            }
            else if (command[i] == 'D') {
                DecrementText(word);
            }
            else if (command[i] == 'L') {
                ShiftLeft(word);
            }
            else if (command[i] == 'R') {
                ShiftRight(word);
            }
            i++;
        }
        i = 0;
        printf("%s\n", word);
        fscanf(fp1, "%s", word);
    }
    
    
    fclose(fp1);
                     
    return 0;
}

