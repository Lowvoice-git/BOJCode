#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> Dice;
int main() {
	long long n;
	int Shortest_Dice_number2 = 2501, Shortest_Dice_number3 = 2501;
	long long number1, number2, number3 = 4;
	long long result = 0;
	std::cin >> n;
	for (int num = 0; num < 6; num++) {
		int temp; std::cin >> temp;
		Dice.push_back(temp);
	}
	if (n == 1) {
		std::sort(Dice.begin(), Dice.end());
		for (int num = 0; num < 5; num++) result += Dice[num];
	}
	else {
		for (int num1 = 0; num1 < 6; num1++)
			for (int num2 = num1 + 1; num2 < 6; num2++)
				if (5 - num1 != num2)
					Shortest_Dice_number2 = std::min(Shortest_Dice_number2, Dice[num1] + Dice[num2]);
		for (int num1 = 0; num1 < 6; num1++)
			for (int num2 = num1 + 1; num2 < 6; num2++)
				for (int num3 = num2 + 1; num3 < 6; num3++)
					if (5 - num1 != num2 && 5 - num1 != num3 && 5 - num2 != num3)
						Shortest_Dice_number3 = std::min(Shortest_Dice_number3, Dice[num1] + Dice[num2] + Dice[num3]);
		std::sort(Dice.begin(), Dice.end());
		number2 = ((n - 2) + (n - 1)) * 4; number1 = (n * n * 5) - number2 * 2 - number3 * 3;
		result += (Dice[0] * number1);
		result += (Shortest_Dice_number2 * number2);
		result += (Shortest_Dice_number3 * number3);
	}
	std::cout << result;
}