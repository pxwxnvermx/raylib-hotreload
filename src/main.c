#include "game.h"
#include "raylib.h"

#include "config.h"

#ifdef HOTRELOAD
#include "assert.h"
#include "dlfcn.h"
#include "stdio.h"

static const char *libgame_file_name = "libgame.so";
static void *libgame = NULL;
static game_draw_t *game_draw = NULL;

bool reload_libgame(void) {
  if (libgame != NULL)
    dlclose(libgame);

  libgame = dlopen(libgame_file_name, RTLD_NOW);
  assert(libgame != NULL);

  game_draw = dlsym(libgame, "game_draw");
  assert(game_draw != NULL);
  return true;
}
#endif /* HOT_RELOAD */

int main() {
  InitWindow(WINDOW_W, WINDOW_H, "RAYLIB HotReload");

  GameState game_state = {};

  reload_libgame();

  while (!WindowShouldClose()) {
    const float delta = GetFrameTime();

#ifdef HOTRELOAD
    if (IsKeyPressed(KEY_R)) {
      reload_libgame();
    }
#endif /* HOTRELOAD */

    game_draw(&game_state, delta);
  }

  CloseWindow();
  return 0;
}
