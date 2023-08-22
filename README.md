# Race_Simulation
**Summary** <br>
This program simulates the classic race of the Tortoise and the Hare. 
The race track is represented by a 70 tile long track, where both animals beging at index 0. Every 1 second, a random movement patter is chosen for the tortoise and the hare, and their index is adjusted forward, backward, or no movement (Keep in mind, the tortoise will have more consistent, but shorter movements, and the hare will have more inconsistent, but aggressive movements). First animal to reach the last tile wins.
**Example output**
________T_______________H______________________
____________________T_______H__________________
_______________H___T___________________________
_____________________T_____H___________________
________________________T___________H__________
______________________________T________H_______

_Moving forward, I describe each function individually <br>
**main function** <br>
An array, called "track", of size 70 is populated by underscores '_', to vizually represent the race track. 
Within a for loop, we determine a random number between 1-10 with rand(), and we call moveTortoise and moveHare. After the functions execute, they will return the new indeces of the animals. With the new indeces, the program checks for a tie, or for a winner.
If no animal has reached the last tile, program checks if they have landed on the same tile. If that is the case, the tortoise bites the hare, and we print the string "OUCH!!!", starting from the overlapping index. For example, if the overlapping index was 20, we print "OUCH!!!" from index 20 to 27. 
At this point, program calls track_printer which prints the updated track. Lastly, if OUCH!!! was printed, we now delete it from the array.
For loop will return 0 when an animal reaches index 69.

**moveTortoise and moveHare**
Functions receives the track, the random number generated, and the animal's current index.
First, we initilize the variable next_tile as the animal's current tile, so we have a base index to add or subtract from. 
Each animal has a pre-set number of movements, each with a different probability. The probability is represented by the amount of numbers from 1-10. For example, the tortoise has a 50% chance to move forward 3 tiles if random number is 1-5, a 30% chance to move forward 1 tile if random number is 6-8, and a 20% chance to move backward 6 tiles if random number is 9-10.
Once we determine what the next tile will be, we check for out-of-range indeces errors (lower than 0, or higher than 69), and adjust to 0 or 69. 
With the new index, boths functions call animal_mover (handing it the animal's current tile, and the next_tile), which will swap the animals old index with the new one. 
Finally, the animal's current tile is updated with the newly established tile. This is done after calling animal_mover since we have to hand animal_mover the old index, before it is overrided. 

**animal_mover**
This function swaps the animal's previous position with its new position.
Function receives animal's name, previous tile, and next tile.
The first if conditional statement addresses a rare event. This event is explained in the following exaple. 
Example: Tortoise at index 20, hare at index 30
____________T__________H__________________
We generate random number and determine tortoise's next tile is index 30, and call animal_mover to move the tortoise. animal_mover re-assings tortoise's previous tile as '_', and next tile as 'T'.
_______________________T__________________
There is no problem yet, however, we now determine the hare's next tile, and call animal_mover to move the hare. animal_mover re-assings hare's previous tile as '_', and next tile as 'H'.
__________________________________H________
When we print the track, we only see the hare, the tortoise is not gone. In other words, when we swapped the tiles for the hare, we intentionllay overrided 'T' with an underscore. 
This event only happens when the tortoise next tile is the hare's current/old tile.
To address this, animal_mover's first condition states that if we are moving the hare, and the current tile of the hare is 'T', instead of overriding the current tile with an underscore, we override it with yet another 'T' so that tortoise position remains in the array.

Nonetheless, most of the time, animal_mover will simply re-assing the animal's previous tile with an underscore, and re-assign the next tile with a 'T' or 'H'.

**track_printer**
track_printer print the current array with a 1 second delay


// specifcy index as number and index as [] array
// specify pointers


