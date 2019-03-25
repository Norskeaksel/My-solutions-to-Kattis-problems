#include <iostream>
#include <string>
int main() {
	std::string str;
	std::cin >> str;
	int svar = 1;
	for (std::string::size_type i = 0; i < str.size(); ++i) {
		switch (svar) {
		case 1:
			switch (str[i]) {
			case 'A':
				svar = 2;
				break;
			case 'B':
				svar = 1;
				break;
			case 'C':
				svar = 3;
				break;

			}
			break;
		case 2:
			switch (str[i]) {
			case 'A':
				svar = 1;
				break;
			case 'B':
				svar = 3;
				break;
			case 'C':
				svar = 2;
				break;

			}
			break;
		case 3:
			switch (str[i]) {
			case 'A':
				svar = 3;
				break;
			case 'B':
				svar = 2;
				break;
			case 'C':
				svar = 1;
				break;
			}
			break;

		}
	}
	std::cout<< svar;
}