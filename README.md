# Fantasy-Football-Drafter
A program that algorithmically selects fantasy football players in a draft.


TileStack and TileNode structure is written by Marty Stepp for Stanford's CS106B and require the Stanford C++ library. TileStack and tilemain files were rewritten to create a fantasy football draft program.

Between each round's selection, selections made by other teams are entered into the console. When it is time for your team to pick a player, the algorithm takes into account team positional needs, available players, and the rate at which positions are being taken off the board. Based on season points projections for each player, the algorithm uses an "opportunity cost" approach to decide which position to select each round. Whichever position would take the largest hit in points by waiting another round to pick that position is the one to be selected that round. There are positional restrictions that keeps the program from doing things like picking a fifth running back rather than a starting quarterback. The aim of the algorithm is to optimize the entire team's projected points for the season.

