# Race_Simulation
**Summary** <br>
This program simulates the classic race of the Tortoise and the Hare. 
The race track is represented by a 70 tile long track, where both animals beging at index 0. Every 1 second, a random movement patter is chosen for the tortoise and the hare, and their index is adjusted forward, backward, or no movement (Keep in mind, the tortoise will have more consistent, but shorter movements, and the hare will have more inconsistent, but aggressive movements). If tortoise and hare land on the same tile, tortoise bites the hare and program prints "OUCH!!!". First animal to reach the last tile wins. <br>
**Example output** <br>
\_\_\_\_\_H\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_T\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ <br>
\_\_\_\_\_\_\_\_\_H\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_T\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ <br>
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_H\_\_\_T\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ <br>
\_\_\_\_\_\_\_\_\_\_\_\_OUCH!!!\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_<br>
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_H\_\_\_\_\_\_\_T\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ <br>
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_H\_\_\_\_\_\_\_\_\_\_\_T\_\_\_\_\_\_\_\_ <br>


**animal_mover -> preventing an override when toirtoise's next move was hare's previos position** <br>
This function swaps the animal's previous position with its new position.  <br>
Function receives animal's name, previous tile, and next tile.  <br>
The first if conditional statement addresses a rare event. This event is explained in the following exaple.  <br>
Example: Tortoise at index 20, hare at index 30  <br>
\_\_\_\_\_\_\_\_\_\_\_\_T\_\_\_\_\_\_\_\_\_\_\_\_\_H\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ <br>
We generate random number and determine tortoise's next tile is index 30, and call animal_mover to move the tortoise. animal_mover re-assings tortoise's previous tile with an underscore, and next tile as 'T'.  <br>
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_T\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ <br>
There is no problem yet, however, we now determine the hare's next tile, and call animal_mover to move the hare. animal_mover re-assings hare's previous tile as '_', and next tile as 'H'.  <br>
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_H\_\_\_\_\_\_\_\_ <br>
When we print the track, we only see the hare, the tortoise is not gone. In other words, when we swapped the tiles for the hare, we intentionllay overrided 'T' with an underscore.   <br>
This event only happens when the tortoise next tile is the hare's current/old tile.  <br>
To address this, animal_mover's first condition states that if we are moving the hare, and the current tile of the hare is 'T', instead of overriding the current tile with an underscore, we override it with yet another 'T' so that tortoise position remains in the array.  <br>

Nonetheless, most of the time, animal_mover will simply re-assing the animal's previous tile with an underscore, and re-assign the next tile with a 'T' or 'H'. <br>
 

