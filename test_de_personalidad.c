#include <stdio.h>

#define POLAR 'I'
#define PANDA 'P'
#define PARDO 'G'

#define ANIME 'A'
#define MUSICA_POP 'M'
#define LIMPIEZA 'L'

#define BAMBU 'B'
#define PESCADO 'P'
#define FOCAS 'F'

const int PUNTAJE_ANIME = 2;
const int PUNTAJE_MUSICA_POP = 3;
const int PUNTAJE_LIMPIEZA = 1;

const int PUNTAJE_BAMBU = 6;
const int PUNTAJE_PESCADO = 9;
const int PUNTAJE_FOCAS = 3;

const int PISO_MINIMO = 1;
const int PISO_MAXIMO = 18;

const int GRITO_MINIMO = 1;
const int GRITO_MAXIMO = 18;

const int PUNTAJE_MINIMO_POLAR = 5;
const int PUNTAJE_MAXIMO_POLAR = 24;
const int PUNTAJE_MINIMO_PANDA = 25;
const int PUNTAJE_MAXIMO_PANDA = 43;
const int PUNTAJE_MINIMO_PARDO = 44;
const int PUNTAJE_MAXIMO_PARDO = 63;

/*
.Pre: La funcion recibe el caracter elegido por el usuario y valida que sea uno de los caracteres validos
.Post: Cuando se ingresa un caracter valido se guarda en la variable "caracter"
*/
void validar_caracter(char* caracter, char opcion_1, char opcion_2, char opcion_3){
    while ((*caracter != opcion_1) && (*caracter != opcion_2) && (*caracter != opcion_3)){
        printf("Por favor, elegir entre una de estas opciones: %c, %c, %c: ", opcion_1, opcion_2, opcion_3);
        scanf(" %c", caracter);
    }
}

/*
.Pre: La funcion recibe el numero elegido por el usuario y valida que este dentro del rango valido
.Post: Cuando se ingresa un numero valido se guarda en la variable "numero"
*/
void validar_numero(int* numero, int minimo, int maximo){
    while ((*numero < minimo) || (*numero > maximo)){
        printf("Por favor elija un numero entre %i y %i: ", minimo, maximo);
        scanf("%i", numero);
    }
}

/*
.Pre: La funcion recibe las opciones elegidas por el usuario
.Post: Devuelve un entero con el resultado de la formula de personalidad
*/ 
int calcular_puntaje(char canal, char alimento, int piso_elegido, int grito){
    int puntaje_total;
    switch (canal){
    case ANIME:
        if (alimento == BAMBU){
            puntaje_total = (PUNTAJE_BAMBU * PUNTAJE_ANIME) + piso_elegido + grito;
        }else if (alimento == PESCADO){
            puntaje_total = (PUNTAJE_PESCADO * PUNTAJE_ANIME) + piso_elegido + grito;
        }else{
            puntaje_total = (PUNTAJE_FOCAS * PUNTAJE_ANIME) + piso_elegido + grito;
        }        
        break;
    case MUSICA_POP:
        if (alimento == BAMBU){
            puntaje_total = (PUNTAJE_BAMBU * PUNTAJE_MUSICA_POP) + piso_elegido + grito;
        }else if (alimento == PESCADO){
            puntaje_total = (PUNTAJE_PESCADO * PUNTAJE_MUSICA_POP) + piso_elegido + grito;
        }else{
            puntaje_total = (PUNTAJE_FOCAS * PUNTAJE_MUSICA_POP) + piso_elegido + grito;
        }
        break;
    case LIMPIEZA:
        if (alimento == BAMBU){
            puntaje_total = (PUNTAJE_BAMBU * PUNTAJE_LIMPIEZA) + piso_elegido + grito;
        }else if (alimento == PESCADO){
            puntaje_total = (PUNTAJE_PESCADO * PUNTAJE_LIMPIEZA) + piso_elegido + grito;
        }else{
            puntaje_total = (PUNTAJE_FOCAS * PUNTAJE_LIMPIEZA) + piso_elegido + grito;
        }
        break;
    }
    return puntaje_total;
}

