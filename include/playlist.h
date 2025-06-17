//header file para la lista enlazada
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SONG_SIZE 100

struct Playlist{
	char cancion[SONG_SIZE];
	struct Playlist* next;
};

void Insert_begginig(struct Playlist** head, const char* nombre);
void Insert_end(struct Playlist** head, const char* nombre);
void Insert_specific(struct Playlist** head, const char* nombre, const char* specific);
void delete_element(struct Playlist** head, const char* nombre);
void Show(struct Playlist* head);
void buscar_elemento(struct Playlist** head, const char* nombre);
void liberar_memoria(struct Playlist* head);

