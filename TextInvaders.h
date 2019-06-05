#ifndef TEXTINVADERS_H_INCLUDED
#define TEXTINVADERS_H_INCLUDED

#include <vector>
#include <iostream>

/*

This game is build alongside a course taught in udemy by Serge Lansiquot in his course entitled
        Learn C++ programming by Making Games

This is the last lesson game that is made during the course

Space Invaders

The object of the game is to shoot the invaders with your missile base while avoiding their shots and
preventing an invasion. Ammassing a high score is a further objective and one that must be prioritised
agaisnt your continued survival.

The bottom 2 score 10 points per large invader, the middle 2 rows 20 points for each medium invader and
the top row scores 30 points for each small invader. This make each worth a total of 990 points

The score for each screen can be dramatically increased by the destruction of the mystery value spaceships that
frequesntly fly from one side of the screen to the other.
The mystery ufo should have a points value of 50 to 200 points.

Teomporary sanctuary can sought beneath the 4 base shields. Shields are destructible by both the player and the aliens.
Only the part of the shield hit by either a player missile or alien bomb shold be destroyed not the entire shield.

The invaders travel sideways and each time they touch the side they drop down 1 line.
On screen 1 they need to drop 11 lines to reach the botton and 'invade'.
From screen 2 through to screen 9 they start progressively lover down the screen
At screen 10 the game revert to the screen start posistion and the cycle begins again.


There is no time limit, except for the fact that if you do not shoot them all before they reach the bottom of the
screen the game ends.

The more invaders the player shoots. the faster the remaining invaders move
When the invaders are low enough to touch the base shelters they erase them as they pass. The last invader moves very quickly

Any bombs dropped by an invader on the row above 'invasion' row will not harm the players missle.

The aliens can have a maximum of 3 bombs on screen at any time , The player can have only 1 missile shot on screen at any one time.

If the player is hit, the should pause, and the player should be showing the exploding animation

If an alien is hit, the should explode for a short period of time then disappear.

there should be an intro screen, game over screen(where the player can enter their name) , and high score screen
There should be a high score table that can be seen from the initial welcome screen and after the game is ove and the player enters
his/her three letter name


All regular aliens are 2 by 4 in terms of size(2 rows of 4 columns)

The player is 2 by 5
Alien ufo is 2 by 6

Alien sprites:
30 points aliens: /oo\  /oo\
                   <>   /""\

20 points aliens:  ><  |><|
                  |\/| /  \



 General Data
 -------------------------
 Player
 Alien
 Shields
 Alien bombs
 Player missiles
 Game states
 Scores
 High Score table


 Player
 ------------------------
 Position
 Missile
 Aimation state
 Size of the sprite
 Lives(3)
 Score

 Shields
 ------------------------
 Sprites


 Alien swam (all the 10, 20, 30 point aliens)
 ------------------------
 Position
 Direction(left or right)
 Animations states
 Size of each alien
 State that they are in(alive, dead or exploding)
 Alien bombs

 Alien UFO
 -------------------------
 Size for the sprite
 Position

 Points


 Position
 -----------------------------
 x, y coordinate


 Alien bomb
 ---------------------------------
 position
 animation state -\|/-


 Missile
 -----------------------------------
 Position


 Game
 -----------------------------------
 level
 Game state
 size of the window




*/
enum
{

    SHIELD_SPRITE_HEIGHT = 3,
    NUM_ALIEN_ROWS = 5,
    NUM_ALIEN_COLUMNS = 11,
    MAX_NO_OF_ALIEN_BOMBS = 3,
    MAX_NO_OF_LIVES = 3,
    PLAYER_SPRITE_WIDTH = 3,
    PLAYER_SPRITE_HEIGHT = 2,
    NOT_IN_PLAY = -1

};

enum AlienState
{
    ALIVE = 0,
    DEAD,
    EXPLODING,
};

enum GameState
{
    GS_INTRO,
    GS_HIGH_SCORES,
    GS_PLAY,
    GS_PLAYER_DEAD,
    GS_WAIT,
    GS_GAME_OVER
};

struct Position
{
    int x;
    int y;
};

struct Size
{
    int width;
    int height;
};

struct Player
{
    Position positions;
    Position missile_pos;
    Size spriteSize;
    int animation;
    int lives; //max 3 lives
    int score;
};

struct shields
{
    Position positions;
    char *sprite[SHIELD_SPRITE_HEIGHT];
};

struct AlienBomb
{
    Position positions;
    int animation;
};

struct AlienSwam
{
    Position positions;
    AlienState aliens[NUM_ALIEN_ROWS][NUM_ALIEN_COLUMNS];
    AlienBomb bombs[MAX_NO_OF_ALIEN_BOMBS];
    Size spriteSize;
    int animation;
    int directions;
    int numberOfBombsInPlay;
    int movementTime;   //how it will simulate it movements
    int explosionTimer; //capture how long to explode for
    int numAliensleft;  //Capture when to restart or to the next level
    int line;           //capture when the aliens win.
};

struct AlienUfo
{
    Position positions;
    Size spritesize;
    int points;
};

struct Score
{
    int score;
    std::string name;
};

struct HighScoreTable
{
    std::vector<Score> scores;
};

struct Game
{
    Size windowSize;
    GameState currentState;
    int level;
};
#endif // TEXTINVADERS_H_INCLUDED
