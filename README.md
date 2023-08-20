# Race_Simulation
**Summary** <br>
This program simulates the classic race of the Tortoise and the Hare. 
The race track is represented by a 70 tile long track, where both animals begging at index 0. Every 1 second, a random movement patter is chosen for the tortoise and the hare, and their index is adjusted forward, backward, or no movement (Keep in mind, the tortoise will have more, but shorter movements, and the hare will have more inconsistent, but aggressive movements). First animal to reach the last tile wins.
**Example output**


_Moving forward, I describe each function individually <br>
**main function** <br>
An array, called "track", of size 70 is populated by underscores '_', to vizually represent the race track. 
Within a for loop, we determine a random number between 1-10 with rand(), and srand() (random seed), and store it a variable called "movement_dictator". At which point, we call moveTortoise and moveHare, handing it the track, movement_dictator, and the corresponding animal's current index in the track. 
After the functions execute, they will return the new indeces of the animals. Here, the program checks if both their indeces are 69, in which case we establish it is a tie, and exit. Otherwise, if only one index is 69, we declare a winner and exit. 

If no animal has reached the last tile, program checks if they have landed on the same tile. If that is the case, the tortoise bites the hare, and we print the string "OUCH!!!", starting from the overlapping index. For example, if the overlapping index was 20, we print "OUCH!!!" from index 20 to 27. 










Race track is represented by a 70 tile long array populated by underscores '_'. Position of the hare is represented by 'H', and 'T' for the tortoise. Movement of the animals will the conducted by functions moveTortoise, and moveHare. 
In certain scenarios the 'H' and 'T' characters might land on the same tile. In that case, the string "OUCH!!!"

**Determinating random movement of the Tortoirse and Hare**
Each loop, program uses rand(), and srand() (random seed), to generate a random number between 1-10. This random number is given to functions moveTortoise and moveHare. Within these functions, a movement pattern is choosen according to the random number. 



