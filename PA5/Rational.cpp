#include "Rational.h"

//rational class default contructor
Rational::Rational(){

}//Rational::Rational()

Rational::Rational(int num_m, int denom_m){
	num = num_m;
	denom = num_m;
}//Rational::Rational(int int)

Rational::Rational(int wholeNumber){
	num = wholeNumber;
	denom = 1;
}//Rational::Rational(int)

Rational::Rational(const Rational &a){

}//Rational::Rational(Rational)

Rational operator+(const Rational& val) {
	Rational addedVal;
	
	//addedVal.setValue();

	return addedVal;
}//Rational::operator+



