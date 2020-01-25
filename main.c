/*

This program will allow the user to play
two mini games Dice and WWTBAM.

mcq <- {question,options,correct}

function generateQuestions(){ 
    generates 10 questions for WWTBAM
end 
}

function printDice(Argument one){ 
    prints the structure of the dice with * and - provided the number in argument "one"
end 
}

function loadDice(Argument one, Argument two){
    score <- 0  
    for i <-0 to 5 :
        random <- GenerateRandomNumber() mod 6
        answer <- input from user
        printDice(random)
        if random==answer:
            score <- score + 1
        else
            score <- score + 0
    if score == 4
        print "Win"
    else print "Loss"
end 
} 

function loadMillionaire(){
    i <- 0
    while(true) :
        print question from generatedQuestions
        input <- Take the input number from the user for answer
        if correct == input
            if i==10:
                print "Congrats"
            else i <- i + 1
        else break;
end 
} 
  
{ 
In the main function 
     
   while(true):
        print prompt "select game"
        input <- Take the input number from the user 
        if input == 1
                loadDice() with reload option
        if input == 2
                loadMillionaire() with reload option
        if input == 3
                exit 

    end
} 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question //question struct acts the data structure for the array of question 
{
    char q[140]; //question
    char a[140]; //option1
    char b[140]; //option2
    char c[140]; //option3
    char d[140]; //option4
    int correct; //correct option
};

typedef struct question mcq; 

mcq arr[10]; //array of questions declared

void generateQuestions() // each question is defined here with strcpy to copy string and correct option
{
    strcpy(arr[0].q, "Grand Central Terminal, Park Avenue, New York is the world's");
    strcpy(arr[0].a, "largest railway station");
    strcpy(arr[0].b, "highest railway station");
    strcpy(arr[0].c, "longest railway station");
    strcpy(arr[0].d, "None of the above");
    arr[0].correct = 1;

    strcpy(arr[1].q, "Entomology is the science that studies");
    strcpy(arr[1].a, "Behavior of human beings");
    strcpy(arr[1].b, "Insects");
    strcpy(arr[1].c, "The origin and history of technical and scientific terms");
    strcpy(arr[1].d, "The formation of rocks");
    arr[1].correct = 2;

    strcpy(arr[2].q, "Eritrea, which became the 182nd member of the UN in 1993, is in the continent of");
    strcpy(arr[2].a, "Asia");
    strcpy(arr[2].b, "Africa");
    strcpy(arr[2].c, "Europe");
    strcpy(arr[2].d, "Australia");
    arr[2].correct = 2;

    strcpy(arr[3].q, "Garampani sanctuary is located at");
    strcpy(arr[3].a, "Junagarh, Gujarat");
    strcpy(arr[3].b, "Gangtok, Sikkim");
    strcpy(arr[3].c, "Kohima, Nagaland");
    strcpy(arr[3].d, "Diphu, Assam");
    arr[3].correct = 4;

    strcpy(arr[4].q, "For which of the following disciplines is Nobel Prize awarded?");
    strcpy(arr[4].a, "Physics and Chemistry");
    strcpy(arr[4].b, "Physiology or Medicine");
    strcpy(arr[4].c, "Literature, Peace and Economics");
    strcpy(arr[4].d, "All of the above");
    arr[4].correct = 4;

    strcpy(arr[5].q, "Epsom (England) is the place associated with");
    strcpy(arr[5].a, "Horse racing");
    strcpy(arr[5].b, "Polo");
    strcpy(arr[5].c, "Shooting");
    strcpy(arr[5].d, "Snooker");
    arr[5].correct = 1;

    strcpy(arr[6].q, "Hitler party which came into power in 1933 is known as");
    strcpy(arr[6].a, "Nazi Party");
    strcpy(arr[6].b, "Labour Party");
    strcpy(arr[6].c, "Ku-Klux-Klan");
    strcpy(arr[6].d, "Democratic Party");
    arr[6].correct = 1;

    strcpy(arr[7].q, "FFC stands for");
    strcpy(arr[7].a, "Foreign Finance Corporation");
    strcpy(arr[7].b, "Film Finance Corporation");
    strcpy(arr[7].c, "Federation of Football Council");
    strcpy(arr[7].d, "None of the above");
    arr[7].correct = 2;

    strcpy(arr[8].q, "Fastest shorthand writer was");
    strcpy(arr[8].a, "Dr. G. D. Bist");
    strcpy(arr[8].b, "J.R.D. Tata");
    strcpy(arr[8].c, "J.M. Tagore");
    strcpy(arr[8].d, "Khudada Khan");
    arr[8].correct = 1;

    strcpy(arr[9].q, "First human heart transplant operation conducted by Dr. Christiaan Barnard on Louis Washkansky, was conducted in");
    strcpy(arr[9].a, "1967");
    strcpy(arr[9].b, "1968");
    strcpy(arr[9].c, "1958");
    strcpy(arr[9].d, "1922");
    arr[9].correct = 1;
}

void printDice(int number)
{
    /*considers dice as 5x5 block showing a basic graphical representation of dice. Example:
    
    - - - - - 
    - *   * - 
    -   *   - 
    - *   * - 
    - - - - - 

    a dice showing 5 value

    */
    int i, j;
    for (i = 0; i < 5; i++) //print first dashed line of dice
    {
        printf("- ");
    }
    printf("\n");
    for (j = 0; j < 3; j++)
    {
        for (i = 0; i < 5; i++)
        {
            if (i == 0 || i == 4) //prints terminal dashes
            {
                printf("- ");
            }
            else
            {

                if (j == 1 && (number == 1 || number == 5) && i == 2) //logic for printing center * 
                {
                    printf("* ");
                }
                else if ((j == 0 && number == 2 && i == 3) || (j == 2 && number == 2 && i == 1)) //logic for 2 corner center *
                {
                    printf("* ");
                }
                else if ((j == 0 && number == 3 && i == 3) || (j == 1 && number == 3 && i == 2) || (j == 2 && number == 3 && i == 1)) //logic for 3 corner center *
                {
                    printf("* ");
                }
                else if ((j == 0 && (number == 4 || number == 5 || number == 6) && (i == 1 || i == 3)) || (j == 2 && (number == 4 || number == 5 || number == 6) && (i == 1 || i == 3)) || (j == 1 && (number == 6) && (i == 1 || i == 3))) //logic for 2 parallel sets of *'s
                {
                    printf("* ");
                }

                else //covers remaining space with blanks
                {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
    for (i = 0; i < 5; i++) //print first dashed line of dice
    {
        printf("- "); 
    }
    printf("\n");
}

void loadDice()
{
    int score = 0; //setting score to zero
    int i = 0;
    while (i < 6) // iterate 6 times 
    {
        int random = (rand() % 6) + 1;
        int answer;
        printf("Guess number on the dice (1-6) : ");
        scanf("%d", &answer);
        printf("\n");
        printDice(random);
        printf("\n");

        if (answer == random) //checks for correct answer 
        {
            printf("Woohoo.. got it correct : +1 points\n\n");
            score += 1;
        }
        else
        {
            printf("Oh No.. got it wrong : 0 points\n\n");
        }

        i++;
    }

    //shows result
    printf("-----------------------------\nTotal Score : %d\n", score);
    if (score >= 4)
    {
        printf("Hurray!! You won the game..Congrats\n");
    }
    else
    {
        printf("Sorry! You lost the game...\n");
    }
}

void loadMillionaire()
{
    int i = 0;
    int lifeline = 1;
    int set_lifeline = 0 ;
    while (i < 10) // iterates through 10 levels
    {
        printf("%s\n", arr[i].q);
        if(set_lifeline==0){
            printf("1. %s\t 2. %s\n3. %s\t 4. %s\n", arr[i].a, arr[i].b, arr[i].c, arr[i].d);
            printf("Choose option (1-4) ");
        }
        else{ // if lifeline is used
            int index = arr[i].correct ;
            if(index==1){
                printf("1. %s\n2. %s\n", arr[i].a, arr[i].b);
                printf("Choose option ");
            }
            if (index == 2)
            {
                printf("2. %s\n4. %s\n", arr[i].b, arr[i].d);
                printf("Choose option ");
            }
            if (index == 3)
            {
                printf("2. %s\n3. %s\n", arr[i].b, arr[i].c);
                printf("Choose option ");
            }
            if (index == 4)
            {
                printf("1. %s\n4. %s\n", arr[i].a, arr[i].d);
                printf("Choose option ");
            }
            set_lifeline = 0; //clears lifeline option
        }
        if(lifeline>0){
            printf("or 5 to use lifeline ");
        }
        printf(": ");
        int option;
        scanf("%d", &option);
        if (option >= 1 && option <= 4) //checks whether option is correct
        {
            if (option == arr[i].correct)
            {
                i++;
                if (i == 10)
                {
                    printf("\n\nCongrats! You have become millionaire!!!\n\n");
                    break;
                }
                else
                {
                    printf("Congrats! You have passed level %d\n\n", i);
                }
            }
            else
            {
                printf("Sorry! answer is wrong!\n\n");
                break;
            }
        }
        if(option==5){ 
            set_lifeline = 1 ; //sets lifeline
            lifeline--;
            continue;
        }
    }
}

int main()
{
    generateQuestions(); //generates Questions to globally declared array arr[10]
    srand(time(0)); 
    while (1)
    {
        printf("Welcome to Mini Games\nSelect Game: 1. Mini Dice 2. Who wants to be a millionaire? 3.Exit\n");
        int option;
        scanf("%d", &option);

        if (option == 1) //option 1 for dice
        {
            while (1)
            {
                loadDice();
                int c;
                printf("Enter your choice 1. Retry 2.Main Menu : ");
                scanf("%d", &c);
                if (c == 2)
                {
                    break;
                }
                else
                    continue;
            }
        }
        if (option == 2) //option 2 for millionaire
        {
            while (1)
            {
                loadMillionaire();
                int c;
                printf("Enter your choice 1. Retry 2.Main Menu : ");
                scanf("%d", &c);
                if (c == 2)
                {
                    break;
                }
                else
                    continue;
            }
        }
        if (option == 3) //option 3 exits the program
        {
            break;
        }
    }

    return 0;
}