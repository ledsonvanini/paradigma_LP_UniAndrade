#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }
    printf("SDL inicializado com sucesso!\n");
    SDL_Quit();
    return 0;
}
