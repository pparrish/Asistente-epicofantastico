#include <stdio.h>

int main(){

  char tarea[20][500] = {""};
  int valor[20] = {0};
  char TEXTO_AYUDA_ITAREAS[] = "----";
  
  int c; 
  int i;
  int salir=0;
  int err = 0;
  char opc;

  /*Recorremos la lista de tareas una a una, por cada tarea disponible
  nos motrara un menu para insertar una nueva tarea */
  for (i=0; (i<20) && (salir!=1); i++){
    
    if(tarea[i][0] == '\0'){
      
      if(!err){
        printf("%s\n", TEXTO_MENU_NTAREA); 
      }else{
        err=0;
      }

      scanf("%c", &opc);

       do {
        c = getchar();
      } while (c != '\n' && c != EOF);



      switch(opc){
        case 'N':
        scanf("%s",  tarea[i]);
        do {
        c = getchar();
        } while (c != '\n' && c != EOF);


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

}