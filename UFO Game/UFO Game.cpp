// UFO Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "ufo_functions.h"

void end_game(std::string answer, std::string codeword);
void display_status(std::vector<char> incorrect, std::string answer);

int main() {
    ufo_functions test;
    test.greet();
    std::string codeword = "codecademy";
    std::string answer = "__________";
    int misses = 0;
    std::vector<char> incorrect;
    bool guess = false;
    char letter;
    while (answer != codeword && misses < 7)
    {
        test.display_misses(misses);
        display_status(incorrect, answer);
        std::cout << "\nPlease enter your guess: ";
        std::cin >> letter;
        for (size_t i = 0; i < codeword.size(); i++)
        {
            if (letter == codeword[i])
            {
                answer[i] = letter;
                guess = true;
            }
        }
        if (guess == true)
        {
            std::cout << "Correct!\n";
        }
        else
        {
            std::cout << "Incorrect! The tractor beam pulls the person in further.\n";
            incorrect.push_back(letter);
            misses++;
        }
        guess = false;
    }
    end_game(answer, codeword);
    system("pause");
}

void end_game(std::string answer, std::string codeword)
{
    if (answer == codeword)
    {
        std::cout << "Horray! You saved the person and earned a medal of honor!\n";
    }
    else
    {
        std::cout << "Oh no! The UFO just flew away with another person!\n";
    }
}

void display_status(std::vector<char> incorrect, std::string answer)
{
    std::cout << "Incorrect Guesses: ";
    for (size_t i = 0; i < incorrect.size(); i++)
    {
        std::cout << incorrect[i] << " ";
    }
    std::cout << "\nCodeword: ";
    for (size_t i = 0; i < answer.size(); i++)
    {
        std::cout << answer[i] << " ";
    }
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
