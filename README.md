# Race_Simulation
**Summary** <br>
This program simulates the classic race of the Tortoise and the Hare. 
The race track is represented by a 70 tile long track, where both animals begging at index 0. Every 1 second, a random movement patter is chosen for the tortoise and the hare, and their index is adjusted forward, backward, or no movement (Keep in mind, the tortoise will have more consistent, but shorter movements, and the hare will have more inconsistent, but aggressive movements). First animal to reach the last tile wins.
**Example output**


_Moving forward, I describe each function individually <br>
**main function** <br>
An array, called "track", of size 70 is populated by underscores '_', to vizually represent the race track. 
Within a for loop, we determine a random number between 1-10 with rand(), and we call moveTortoise and moveHare. After the functions execute, they will return the new indeces of the animals. With the new indeces, the program checks for a tie, or for a winner.
If no animal has reached the last tile, program checks if they have landed on the same tile. If that is the case, the tortoise bites the hare, and we print the string "OUCH!!!", starting from the overlapping index. For example, if the overlapping index was 20, we print "OUCH!!!" from index 20 to 27. 
At this point, program calls track_printer which prints the updated track. Lastly, if OUCH!!! was printed, we now delete it from the array.
For loop will return 0 when an animal reaches index 69.

**moveTortoise and moveHare**
Functions receives the track, the random number generated, and the animal's current index.
First, we initilize the variable next_tile as the animal's current tile, so we have a base to add or subtract from. 
Each animal has a pre-set number of movements, each with a different probability. The probability is represented by the amount of number from 1-10. For example, the tortoise has a 50% chance to move forward 3 tiles if random number is 1-5, a 30% chance to move forward 1 tile is random number is 6-8, and a 20% chance to move backward 6 tiles if random number is 9-10.
Once we determine what will the next tile be, we check for out-of-range indeces errors (lower than 0, or higher than 69), and adjust accordingly. 
With the new index, boths functions call animal_mover(handing it the animal's current tile, and the next_tile), which will swap the animals old index with the new one. 
Finally, the animal's current tile is updated with the newly established tile. This is done after calling animal_mover since we have to hand animal_mover the old index, before it is overrided. 

**animal_mover**





