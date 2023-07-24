#include <iostream>
#include <chrono>
#include <thread>
#include <cstring>
using namespace std;

// prototypes
void moveTortoise(char *const, const int, int *const);
void moveHare(char *const, const int, int *const);
void animal_mover(const string, char * const, char *const);
void track_printer(char const *const, const int);

int main(int argc, const char *argv[]) {
    
    const int array_size = 70;
    char track[array_size]; // race track 1-70 (0-69 index) tiles
    memset(track, '_', array_size); // populate array

    int tortoise_current_tile = 0; // initiate tortose and hare at tile 0
    int hare_current_tile = 0;

    cout << "BANG !!!! AND THEY'RE OFF!!!" << endl;
    
    
    for (int second_tracker = 0; second_tracker != -1; second_tracker++)
    {
        srand(second_tracker); // random seed
        
        int movement_dictator = rand() % 10 + 1; // random number 1-10
        
        
        moveTortoise(&track[0], movement_dictator, &tortoise_current_tile);
        moveHare(&track[0], movement_dictator, &hare_current_tile);
        
        
        if (tortoise_current_tile == 69 && hare_current_tile == 69) // its a tie
        {
            cout << "It's a tie!" << endl;
            return 0;
        }
        else if (tortoise_current_tile == 69) // tortoise wins
        {
            cout << "Tortoise wins!" << endl;
            return 0;
        }
        else if (hare_current_tile == 69) // hare wins
        {
            cout << "Hare wins!" << endl;
            return 0;
        }
        
        // if both animals land on the same tile, print "OUCH!!!" beginning at that tile's index
        int erase_ouch = 0; // variable prompts an erase of OUCH!!! text
        if (hare_current_tile == tortoise_current_tile)
        {
            string ouch_text = "OUCH!!!";
            for (int word_length = 0; word_length < 7; word_length++)
            {
                track[tortoise_current_tile + word_length] = ouch_text[word_length]; // beginning at the landing tile's index, assign first character ('O'), and then assign next character to next index, until word's length has been reached
            }
            erase_ouch = 1; // trigger a deletion of ouch text from array
        }
        
        track_printer(&track[0], array_size); // print array
        
        if (erase_ouch) // if ouch text was printed, delete it from array
            memset(track, '_', hare_current_tile + 7);
    
    }
    
    return 0;
}

// determine animal's next move and track their position
void moveTortoise(char *const trackPtr, const int movement_dictator, int *const tortoise_current_tile) // receive: race track array, random number dictating movement, and tortoise's current tile
{
    int next_tile = *tortoise_current_tile; // initialize next tile to the current tile
    
    if (movement_dictator <= 5)
        next_tile += 3;
    else if (movement_dictator <= 8)
        next_tile += 1;
    else
        next_tile -= 6;
    
    if (next_tile < 0) // if next tile is left of index 0
        next_tile = 0;
    
    if (next_tile >= 69) // if next tile is beyond index 69
        next_tile = 69;
    
    animal_mover("tortoise", & trackPtr [*tortoise_current_tile], & trackPtr [next_tile] );
    
    *tortoise_current_tile = next_tile; // after movemnet, re-declare tortoise's current tile

}

// determine animal's next move and track their position
void moveHare(char *const trackPtr, const int movement_dictator, int *const hare_current_tile) // receive: race track array, random number dictating movement, and hare's current tile
{
    int next_tile = *hare_current_tile; // initialize next tile to the current tile
    
    if (movement_dictator <= 3)
        next_tile += 1;
    else if (movement_dictator <= 5)
        next_tile -= 2;
    else if (movement_dictator <= 7)
        next_tile += 0;
    else if (movement_dictator <= 9)
        next_tile += 9;
    else
        next_tile -= 12;

    if (next_tile < 0) // if next tile is left of index 0
        next_tile = 0;
    
    if (next_tile >= 69) // if next tile is beyond index 69
        next_tile = 69;
    
    animal_mover("hare", & trackPtr [*hare_current_tile], & trackPtr [next_tile] );
    
    *hare_current_tile = next_tile; // after movemnet, re-declare hare's current tile
    
}

// swaps animal's previous position with the next
void animal_mover(const string animal, char *const tile1, char *const tile2) // receive: animal's name, last position, and new position
{
    if (animal == "hare" && *tile1 == 'T') // It prevents an override when toirtoise's next move was hare's previos position
        *tile1 = 'T';
    else
        *tile1 = '_'; // this else condition will execute in the vast majority of cases
        
    if (animal == "tortoise")
        *tile2 = 'T';
    else if (animal == "hare")
        *tile2 = 'H';
    
}

// prints race track array
void track_printer(char const *const trackPtr, const int array_size)
{
    this_thread::sleep_for(1s); // delay of 1s between printing
    
    for (int i = 0; i < array_size; i++)
        cout << trackPtr[i];
    
    cout << endl;
}