/*
.Pre: Recibe un entero con el resultado de la formula de personalidad
.Post: Imprime por pantalla el resultado del test de personalidad
*/
void determinar_personalidad(int puntaje){
    if ((puntaje >= PUNTAJE_MINIMO_POLAR) && (puntaje <= PUNTAJE_MAXIMO_POLAR)){
        printf("Sos callado y muy cerrado con tus emociones, pero eso no te quita lo maduro y valiente, tu unico miedo son los pepinos, sos un loquito de la limpieza y tenes varias habilidades que poca gente conoce por lo que tu personalidad es la de - Polar (%c) -\n", POLAR);
    } else if ((puntaje >= PUNTAJE_MINIMO_PANDA) && (puntaje <= PUNTAJE_MAXIMO_PANDA)){
        printf("El SuperTest cocluyo que tu personalidad corresponde a la de - Panda (%c) -, sos muy sensible y tierno, no soltas el celular en todo el dia y ademas sos medio otaku\n", PANDA);
    } else if((puntaje >= PUNTAJE_MINIMO_PARDO) && (puntaje <= PUNTAJE_MAXIMO_PARDO)){
        printf("Segun los resultados de nuestro SuperTest se ha determinado que tu personalidad coincide con la de - Pardo (%c) - eres el mas hiperactivo, ruidoso y sociable de la familia, amas el cine y lo mas importante eres el lider del trio\n", PARDO);
    }    
}

/*
.Pre:-
.Post: Guarda en la variable "canal" la opcion elegida por el usuario
*/
void elegir_canal(char* canal){
    printf("Vas a ver televisión un rato, pones el canal de: Anime (A), Musica Pop (M), Limpieza (L): ");
    scanf(" %c", canal);
    validar_caracter(canal, ANIME, MUSICA_POP, LIMPIEZA);
}

/*
.Pre:-
.Post: Guarda en la variable "alimento" la opcion elegida por el usuario
*/
void elegir_alimento(char* alimento){
    printf("Solo podes guardar un alimento en tu vianda: Bambú (B), Pescado (P), Focas (F): ");
    scanf(" %c", alimento);
    validar_caracter(alimento, BAMBU, PESCADO, FOCAS);
}

/*
.Pre:-
.Post: Guarda en la variable "piso" la opcion elegida por el usuario
*/
void elegir_piso(int* piso){
    printf("Te compras una torre con tus dos hermanos de 18 pisos. ¿En que piso te gustaría vivir?: ");
    scanf("%i", piso);
    validar_numero(piso, PISO_MINIMO, PISO_MAXIMO);
}

/*
.Pre:-
.Post: Guarda en la variable "grito" la opcion elegida por el usuario
*/
void elegir_nivel_de_grito(int* grito){
    printf("¡Oh, una rata! ¿Que tan fuerte gritas del 1 al 18? Siendo 1 no gritar y 18 desgarrarse la garganta: ");
    scanf("%i", grito);
    validar_numero(grito, GRITO_MINIMO, GRITO_MAXIMO);
}

/*
.Pre: -
.Post: Imprime por pantalla un mensaje de bienvenida al test
*/
void saludar(){
    printf("Bienvenido al SuperTest de personalidad, de acuerdo a tus respuestas en las siguientes 4 preguntas, definiremos a cual de los tres osos escandalosos te pareces.\n");
}

int main(){
    char canal_tv, alimento;
    int piso_elegido, grito;
    int puntaje_total;
    
    saludar();

    elegir_canal(&canal_tv);
    elegir_alimento(&alimento);
    elegir_piso(&piso_elegido);
    elegir_nivel_de_grito(&grito);

    puntaje_total = calcular_puntaje(canal_tv, alimento, piso_elegido, grito);
    determinar_personalidad(puntaje_total);


    return 0;
}
