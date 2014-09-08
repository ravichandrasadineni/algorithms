#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generate_preferences(int manPreferences[4][4], int womanPreferences[4][4]) {
    int man, preference,woman, i;
    for(man=0; man<4; man++)
    {
        for (preference = 0; preference<4; preference ++ ) 
        {
            int currentPreference = rand()%4;
            for(i = 0; i < preference;) {
                if(manPreferences[man][i] == currentPreference) {
                    i= 0;
                    currentPreference = rand()%4;
                }
                else {
                    i++ ;
                }
            }
            printf("\t %d", currentPreference );
            manPreferences[man][preference] = currentPreference;
        }
        printf("\n");
    }



    for(woman=0; woman<4; woman++)
    {
        for (preference = 0; preference<4; preference ++ ) 
        {
            int currentPreference = rand()%4;
            for(i = 0; i < preference;) {
                if(womanPreferences[woman][i] == currentPreference) {
                    i= 0;
                    currentPreference = rand()%4;
                }
                else {
                    i++;
                }
            }
            printf("\t %d", currentPreference );
            womanPreferences[woman][preference] = currentPreference;
        }
        printf("\n");
    }
     
}


int* stable_matching(int menPreferences[4][4], int womenPreferences[4][4], int menOrder[4]) {
    

}

int main (int argc, char* argv[]) {
    srand(clock());
    int menPreferences[4][4], womenPreferences[4][4];
    generate_preferences(menPreferences,womenPreferences);



}
