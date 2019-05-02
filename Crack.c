
                    // Amadou Arifa Arifa Mamane


#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <crypt.h>

#define SALT "50"

int main(int argc, char **argv)
{
  //Condition that can allow the code to know wheither the user is putting a correct command to compile the code
if (argc == 2)
{
    char *hash = argv[1];

    // Create an array of characters to be used with upper and lower case alphabet letters (+the '\0'). Means 26+26+'\0'=53 Characters
    char alphabet[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Creating a password that 5 characters long (+ the '\0')
    char passwd[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};

// Looping  through the iterations "inside-out" in order to creat "a hash"

for(int car5 = 0; car5 < 52; car5++) //  5th character
    {
    for(int car4= 0; car4 < 52; car4++) //  4th character
        {
        for(int car3= 0; car3 < 52;car3++) // 3rd character
            {
            for(int car2= 0; car2< 52; car2++) // 2nd character
                {
                for(int car1= 0; car1 < 52; car1++) // 1st character
                    {
                        passwd[0] = alphabet[52];  // The 1st character loop

                        // Comparing the generated hash
                        char *passwdCrypt = crypt(passwd, SALT);
                        if(strcmp(hash, passwdCrypt) == 0)
                        {
                            //printing the cracked password after all
                            printf("The Cracked password is: %s\n", passwd);
                            return 0;
                        } //Looping Character by character
                    }
                    passwd[1] = alphabet[car2];  // Character 2
                }
                passwd[2] = alphabet[car3];  // Character 3
            }
            passwd[3] = alphabet[car4];  // Character 4
        }
        passwd[4] = alphabet[car5];  // Character 5
    }
}
else // If the command put when compiling is incorrect to return at the top (1)
{
    printf("Go back to: ./Crack put your hash here!\n");
    return 1;
}
}
