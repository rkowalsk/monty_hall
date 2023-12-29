#include <iostream>
#include <time.h>
#include <stdlib.h>

int	get_new_door(int guess, const int answer)
{
	int	open_door = 1;
	int	possibilities = 1;

	// opening a door that isn't the correct answer
	while (open_door <= 3
		&& (open_door == guess || open_door == answer))
		open_door++;

	// changing door to one that is neither the open door
	// or the first guess
	while (possibilities <= 3
		&& (possibilities == guess || possibilities == open_door))
		possibilities++;
	return (possibilities);
}

int main(void)
{
	const int	nb_tries = 1000000;
	int			times_1 = 0;
	int			times_2 = 0;
	int			times_3 = 0;

	srand(time(NULL));

	std::cout << "Number of trials: " << nb_tries << std::endl;
	// Verif probabilities
	int	i = 0;
	int	number;
	while (i < nb_tries)
	{
		number = rand() % 3 + 1;
		if (number == 1)
			times_1++;
		else if (number == 2)
			times_2++;
		else if (number == 3)
			times_3++;
		i++;
	} 
	std::cout << "Checking probability of each door being the answer" << std::endl;
	std::cout << " door 1: " << times_1 * 100 / nb_tries << "%" << std::endl;
	std::cout << " door 2: " << times_2 * 100 / nb_tries << "%" << std::endl;
	std::cout << " door 3: " << times_3 * 100 / nb_tries << "%" << std::endl;

	// No changing door (control test)
	{
		int	j = 0;
		int	answer;
		int	guess;
		int	nb_good_guesses = 0;
		while (j < nb_tries)
		{
			answer = rand() % 3 + 1;
			guess = rand() % 3 + 1;
			if (answer == guess)
				nb_good_guesses++;
			j++;
		}
		std::cout << "Without changing door" << std::endl;
		std::cout << " Percentage of correct answers: ";
		std::cout << (nb_good_guesses * 100) / nb_tries << "%" << std::endl;
	}

	// Changing door
	{
		int	j = 0;
		int	answer;
		int	guess;
		int	nb_good_guesses = 0;
		while (j < nb_tries)
		{
			answer = rand() % 3 + 1;
			guess = rand() % 3 + 1;
			if (answer == get_new_door(guess, answer))
				nb_good_guesses++;
			j++;
		}
		std::cout << "With changing door" << std::endl;
		std::cout << " Percentage of correct answers: ";
		std::cout << (nb_good_guesses * 100) / nb_tries << "%" << std::endl;
	}
	return (0);
}
