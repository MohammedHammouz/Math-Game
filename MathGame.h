#pragma once


#include <iostream>
#include <cstdlib> // For system() and rand()
#include <ctime>   // For seeding random numbers

namespace MathGame
{
	int RandomNumber(int from, int to) {
		std::srand(static_cast<unsigned>(std::time(nullptr)));
		return rand() % (to - from + 1) + from;
	}
	void Reset() {
		system("cls");
		system("color 0F");
	}
	void ShowQuizEndScreen() {
		std::cout << "__________+++++[QuizEnd]+++++______________\n";
		std::cout << "_____________________________________________\n";
	}

}