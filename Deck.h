#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include <algorithm>
#include <random>

class Deck {
public:
    Deck() = default;

    // Deck operations
    void addCard(const std::string& cardName);
    std::string drawCard();
    void shuffle();
    void reset();
    
    // Getters
    int getDeckSize() const { return deck.size(); }
    int getDiscardSize() const { return discard.size(); }
    const std::vector<std::string>& getDeckCards() const { return deck; }

    // Reshuffle discard pile into deck if needed
    void reshuffleDiscardIntoDeck();
    void addToDiscard(const std::string& cardName);

private:
    std::vector<std::string> deck;
    std::vector<std::string> discard;
    std::mt19937 rng;
};

#endif // DECK_H
