#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/playlist.h"

int main(){
	struct Playlist* head = NULL;
	
	int quit = 0;
	int opcion;
	char nombre[SONG_SIZE];
	char specific[SONG_SIZE];
	while (quit == 0){
		printf("Escoja una opcion: (1)Insertar cancion al inicio, (2)Insertar cancion al final, (3)Insertar cancion en posicion especifica, (4)Eliminar cancion, (5)Buscar cancion, (6)Imprimir Playlist, (7)Salir\n");
		scanf("%d", &opcion);
		switch (opcion) {
			case 1:
				printf("Inserte el nombre de la cancion\n");
				scanf("%99s", nombre);
				Insert_begginig(&head, nombre);
			break;

			case 2:
				printf("Inserte el nombre de la cancion\n");
				scanf("%99s", nombre);
				Insert_end(&head, nombre);
			break;
			case 3:
				printf("Inserte el nombre de la cancion\n");
				scanf("%99s", nombre);
				printf("Inserte el nombre de la cancion cuya posicion quiere tomar\n");
				scanf("%99s", specific);
				Insert_specific(&head, nombre, specific);
			break;
			case 4:
				printf("Inserte el nombre de la cancion\n");
				scanf("%99s", nombre);
				delete_element(&head, nombre);
			break;
			case 5:
				printf("Inserte el nombre de la cancion\n");
				scanf("%99s", nombre);
				buscar_elemento(&head, nombre);
			break;
			case 6:
				Show(head);
			break;
			case 7:
				printf("chao :D\n");
				liberar_memoria(head);
				quit = 1;
			break;


		}	


	}

}
