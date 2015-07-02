/***
 *       _____                  __                  ______                _          ______    __                    ______     _      _   _         
 *      / ___/____ _____  _____/ /_  ___  ____     / ____/___ ___________(_)___ _   / ____/___/ /___ _____ ______   / ____/____(_)____/ /_(_)___ _____ 
 *      \__ \/ __ `/ __ \/ ___/ __ \/ _ \/_  /    / / __/ __ `/ ___/ ___/ / __ `/  / __/ / __  / __ `/ __ `/ ___/  / /   / ___/ / ___/ __/ / __ `/ __ \
 *     ___/ / /_/ / / / / /__/ / / /  __/ / /_   / /_/ / /_/ / /  / /__/ / /_/ /  / /___/ /_/ / /_/ / /_/ / /     / /___/ /  / (__  ) /_/ / /_/ / / / /
 *    /____/\__,_/_/ /_/\___/_/ /_/\___/ /___/   \____/\__,_/_/   \___/_/\__,_/  /_____/\__,_/\__, /\__,_/_/      \____/_/  /_/____/\__/_/\__,_/_/ /_/ 
 *     
 ***Tabajo para introduccion a la programacion.
 ***Asistente de tareaas
 ***Podemos introducir hasta un maximo de 20 tareas y este las ordenara segun
 ***su importancia.  
 *  
 *                                                                                                      
 */
 /*Anexar conio solo en windows*/
#ifdef _WIN32
#include <conio.h>
#endif
#include <stdio.h>

/*Colocaremos aqui los  textos correspondientes para cada mensaje,
Los guardamos en memoria debido a que no se usaran mas datos de los necesarios
y asi no inlcuir un sistema de lectura de archivos*/
char TEX_INTRO[]           = "Bienvenido a el Asistente de tareas v1.1\nSoy capas de ayudar a la organizacion de proyectos pequeños solo necesita introducir el nombre de su proyecto y acontinuacion darme las tareas que usted crea necesarias para la realizacion de su proyecto mi funcion es organizar esas tareas conforme a un algotirmo especifico\nA continuacion le muestro un pequeno menu.\n" ;
char TEXTO_PEDIR_PRONO[]   = "Todo proyecto debe tener un nombre, debemos ponerle un nombre muy descriptivo y original\nIntroduce el nombre del proyecto";
char TEXTO_PEDIR_PRODE[]   = "Ahora debemos describir brebemente el proyecto en cuestion, esto es util para tener una idea clara de que vamos a hacer\nPor favor introdusca la descripcion de su proyecto";
char TEXTO_OPC[]           = "=====Opciones=====\n"
                             "N : Nueva tarea. \n"
                             "B : Borrar tarea.\n"
                             "E : Editar tarea.\n"
                             "M : Mostrar tareas.\n"
                             "H : Ayuda\n"
                             "S : Salir\n"
                             "==================\n"
                             "Seleccione una opcion (mayuscula):\n";
char TEXTO_MENU_NTAREA[]   = "=====Opciones=====\n"
                             "==Agregar tareas==\n"
                             "N : Nueva tarea\n"
                             "H : Ayuda\n"
                             "S : menu principal\n";
char TEXTO_AYUDA_ITAREAS[] = "----";

/*Tenemos dos arrays relacionados para colocar las palabras clave para valorar tareas
y tenemos el valor de dichas palabras clave agregaremos tantas como sea necesarias para
el funcionamiento del programa*/
char palabras[][50] = { "investigar",
                        "redactar",
                        "resolver",
                        "conseguir",
                        "hacer",
                        "revisar",
                        "organizar",
                        "comunicar",
                        "" };
int vPalabras[] = { 10,
                    20,
                    30,
                    40,
                    50,
                    60,
                    25,
                    15,
                    -1 };


/*Un contador gloglal que le da un valor  n +1 para que las tareas mas viejas tengan una
prioridad mayor*/
int cViejas = 0;



/*Definiciones*/
/*FFlush*/
void clean_stdin(void);
void readLine(char texto[], int tamano);
void tareaNueva();
int valorar(char * tarea);

