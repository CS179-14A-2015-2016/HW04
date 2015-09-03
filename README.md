HW04 — RPS-card (deadline: 2015-09-10)
===

Make a C++ modified card-based Rock-paper-scissors game. This is similar to KH: Chain of Memories.

Mechanics
====
* Each player is allocated 15 cards.
  * Two of the cards are jokers. (the "0" cards)
  * The rest are labeled 1 to 13.
* Each player uses a card to "joust".
  * The jousts will keep on going until all cards are used up. So there will be 15 rounds/jousts in total.
  * A player gets a point only when he wins the joust. For a draw, no points will be given to any player.
* Except for the jokers, a higher card beats a lower card. But 1 beats 13 (i.e. 1 loses to every normal card except 13). For example:
  * 2 beats 1
  * 3 beats 2
  * 10 beats 1
  * 13 beats 12
  * 12 beats 1
  * 1 beats 13
* The jokers randomly wins or loses against the other card.
  * If both players chose jokers, then there's 50% chance of a draw, 25% chance of the the first player winning, and 25% chance of the other player winning.


Format
====
TODO

Tip: Use [this](http://stackoverflow.com/a/32008479) to "clear" the screen.

Sample
====


```
A - Available cards: 0 0 1 2 3 4 5 6 7 8 9 10 11 12 13
a>
```

Player A selects `4`

```
Press enter when player B is ready...
```

```
B - Available cards: 0 0 1 2 3 4 5 6 7 8 9 10 11 12 13
b>
```
Player B selects `0`

```
Joust: 4 vs 0
Player B wins by chance!
Press enter when player A is ready...
```

```
A - Available cards: 0 0 1 2 3 5 6 7 8 9 10 11 12 13
a>
```
Player A selects `1`

```
Press enter when player B is ready...
```

```
B - Available cards: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
b>
```
Player B selects `12`

```
Joust: 1 vs 12
Player B wins!
Press enter when player A is ready...
```

Etc.

Then when all cards are exhausted:

```
Joust: 0 vs 0
Both players draw by chance!
Player A: 4
Player B: 10
Player B wins!
```
  
