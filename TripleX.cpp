#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Print welcome message to the terminal
    std::cout << " \n ___________________" << std::endl;
    std::cout << " | _______________ |" << std::endl;
    std::cout << " | |XXXXXXXXXXXXX| |" << std::endl;
    std::cout << " | |XXXXX " << Difficulty << " XXXXX| | " << std::endl;
    std::cout << " | |XXXXXXXXXXXXX| |" << std::endl;
    std::cout << " | |XXXXXXXXXXXXX| |" << std::endl;
    std::cout << " |_________________|" << std::endl;
    std::cout << "     _[_______]_" << std::endl;
    std::cout << " ___[___________]___" << std::endl;
    std::cout << "|         [_____]   |" << std::endl;
    std::cout << "|         [_____] []|" << std::endl;
    std::cout << "L___________________J" << std::endl;
    std::cout << " ___________________" << std::endl;
    std::cout << "/###################\\" << std::endl;
    std::cout << "\nYou are Bob the Chef you come to work as usual.\n";
    std::cout << "You want to open fridge but you seed the lock on the fridge handle.\n";
    std::cout << "On the lock there is a monitor with the text.\n";
    std::cout << "You need to enter the correct code to get acces to the products.\n";
    std::cout << "Or you will be replaced by robot worker who are smart and can count product right.\n";
    std::cout << "Please enter the correct code...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The code add-up to: " << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You completed Level " << Difficulty << std::endl
                  << std::endl
                  << std::endl;
        std::cout << "\n***************************************************************************************";
        return true;
    }
    else
    {
        std::cout << "Try againn\n\n\n";
        std::cout << "\n***************************************************************************************";
        return false;
    }
}

const int main()
{

    srand(time(NULL)); // Creats new random sequance based on the time of the day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game untill all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        // Clears any errors
        std::cin.clear();
        // Discards the buffer
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "\nYOU WON A GAME";
    return 0;
}