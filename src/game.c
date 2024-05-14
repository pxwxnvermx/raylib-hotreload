#include "game.h"
#include "raylib.h"

void game_draw(GameState *game_state, const float delta) {
  // game_draw code
  BeginDrawing();
  ClearBackground(RAYWHITE);
  DrawText("Raylib hotreload", 10, 10, 20, BLACK);
  EndDrawing();
}