int main(){

  char salir=0;
  char err=0;
  char opc = 0;
  char isProDefined = 0;
  char nombreProyecto[200] = "";
  char descProyecto[200] = "";

  /*Las tareas y los valores de dichas tareas que se mostraran en nuestro programa*/
  char tarea[20][500] = {""};
  char valor[20] = {0};

  printf("%s\n", TEX_INTRO);

  /*Dentro de este bucle se desarrollara todo el proyecto, el menu principal
    mandara a llamar a todas las subdtinas y el despliege de datos*/
  do{
    /*Si el proyecto NO esta definido, pediremos el nombre del proyecto y la descripcion
    si el proyecto ya ha sido definio iremos al menu principal*/
    if(!isProDefined){
      /*Pedimos un nombre y una descripcion*/
      printf("%s\n", TEXTO_PEDIR_PRONO );
      readLine(nombreProyecto, 200);
      printf("%s\n", TEXTO_PEDIR_PRODE );
      readLine(descProyecto, 200);
      isProDefined = 1;
    }else{
      /*Con cada iteracion, mostaremos el nombre del proyecto y su descripcion
      Despues mostramos las opciones disponibles solo en caso de que no se haya
      dado una opcion invalida*/
      if(!err){
        printf("================================================================================\n"
               "%s"
               "================================================================================\n"
               "%s"
               "================================================================================\n"
               "%s", nombreProyecto , descProyecto, TEXTO_OPC); 
      }else{
        err = 0;
      }

      scanf("%c", &opc);
      clean_stdin();

      /*Operamos de acuerdo a cada condicion*/
      switch(opc){

        /*Nueva tarea*/
        case 'N':
        tareaNueva(tarea, valor);
        break;

        /*Borrar tarea*/
        case 'B':
        break;

        /*Editar tarea*/
        case 'E':
        break;

        /*Mostrar tareas*/
        case 'M':
        break;

        /*P Nuevo proyecto*/
        case 'P':
        break;

        /*Help - ayudas*/
        case 'H':
        break;

        /*Salir del programa*/
        case 'S':
        salir=1;
        break;

        /*Opcion incorrecta*/
        default:
        printf("Opcion incorrecta\n"); 
        err=1;
        break;
      }

    }

  }while(salir!=1);


  #ifdef _WIN32
  getch();
  #endif

  return 0;

}

/*Reemplazo de la funcion fflush que no esta definida para los sitemas opetarivos
esta funcion servira siempre*/
void clean_stdin(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
/*Implementacion para leer lineas completas desde consola caracter a caracter*/
void readLine(char texto[], int tamano){
  int count = 0;
  int c=0;
  do {
          c = getchar();
          texto[count] = c;
          count++;

  } while (c != '\n' && c != EOF && tamano > count );
  clean_stdin(); 
}

/*Agregador de tareas*/
void tareaNueva( char* tarea, char* valor){

  int c; 
  int i;
  int salir=0;
  int err = 0;
  char opc;
  int ifItero = 0;

  /*Recorremos la lista de tareas una a una, por cada tarea disponible
  nos mostrara un menu para insertar una nueva tarea */
  for (i=0; (i<20) && (salir!=1); i++){
    ifItero++;
    if( *(tarea+i) == '\0'){
      
      if(!err){
        printf("%s\n", TEXTO_MENU_NTAREA); 
      }else{
        err=0;
      }

      scanf("%c", &opc);
      clean_stdin();

      switch(opc){
        case 'N':
        readLine( (tarea+i), 500 );
        *(valor+i) = valorar( (tarea+i) );
        cViejas++;
        break;
        case 'H':
        printf("%s\n", TEXTO_AYUDA_ITAREAS );
        break;
        case 'S':
        salir = 1;
        break;
        default:
        printf("Esa es una opcion incorrecta");
        err=1;
        --i;
      }
    }
  }

  if(!ifItero){
    printf("Has llegado al limite de tareas (20), borra algunas tareas, completalas, o piensa en descomponer tu proyecto ne proyectos mas pequeños\n");
  }

}

int valorar(char * tarea){
  /*Buscamos por la primera palabra y la igualamos con nuestra lista de tareas*/
  int valor = cViejas;
  int i;
  int x;
  int isthis = 0;
  /*Busca en nuesta lista de palabras (la ultima de la lista esta vacia), en cada palabra
  la compara con nuestra trarea en cuestion solo hasta la primera palabra, si son iguales
  toma a isthis como cierto y termina la iteracion*/
  for(x=0;palabras[x][0] != '\0' ; x++){
    for(i=0; (*(tarea+i) != '\n') && (*(tarea+i) != ' ') && (*(tarea+i) != '\0'); i++ ){
      if( *(tarea+i) == palabras[x][i] ){
        isthis = 1;
      }else{
        isthis = 0;
        break;
      }
    }
    if(isthis){
      break;
    }
  }
  /*Si es que encontramos una palabra isthis tendra un valor 1  y pobremos sumarle el valor*/
  if(isthis){
    valor = valor + vPalabras[x];
    return valor;
  }
  /*Si no es asi, la palabra en cuestion tendra el valor global del contador*/
  return valor;
}