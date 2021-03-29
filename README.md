# Bomberman

Controls:

● Player 1
	○ Move - WASD
	○ Place bomb - Spacebar
● Player 2
	○ Move - ↑←↓→
	○ Place bomb - Right shift

Features:

● Top-down view on the level ✓
● One map ✓
● Co-Op: Two players play on one machine using the same keyboard ✓
	○ Make the characters distinguishable somehow (color, nameplate, …) ✓
● Implementation of different power-ups ✓
	○ Increased range of bomb blasts ✓
	○ More bombs (can be applied multiple times) ✓
	○ Faster run speed ✓
	○ Remote-controlled bombs (timed power-up, 10 seconds)
● Bomb placing ✓
	○ Player starts with being able to have a single bomb on screen at a time ✓
	○ The bomb explodes after 3 seconds ✓
	○ Placing a bomb subtracts one from the count, when the bomb explodes the count
	goes up again ✓
	○ Amount of active bombs can be increased with pickups ✓
	○ Once the remote detonator has been picked up only one bomb can be active until the
	power-up runs out
● Player death when standing in bomb blast ✓
● Bomb blasts ✓
	○ Along X/Y axis
	○ Can penetrate players/power-ups when going off (killing/destroying them)
	○ Are stopped by walls
	○ Trigger other bombs
● Differentiation between destructible and indestructible walls, destructible walls can spawn
random power-ups (~30% chance to spawn something) upon destruction ✓
● Win conditions:
	○ On end of round, freeze game in its current state ✓
	○ Show win screen when only one player is alive
	○ Show a timer, that counts down to the end of the round
	○ Show “Draw” when both players die in the same bomb blast or multiple players are alive
	when the timer runs out
● Reset option on end screen
	○ Starts another round
	○ Previous score should be saved