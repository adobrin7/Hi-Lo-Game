#pragma once
#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include <iostream>

extern bool worksFine;

int getValue();

// gives advice based on the comparison of the hidden and entered value
void giveAdvice(int generated_value, int input);

int setDifficultyFactor();

bool startRound(int randomValue, int difficulty);

bool askToContinue();


#endif // GAME_FUNCTIONS_H