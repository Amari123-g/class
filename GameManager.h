#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include <string>

enum class GameState {
    Setup,
    PlayerTurn,
    OpponentTurn,
    Combat,
    GameOver
};

class GameManager {
public:
    GameManager();

    // Game flow
    void initializeGame(const std::string& player1Name, const std::string& player2Name);
    void startGame();
    void endTurn();
    void checkWinCondition();
    
    // Getters
    GameState getCurrentGameState() const { return gameState; }
    Player* getCurrentPlayer() { return currentPlayer; }
    Player* getOpponentPlayer() { return opponentPlayer; }
    int getTurnCount() const { return turnCount; }
    bool isGameOver() const { return gameState == GameState::GameOver; }
    Player* getWinner() const { return winner; }

private:
    Player* player1;
    Player* player2;
    Player* currentPlayer;
    Player* opponentPlayer;
    Player* winner;
    GameState gameState;
    int turnCount;

    void switchTurns();
};

#endif // GAMEMANAGER_H