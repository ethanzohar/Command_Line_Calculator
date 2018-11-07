#include <iostream>
#include <string>
#include <cmath>

int main();

void interval_calculator();

std::string userInput;

int main() {
	interval_calculator();
	return 0;
}

void interval_calculator() {
	double num{ 0 };
	double num2{ 0 };

	double temp1{ 0 };
	double temp2{ 0 };
	double temp3{ 0 };
	double temp4{ 0 };

	double max{ 0 };
	double min{ 0 };

	double startInterval{ 0 };
	double endInterval{ 0 };
	double savedStartInterval{ 0 };
	double savedEndInterval{ 0 };
	double temp{ 0 };

	bool enteredInterval{ false };
	bool enteredSavedInterval{ false };

	while (userInput != "exit") {
		std::cout << "input :> ";
		std::cin >> userInput;
		if (userInput == "enter") {
			std::cin >> num >> num2;

			if (num > num2) {
				std::cout << "Error: invalid interval as " << num << " > " << num2 << std::endl;
				std::cout << "--" << std::endl;
			}
			else {
				startInterval = num;
				endInterval = num2;

				std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;

				enteredInterval = true;
			}
		}
		else if (userInput == "negate") {
			if (enteredInterval) {
				temp = startInterval;

				startInterval = -endInterval;
				endInterval = -temp;

				std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
			}
			else {
				std::cout << "--" << std::endl;
			}
		}
		else if (userInput == "invert") {
			if (enteredInterval) {
				if (startInterval <= 0 && endInterval >= 0) {
					std::cout << "Error: division by zero" << std::endl;
					std::cout << "--" << std::endl;
					enteredInterval = false;
				}
				else {
					temp = startInterval;

					startInterval = 1 / endInterval;
					endInterval = 1 / temp;

					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
			}
			else {
				std::cout << "--" << std::endl;
			}
		}
		else if (userInput == "ms") {
			if (enteredInterval) {
				savedStartInterval = startInterval;
				savedEndInterval = endInterval;
				enteredSavedInterval = true;

				std::cout << "[" << savedStartInterval << ", " << savedEndInterval << "]" << std::endl;
			}
			else {
				std::cout << "--" << std::endl;
			}
		}
		else if (userInput == "mr") {
			if (enteredSavedInterval) {
				startInterval = savedStartInterval;
				endInterval = savedEndInterval;

				std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
			}
			else {
				if (enteredInterval) {
					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
		}
		else if (userInput == "mc") {
			if (enteredSavedInterval) {
				savedStartInterval = 0;
				savedEndInterval = 0;

				std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;

				enteredSavedInterval = false;
			}
			else {
				if (enteredInterval) {
					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
		}
		else if (userInput == "m+") {
			if (enteredSavedInterval && enteredInterval) {
				savedStartInterval += startInterval;
				savedEndInterval += endInterval;

				std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
			}
			else {
				if (enteredInterval) {
					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
		}
		else if (userInput == "m-") {
			if (enteredSavedInterval && enteredInterval) {
				savedStartInterval -= startInterval;
				savedEndInterval -= endInterval;

				std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
			}
			else {
				std::cout << "--" << std::endl;
			}
		}
		else if (userInput == "scalar_add") {
			std::cin >> num;
			if (enteredInterval) {

				startInterval += num;
				endInterval += num;

				std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
			}
			else {
				std::cout << "--" << std::endl;
			}
		}
		else if (userInput == "scalar_subtract") {
			std::cin >> num;
			if (enteredInterval) {

				startInterval -= num;
				endInterval -= num;

				std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
			}
			else {
				std::cout << "--" << std::endl;
			}
		}
		else if (userInput == "scalar_multiply") {
			std::cin >> num;
			if (enteredInterval) {

				if (num >= 0) {
					startInterval *= num;
					endInterval *= num;
				}
				else {
					temp = startInterval;
					startInterval = endInterval * num;
					endInterval = temp * num;
				}

				std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
			}
			else {
				std::cout << "--" << std::endl;
			}
		}
		else if (userInput == "scalar_divide") {
			std::cin >> num;
			if (enteredInterval) {
				if (num > 0) {
					startInterval /= num;
					endInterval /= num;

					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else if (num < 0) {
					temp = startInterval;
					startInterval = endInterval / num;
					endInterval = temp / num;

					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "Error: division by zero" << std::endl;
					std::cout << "--" << std::endl;
					enteredInterval = false;
				}
			}
			else {
				std::cout << "--" << std::endl;
			}
		}
		else if (userInput == "scalar_divided_by") {
			std::cin >> num;
			if (enteredInterval) {
				if (startInterval <= 0 && endInterval >= 0) {
					std::cout << "Error: division by zero" << std::endl;
					std::cout << "--" << std::endl;
					enteredInterval = false;
				}
				else {
					if (num > 0) {
						startInterval /= num;
						endInterval /= num;
						std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
					}
					else if (num < 0) {
						temp = startInterval;
						startInterval = num / endInterval;
						endInterval = num / temp;
						std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
					}
					else {
						std::cout << "Error: division by zero";
						std::cout << "--" << std::endl;
						enteredInterval = false;
					}
				}
			}
			else {
				std::cout << "--" << std::endl;
			}
		}
		else if (userInput == "interval_add") {
			std::cin >> num >> num2;

			if (num > num2) {
				std::cout << "Error: invalid interval as " << num << " > " << num2 << std::endl;
				if (enteredInterval) {
					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
			else {
				if (enteredInterval) {
					startInterval += num;
					endInterval += num2;

					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
		}
		else if (userInput == "interval_subtract") {
			std::cin >> num >> num2;

			if (num > num2) {
				std::cout << "Error: invalid interval as " << num << " > " << num2 << std::endl;
				if (enteredInterval) {
					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
			else {
				if (enteredInterval) {
					startInterval -= num2;
					endInterval -= num;

					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
		}
		else if (userInput == "interval_multiply") {
			std::cin >> num >> num2;

			if (num > num2) {
				std::cout << "Error: invalid interval as " << num << " > " << num2 << std::endl;
				if (enteredInterval) {
					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
			else {
				if (enteredInterval) {
					temp1 = startInterval * num;
					temp2 = startInterval * num2;
					temp3 = endInterval * num;
					temp4 = endInterval * num2;

					if (temp1 >= temp2) {
						max = temp1;
						min = temp2;
					}
					else {
						max = temp2;
						min = temp1;
					}

					if (temp3 > max && temp3 > temp4) {
						max = temp3;
					}
					else if (temp4 > max) {
						max = temp4;
					}

					if (temp3 < min && temp3 < temp4) {
						min = temp3;
					}
					else if (temp4 < min) {
						min = temp4;
					}

					startInterval = min;
					endInterval = max;

					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
		}
		else if (userInput == "interval_divide") {
			std::cin >> num >> num2;

			if (num > num2) {
				std::cout << "Error: invalid interval as " << num << " > " << num2 << std::endl;
				if (enteredInterval) {
					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
			else if (num <= 0 && num2 >= 0) {
				std::cout << "Error: division by zero" << std::endl;
				std::cout << "--" << std::endl;
				enteredInterval = false;
			}
			else {
				if (enteredInterval) {
					temp1 = startInterval / num;
					temp2 = startInterval / num2;
					temp3 = endInterval / num;
					temp4 = endInterval / num2;

					if (temp1 >= temp2) {
						max = temp1;
						min = temp2;
					}
					else {
						max = temp2;
						min = temp1;
					}

					if (temp3 > max) {
						max = temp3;
					}
					else if (temp4 > max) {
						max = temp4;
					}
					if (temp3 < min) {
						min = temp3;
					}
					else if (temp4 < min) {
						min = temp4;
					}

					startInterval = min;
					endInterval = max;

					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
		}
		else if (userInput == "intersect") {
			std::cin >> num >> num2;

			if (num > num2) {
				std::cout << "Error: invalid interval as " << num << " > " << num2 << std::endl;
				if (enteredInterval) {
					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
			else {
				if (enteredInterval) {
					if (num <= startInterval && num2 >= endInterval) {
						std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
					}
					else if (num >= startInterval && num <= endInterval && num2 >= endInterval) {
						startInterval = num;
						std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
					}
					else if (num <= startInterval && num2 <= endInterval && num2 >= startInterval) {
						endInterval = num2;
						std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
					}
					else if (num >= startInterval && num2 <= endInterval) {
						startInterval = num;
						endInterval = num2;
						std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
					}
					else {
						enteredInterval = false;
						std::cout << "--" << std::endl;
					}
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
		}
		else if (userInput == "integers") {
			if (enteredInterval) {
				for (double i{ std::ceil(startInterval) }; i <= std::floor(endInterval); i++) {
					if (i == std::floor(endInterval)) {
						std::cout << i << std::endl;
					}
					else {
						std::cout << i << ", ";
					}
				}
				std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
			}
			else {
				std::cout << "--" << std::endl;
			}
		}
		else if (userInput == "cartesian_integers") {
			std::cin >> num >> num2;

			if (num > num2) {
				std::cout << "Error: invalid interval as " << num << " > " << num2 << std::endl;
				if (enteredInterval) {
					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
			else {
				if (enteredInterval) {
					for (double i{ std::ceil(startInterval) }; i <= std::floor(endInterval); i++) {
						for (double j{ std::ceil(num) }; j <= std::floor(num2); j++) {
							if (i == std::floor(endInterval) && j == std::floor(num2)) {
								std::cout << "(" << i << "," << j << ")" << std::endl;
							}
							else {
								std::cout << "(" << i << "," << j << "), ";
							}
						}
					}
					std::cout << "[" << startInterval << ", " << endInterval << "]" << std::endl;
				}
				else {
					std::cout << "--" << std::endl;
				}
			}
		}
		else if (userInput == "clear") {
			enteredInterval = false;
			enteredSavedInterval = false;
		}
		else if (userInput != "exit") {
			std::cout << "Error: invalid command" << std::endl;
		}
	}
	std::cout << "Bye bye: Terminating interval calculator program.";
}
