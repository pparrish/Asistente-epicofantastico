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
char TEX_INTRO[]         = "Bienvenido a el Asistente de tareas v1.1\nSoy capas de ayudar a la organizacion de proyectos pequeños solo necesita introducir el nombre de su proyecto y acontinuacion darme las tareas que usted crea necesarias para la realizacion de su proyecto mi funcion es organizar esas tareas conforme a un algotirmo especifico\nA continuacion le muestro un pequeno menu.\n" ;
char TEXTO_PEDIR_PRONO[] = "Todo proyecto debe tener un nombre, debemos ponerle un nombre muy descriptivo y original\nIntroduce el nombre del proyecto";
char TEXTO_PEDIR_PRODE[] = "Ahora debemos describir brebemente el proyecto en cuestion, esto es util para tener una idea clara de que vamos a hacer\nPor favor introdusca la descripcion de su proyecto";
char TEXTO_OPC[]         = "EL texto de las opciones";


/*Definiciones*/

/*FFlush*/
void clean_stdin(void);

void tareaNueva();

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
    /*Si el proyecto esta definido, pediremos el nombre del proyecto y la descripcion
    si el proyecto ya ha sido definio iremos al menu principal*/
    if(!isProDefined){
      /*Pedimos un nombre y una descripcion*/
      printf("%s\n", TEXTO_PEDIR_PRONO );
      scanf("%s", nombreProyecto);
      printf("%s\n", TEXTO_PEDIR_PRODE );
      scanf("%s", descProyecto);
      clean_stdin();
      scanf("%c", &opc);

      isProDefined = 1;

    }else{
      /*Con cada iteracion, mostaremos el nombre del proyecto y su descripcion
      Despues mostramos las opciones disponibles solo en caso de que no se haya
      dado una opcion invalida*/
      if(!err){
        printf("=====%s=====\n//%s//\n\n%s\n\n", nombreProyecto , descProyecto, TEXTO_OPC);
        scanf("%c", &opc);
        clean_stdin(); 
      }else{
        err = 0;
      }
      /*Operamos de acuerdo a cada condicion*/
      switch(opc){

        /*Nueva tarea*/
        case 'N':
        tareaNueva();
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
        case 'M':
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
