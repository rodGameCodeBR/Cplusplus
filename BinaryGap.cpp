
// BinaryGap.cpp : Defines the entry point for the console application.
// Rodrigo dos Reis


#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int BinaryGap(long n);

const long MIN = 1;
const long MAX = 2147483647;

int main()
{
	cout << "BinaryGap of " << BinaryGap(1538) << endl;

	cin.get();
	return 0;
}

int BinaryGap(long quotient)
{
	string remaining;
	int lastBinaryGap = 0, currentBinaryGap = 0;

	// if quotient is within Min and Max...
	if (quotient >= MIN && quotient <= MAX)
	{
		cout << "Binary Gap of " << quotient << endl;

		// convert long to binary by dividing it until reachs zero
		do
		{
			if (quotient % 2 == 0)
			{
				remaining += "0";

				currentBinaryGap++;

				// keep the greater binary gap found
				if (currentBinaryGap > lastBinaryGap)
					lastBinaryGap = currentBinaryGap;
			}
			else
			{
				remaining += "1";

				currentBinaryGap = 0;
			}

			// keep dividing the quotient until 0

			quotient /= 2;

		} while (quotient > 0);

		// reverse the string
		std::reverse(remaining.begin(), remaining.end());

		// convert string to int
		cout << "Binary: " << stoi(remaining, nullptr, 10) << endl;
	}
	else
		return 0;

	return lastBinaryGap;
}
