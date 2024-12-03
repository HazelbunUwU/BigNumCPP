#include <iostream>
#include <cmath>
#include <sstream>
#include <list>
#include <iterator>
#include <limits.h>
#include <math.h>
using namespace std;

class CarriableInt 
{

public:

	static const unsigned long long int MaxValue = 10000000000000000000;	//10^19 for maximum utilisation of the 64 bit int whilst keeping it base 10 friendly
	unsigned long long int Number;
	char Carry;																//Carry char can range from 0 -> 9
	unsigned long long int _SpecialCaseCarry_;								//Unsigned long long int for special case carries where more than char is required

	CarriableInt(unsigned long long int InputNumber=0, char CarryInput = 0, unsigned long long int __Carry__ = 0){

		Number = InputNumber % MaxValue;
		Carry = CarryInput;
		_SpecialCaseCarry_ = __Carry__;

	};

	CarriableInt operator + (CarriableInt const& obj){

		unsigned long long int TemporaryMantissa = Number + obj.Number + Carry;
		char TemporaryCarry = 0;

		if (TemporaryMantissa > MaxValue) {

			TemporaryCarry = TemporaryMantissa - (TemporaryMantissa % MaxValue);
			TemporaryMantissa = TemporaryMantissa % MaxValue;

		}

		return CarriableInt(TemporaryMantissa, TemporaryCarry);

	};

	CarriableInt operator - (CarriableInt const& obj){

		unsigned long long int TensComplementObj = MaxValue - obj.Number;
		char TemporaryCarry = 10-Carry;

		unsigned long long TemporaryMantissa = Number + TensComplementObj + TemporaryCarry;

		if (TemporaryMantissa > MaxValue) {

			TemporaryCarry = TemporaryMantissa - (TemporaryMantissa % MaxValue);
			TemporaryMantissa = TemporaryMantissa % MaxValue;

		}

		return CarriableInt(TemporaryMantissa, TemporaryCarry);

	};

	CarriableInt operator >> (CarriableInt const& obj){

		unsigned long long int TemporaryMantissa = Number >> obj.Number;
		unsigned long long int SpecialCaseCarry = Number << (19-obj.Number);

		return CarriableInt(TemporaryMantissa, 0, SpecialCaseCarry);

	};

	CarriableInt operator << (CarriableInt const& obj){

		unsigned long long int TemporaryMantissa = Number << obj.Number; 
		unsigned long long int SpecialCaseCarry = Number >> (19-obj.Number);

		return CarriableInt(TemporaryMantissa, 0, SpecialCaseCarry);

	};

};
