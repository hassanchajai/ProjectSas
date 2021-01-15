#include <stdio.h>
#include <stdlib.h>
#define max 1000
// begin of structures


// president
struct election
{
    char name[50];
    int vote;
};

struct electeur
{
    char cin[20];
};

//end of structure
// function calcul percentage

float CalculPercenetage(int votes, int counter) { return (votes * 100 / counter); }

// end of function calcul
int main()
{
    // variables

    // total des eleteurs et presidents entre par uttilisateur
    int nbELecteurs = 0, nbELections = 0;

    struct election elections[max],electionsDeuxTour[max],electionsTirthTour[max];

    struct electeur electeurs[max];

    // des tables entier pour stocker les indeces de presidents passe a lautre tour
    int ElectionHaventOverPercentage[max],
        countElectionPassFirstTour = 0,
        ElectionPassSecondTour[max],
        CountElectionSecondTour = 0;

//  variable pour checker les condition de chaque tour est valide
    int cond = 0;

    // remplir les presidents

    printf("Entre au minimum 5 election \n");
    for (int i = 0; i < max; i++)
    {

        printf("Entre le %d election \n", i + 1);

        scanf("%s", elections[i].name);

        elections[i].vote = 0;

        nbELections++;

        if (i >= 4)
        {
            int a = 0;
            printf("Vous voulez stopper remplissage de les elections \n");
            printf("tapper 1 \n");
            printf("tapper any number to continue \n");
            scanf("%d", &a);

            if (a == 1)
                break;
        }
    }

    // remplir les électeurs

    system("cls");

    printf("\t \t \t Entre au minimum 10 electeur \n");

    for (int i = 0; i < max; i++)
    {
        printf("entre le %d electeur \n", i + 1);

        scanf("%s", &electeurs[i].cin);


        nbELecteurs++;

        if (i >= 9)
        {
            int a = 0;
            printf("vous voulez stopper remplissage de les elections \n");
            printf("tapper 1 \n");
            printf("tapper any number to continue \n");
            scanf("%d", &a);

            if (a == 1)
                break;
        }
    }

    system("cls");
//  list des presidents , c  = count les presidents
    void vottage(struct election list[max], int c)
    {
        // L'instialisation de vote de table list(presidents)
        // c total de presidents
        for (int i = 0; i < c; i++)
        {
            list[i].vote = 0;
        }

        for (int i = 0; i < nbELecteurs; i++)
        {
            // lappel de chaque un  electeur pour voter
            // todo : hna nchufo wsh deja mvoti

            printf("Bonjour  %s \n", electeurs[i].cin);
            //  affiche le menu avec
            for (int b = 0; b < c; b++)
            {
                printf("Pour voter %s tape %d \n", list[b].name, b + 1);
            }
            int IdElection = 0;

            // Verification

             // verifier if lindece is exist
              int counter=0;
              do
              {
                if(counter > 0)printf("Entre president en dependant la list : \n");
                scanf("%d", &IdElection);
                counter++;
              }
              while (IdElection <=0 || IdElection > c);







            list[IdElection - 1].vote++;
        }
    }

    // tour 1

    while (cond == 0)
    {

        vottage(elections, nbELections);
        // elimination
        for (int i = 0; i < nbELections; i++)
        {
            if (CalculPercenetage(elections[i].vote, nbELecteurs) >= 15)
            {

                ElectionHaventOverPercentage[countElectionPassFirstTour] = i;
                countElectionPassFirstTour++;
            }
        }

        if (countElectionPassFirstTour >= 0)
            cond = 1;
    }

    // end of while
    if (countElectionPassFirstTour == 0)
    {
        system("cls");
        printf( "\t\t\t\t tous les elections eliminé \n ");

        return 0;
    }
    else if (countElectionPassFirstTour == 1)
    {

        system("cls");
        printf("\t\t\t\t Congrats ur the president now %s  \n", elections[ElectionHaventOverPercentage[0]].name);
    }

    else
    {
        //  EFFICHER ET REMPLIR LA TABLE DE 2 TOUR
         printf("\t\t\t\t les presidents sont qualifié \n");
        for (int i = 0; i < countElectionPassFirstTour; i++)
        {

            electionsDeuxTour[i] = elections[ElectionHaventOverPercentage[i]];

         

            printf("President  %d :  %s   \n",i ,electionsDeuxTour[i].name);
        }

        printf("\t\t\t La 2EME tour \n");
        // TOUR 2
        cond = 0;
        while (cond == 0)
        {
            int indexofMIN = 0;
            int indexofMAX = 0;
            vottage(electionsDeuxTour, countElectionPassFirstTour);
            // elimination
            for (int i = 1; i < countElectionPassFirstTour; i++)
            {
                if (electionsDeuxTour[i].vote > electionsDeuxTour[indexofMAX].vote)
                {
                    indexofMAX = i;
                }
                if (electionsDeuxTour[i].vote < electionsDeuxTour[indexofMIN].vote)
                {
                    indexofMIN = i;
                }
            }


            // condition if all the  presidents equals repeat the tour
            // check if counter equal to taille

            int counter = 0;
            for (int i = 0; i < countElectionPassFirstTour; i++)
            {
                if (electionsDeuxTour[indexofMIN].vote == electionsDeuxTour[i].vote)
                {
                    counter++;
                }
                else
                {
                    ElectionPassSecondTour[CountElectionSecondTour] = i;
                    CountElectionSecondTour++;
                }
            }

            if (counter == countElectionPassFirstTour)
            {
                printf("all the presidents is equals \n");

                continue;
            }
            else if (countElectionPassFirstTour - counter == 1)
            {

                printf("Congrats ur the president  now  %s \n", electionsDeuxTour[indexofMAX].name);

                return 0;
            }

            //  counter > 1 && counter < countElectionPassFirstTour
            else
            {

                // stocker les presidents passer a lautre tour
             for (int i = 0; i < CountElectionSecondTour; i++)
             {
                electionsTirthTour[i]=electionsDeuxTour[ElectionPassSecondTour[i]];
             }

            }


            cond = 1;

        }

        // Tour3
        if (cond==1)
        {
            // begin

            system("cls");
            printf("\t\t\t\t la 3eme tour \n\n");
            printf("\t\t\t\t les presidents sont qualifié \n");
            for(int i=0; i<CountElectionSecondTour;i++){
                printf("\t\t\t\t president %s \n",electionsTirthTour[i].name);
            }
            cond = 0;
            while (cond == 0)
            {
                int indexofMIN = 0;
                int indexofMAX = 0;
                vottage(electionsTirthTour, CountElectionSecondTour);
                // elimination
                for (int i = 1; i < countElectionPassFirstTour; i++)
                {
                    if (electionsTirthTour[i].vote > electionsTirthTour[indexofMAX].vote)
                    {
                        indexofMAX = i;
                    }
                }


                // condition if all the  presidents equals repeat the tour
                int counter = 0;
                for (int i = 0; i < CountElectionSecondTour; i++)
                {
                    if (electionsTirthTour[indexofMAX].vote == electionsTirthTour[i].vote)
                    {
                        counter++;
                    }

                }


                if (counter == 1)
                {
                    system("cls");
                    printf("\t\t\t\t Congrats ur the president  now  %s \n", electionsTirthTour[indexofMAX].name);

                    return 0;
                }
                else{

                        printf(" we have some equality \n ");
                        printf("we need to repeat\n");
                        continue;
                }
            cond=1;
        }
        // end 3eme Tour
    }

    return 0;


    }
    // END OF ELSE
}
