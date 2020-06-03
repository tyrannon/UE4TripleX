#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to the terminal

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n  /\\_/\\  (";
    std::cout << "\n ( ^.^ ) _)";
    std::cout << "\n   \\\"/  (";
    std::cout << "\n ( | | )";
    std::cout << "\n(__d b__)";

    std::cout << "\nCurrent Level Difficulty is: " << Difficulty;
    std::cout << "\nYou are an investor doing financial research on a company.\n";    
    std::cout << "You need to enter the correct codes into the bloomberg terminal to continue...\n\n";
}

bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);


    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;


    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;


    // User Input
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // Print Sum and Product of Guesses
    std::cout << "\nThe Sum of your Guesses is: " << GuessSum;
    std::cout << "\nThe Product of your Guesses is: " << GuessProduct;

    if (CodeSum == GuessSum)
    {
        std::cout << "\nYou Win!";
        return true;
    } 
    else 
    {
        std::cout << "\nYou Lose!";
        return false;
    }

}

int main()
{
    srand(time(NULL)); // create new random sequence based on time of day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if  (bLevelComplete)
        {
            // increase the level difficulty
            ++LevelDifficulty;
        }
    }

    std::cout << "\n*** Great work agent! You got all the  files! Now get out of there! ***\n";
    return 0;
}