#include <iostream>
#include "CursesUtils.h"
#include "TextInvaders.h"

using namespace std;

void InitGame(Game &game);
void ResetPlayer(const Game &game, Player &player);
void InitPlayer(const Game &game, Player &player);
void ResetMissile(Player &player);
char HandleInput(const Game &game, Player &player);

int main()
{

    Game game;
    Player player;

    InitializeCurses(true);

    cout << "hello world" << endl;
    InitGame(game);
    InitPlayer(game, player);

    char input;
    bool quit = false;

    while (!quit)
    {
        input = HandleInput(game, player);
        // UpdateGame(game, player);
        ClearScreen();
        // DrawGame(game, player);
        RefreshScreen();
    }

    ShutdownCurses();
    return 0;
}

void InitGame(Game &game)
{
    // setting the window size
    game.windowSize.width - ScreenWidth();
    game.windowSize.height - ScreenHeight();

    // setting the game level
    game.level = 1; //change to GS_INTRO at the end
    game.currentState = GS_PLAY;
}

void ResetPlayer(const Game &game, Player &player)
{
    player.positions.x = game.windowSize.width / 2 - player.spriteSize.width / 2;
    player.positions.y = game.windowSize.height / 2 - player.spriteSize.height - 1;
    player.animation = 0;
    ResetMissile(player);
}

void InitPlayer(const Game &game, Player &player)
{
    player.lives = MAX_NO_OF_LIVES;
    player.spriteSize.height = PLAYER_SPRITE_HEIGHT;
    player.spriteSize.width = PLAYER_SPRITE_WIDTH;
    ResetPlayer(game, player);
}

void ResetMissile(Player &player)
{
    player.missile_pos.x = NOT_IN_PLAY;
    player.missile_pos.y = NOT_IN_PLAY;
}
char HandleInput(const Game &game, Player &player)
{

    return ' ';
}