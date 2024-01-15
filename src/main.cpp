#include "Game.h"
#include "Menu.h"
// app entrypoint

int main() {
    Game g(new Menu());
    g.Run();

    return 0;
}