#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
        if (argc!=3) {
                fprintf(stderr, "Uso: %s puerto fichero_temas\n", argv[0]);
                return 1;
        }
        // Guardo los argumentos que me interesan                                                        
        int puerto = strtol(argv[1],NULL,10);
        char *fichero=argv[2];
        //Prueba guardado de argumentos correcto                                                         
        fprintf(stdout, "Puerto %d Fichero %s\n", puerto, fichero);

        //Leemos el contenido del fichero de temas                                                       
        FILE * fp;

        fp = fopen(fichero,"r");
        if(fp == NULL){
                fprintf(stderr, "Error: lectura del fichero de temas\n");
                return 1;
                }

        const size_t tamLin = 300;
        char * linea = malloc(tamLin);
        //char c;                                                                                        
        while (fgets(linea,tamLin,fp) != NULL){
                printf(linea);

                //NO PUEDE HABER ESPACIOS EN EL NOMBRE                                                   
                /*while((c=getchar()) != '\n'){                                                          
                        if(c == ' '){                                                                    
                        fprintf(stdout,"Aviso: El tema %s contiene al menos un espacio. Sera eliminado d\
e la lista\n",linea);                                                                                    
                        //Borrar Linea del fichero                                                       
                        break;                                                                           
                        }                                                                                
                }       */
        }
        free(linea);
return 0;
}
//Falta probar la funcion.                                                                               
//Falta saber si hay que borrar la linea con espacios o arreglarla                                       
void borrarEspacios(char* cad){
        char* aux = cad;
        char* aux2 = cad;
        while(*aux2 != 0){
                *aux = *aux2++;
                if(*aux != ' '){
                        aux++;}
                }
        *aux=0;
}


