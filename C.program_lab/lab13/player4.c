/* 	blackjack player functions
 * 4 functions are needed
 * bet_init: before cards are dealt, initial bet is made
 * hit_or_stand: after cards are dealt, player needs to make a decision
 * whether to hit or stand
 * shuttle: when the decks of cards are all used, dealer reshuffle
 * the decks, and each player is notified
 * deal_one_card: when each card is dealt by the dealer, each player is
 * notified what card is dealt
 *
 */
#include <stdio.h>
#include "card.h"

extern int step_display;
extern int Nhands;
char play4_name[9] = "KuanChu";

// this function places a bet before cards are dealt
// input: the amount of credit left for the user
// output: how much the player want to bet for this round
// algorithm: bet no more than 3

int play4_bet_init(const int credit){
	step_display = 1; // by turning off this, it speed up the game
	Nhands = 100; // number of hands to be played
	if (credit >= 3) return 3;
	else return credit;
}

// this function decides if to hit for more cards or not
// input: player's cards (and number of cards)
// dealer's cards (and number of cards)
// Note, at this time dealer has only one card
// output: 1 to hit; 0 to stand, 2: double (receive only 1 card), 3: surrender
// algorithm: hit if player's points is less than 17

int play4_hit_or_stand(const struct CARD mycard[], int Nmycard,\
const struct CARD dealercard[], int Ndealercard){
	if (sum_cards(mycard, Nmycard) >= 17) return 0;
	else return 1;
}

int main(void){
	
