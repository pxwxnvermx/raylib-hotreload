#ifndef _GAME_H_
#define _GAME_H_
#include "config.h"

typedef struct {
} GameState;

#ifdef HOTRELOAD
typedef void(game_draw_t)(GameState *, const float);
#else
void game_draw(GameState *, const float);
#endif // DEBUG

#endif // _GAME_H_
