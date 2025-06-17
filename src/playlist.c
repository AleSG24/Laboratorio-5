#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/playlist.h"

#define SONG_SIZE 100

struct Playlist{
	char cancion[SONG_SIZE];
	struct Playlist* next;
};

struct Playlist* new_song(const char* nombre){
	struct Playlist* newSong = (struct Playlist*)malloc(sizeof(struct Playlist));
	
	if (newSong == NULL) {
		printf("Error al reservar memoria\n");

		exit(1);
	}

	strcpy(newSong->cancion, nombre);  
	newSong->next = NULL;

	return newSong;
}

void Insert_begginig(struct Playlist** head, const char* nombre) {
	struct Playlist* newSong = new_song(nombre);
	newSong->next = *head;
	*head = newSong;
}

void Insert_end(struct Playlist** head, const char* nombre) {
	struct Playlist* newSong = new_song(nombre);
	if (*head == NULL){
	*head = newSong;
	return;
	}
	struct Playlist* temp = *head;
	while (temp->next != NULL ){
		temp = temp->next;
	}
	temp->next = newSong;
}

void Insert_specific(struct Playlist** head, const char* nombre, const char* specific){
	struct Playlist* newSong = new_song(nombre);
	if (*head == NULL){
		*head = newSong;
	return;
	}

	struct Playlist* temp = *head;
	struct Playlist* prev = NULL;

	while (temp != NULL){
		if (strcmp(temp->cancion, specific) == 0){
			newSong->next = temp;
			if (prev == NULL){
				*head = newSong;
			} else{
				prev->next = newSong;
			}
			return;
		}

		prev = temp;
		temp = temp->next;
	}
}

void delete_element(struct Playlist** head, const char* nombre){
	struct Playlist* temp = *head;
	struct Playlist* prev = NULL;

	while (temp != NULL){
		if (strcmp(temp->cancion, nombre) == 0){
			if (prev == NULL){
				*head = temp->next;

			}else{
				prev->next = temp->next;
			}
		free(temp);
		return;
		}
		prev = temp;
		temp = temp->next;
	}
}

void Show(struct Playlist* head){
	struct Playlist* current = head;
	while (current != NULL){
		printf("%s\n", current->cancion);
		current = current->next;
	}
}

void buscar_elemento(struct Playlist** head, const char* nombre){
	struct Playlist* temp = *head;
	while (temp != NULL){
		if (strcmp(temp->cancion, nombre) == 0){
			printf("Se ha encontrado el elemento\n");
		return;
		}
		if (temp->next == NULL){
			printf("El elemnto no existe en la lista\n");
			break;
		return;
		}
		temp = temp->next;
	}
}

void liberar_memoria(struct Playlist* head){
	struct Playlist* actual = head;
	struct Playlist* next;

	while (actual != NULL){
		next = actual->next;
		free(actual);
		actual = next;
	}
}




