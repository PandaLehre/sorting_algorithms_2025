#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float *textToFloatArray(const char *filePathName, size_t *out_n)
{

    FILE *file = fopen(filePathName, "r");
    if (!file) {
        perror("open");
        return NULL;
    }

    size_t cap = 8, n = 0; //n for elemnt count
    float *arr = malloc(cap * sizeof(*arr));

    char line[1024];

    if (fgets(line, sizeof(line), file)) {
        char *tok = strtok(line, ";\n\r"); //Cuts at ; into tokens
        while (tok) {
            //Increase Array Size if needed
            if (n == cap) {
                cap *= 2;
                float *tmp = realloc(arr, cap * sizeof(*arr));
                if (!tmp) {
                    perror("realloc");
                    free(arr);
                    fclose(file);
                    return NULL;
                }
                arr = tmp;
            }

            arr[n++] = strtof(tok, NULL); //String to Float
            tok = strtok(NULL, ";\n\r"); 
        }
    }

    fclose(file);

    *out_n = n;
    return arr;
}

//Use Example
/*
int main(void)
{
    size_t countOfElements = 0;
    char testTxtFile[50] = "Tests/floatTest.txt";
    float *TestDaten = textToFloatArray(testTxtFile, &countOfElements);

    for (size_t i = 0; i < countOfElements; i++){
        printf("%.2f ", TestDaten[i]);
    }

    free(TestDaten);
    return 0;
}
*/