#include <iostream>
#include <cstdint>
#include <bitset>
#include <limits>

void printValue(const std::string& title, uint8_t value)
{
    std::cout << title << std::endl;
    std::cout << "Binary : " << std::bitset<8>(value) << std::endl;
    std::cout << "Decimal: " << static_cast<int>(value) << std::endl;
}

int main()
{
    int input;
    uint8_t number;
    int bitPosition;

    // Read number (0–255)
    while (true) {
        std::cout << "Enter an integer (0 - 255): ";
        std::cin >> input;

        if (std::cin.fail() || input < 0 || input > 255) {
            std::cout << "Error: number must be in range 0 - 255.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            number = static_cast<uint8_t>(input);
            break;
        }
    }

    // Read bit position (0–7)
    while (true) {
        std::cout << "Enter a bit position (0 - 7): ";
        std::cin >> bitPosition;

        if (std::cin.fail() || bitPosition < 0 || bitPosition > 7) {
            std::cout << "Error: bit position must be in range 0 - 7.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }


	// Display binary 
	std::cout << "Binary: " << std::bitset<8>(number) << std::endl;

	// Count set bits
	int setBits = 0;
	for (int i = 0; i < 8; i++) {
		if ((number >> i) & 1) {
			setBits++;
		}
	}

	std::cout << "Number of bits set: " << setBits << std::endl;

	// Check selected bit 
	bool isSet = (number >> bitPosition) & 1;
	std::cout << "Bit " << bitPosition << " is set: "
		<< (isSet ? "true" : "false") << std::endl;
    
    // Set the nth bit
    uint8_t setBit = number | (1 << bitPosition);
    printValue("After setting bit:", setBit);

    //Clear the nth bit
    uint8_t clearBit = number & ~(1 << bitPosition);
    printValue("After clear bit: ", clearBit);

    //Invert the nth bit
    uint8_t invertBit = number ^ (1 << bitPosition);
    printValue("After invert bit: ", invertBit);

    //Left shift by th nth bit
    uint8_t leftBit = number << bitPosition;
    printValue("After left shift: ", leftBit);

    //Right shift by th nth bit
    uint8_t rightBit = number >> bitPosition;
    printValue("After right shift: ", rightBit);

	return 0;
}