/*cppmath.h is available to be used in any way except for for commercial purposes*/

//cppmath.h is compatible for C++ files but NOT C files
//cppmath.h has a developed C++ replacement for the JS Math object
//It adds many functions such as nPr, nCr, factorial, floor, ceiling, round, fibonacci, HCF, rand, LCM/GCD, factor(algebraic), changeBase, isPrime and isComposite.
//It also includes popular function groups such as the trigonometric functions, statistical functions, geometrical functions and figurate functions
//The Math library includes all of the methods and constants that is included in the JS Math object such as min, max, abs, pow, exp, rand, log and PI
//The sorting library is included with this. Reference this by using the Sort object, like 'Sort.quickSort(array)'. This includes many sorts such as
//insertion sort, selection sort, bubble sort, shell sort, quick sort, int sort, merge sort and heap sort
//Time measurements are using Intel Core i7

#ifndef MYMATH_H_INCLUDED
    #define MYMATH_H_INCLUDED
#endif // MYMATH_H_INCLUDED
#ifndef _GLIBCXX_CMATH
    #include <cmath>
#endif // _GLIBCXX_CMATH
#ifndef _GLIBCXX_CSTDLIB
    #include <cstdlib>
#endif //_GLIBCXX_CSTDLIB
#ifndef _GLIBCXX_CTIME
    #include <ctime>
#endif //_GLIBCXX_CTIME
#ifndef _GLIBCXX_STRING
    #include <string>
#endif // _GLIBCXX_STRING
#ifndef _GLIBCXX_SSTREAM
    #include <sstream>
#endif // _GLIBCXX_SSTREAM
#ifndef _GLIBCXX_VECTOR
    #include <vector>
#endif // _GLIBCXX_VECTOR
#include "sort.h"
using namespace std;

class myMath {
    public:
        const double PI = 3.141592653589793;
        const double E = 2.718281828459045;
        const double LN2 = 0.6931471805599453;
        const double LN10 = 2.302585092994046;
        const double LOG2E = 1.4426950408889634;
        const double LOG10E = 0.4342944819032518;
        const double SQRT1_2 = 0.7071067811865476;
        const double SQRT2 = 1.4142135623730951;
        const double GOLDEN_RATIO = 1.61803398875;
        //Find the absolute value of a value
        //15ms for Math.abs(-8.566978546675879567435637865756547646)
        double abs(double value) {
            if (value >= 0) {
                return value;
            } else {
                return value * -1;
            }
        }
        int abs(int value) {
            if (value >= 0) {
                return value;
            } else {
                return value * -1;
            }
        }
        //Find the factorial of a number i.e. '5!' = 120
        //17ms for Math.factorial(30)
        int factorial(int value) {
            if (value > 31) {
                cerr << "From function factorial(int): The value you entered was too large.\n";
                return 0;
            } else if (value < 0) {
                return value;
            } else if (value == 0 || value == 1) {
                return 1;
            } else {
                int result = 1;
                for (int i = 2; i <= value; i++) {
                    result *= i;
                }
                return result;
            }
        }
        //Find the floor of a value
        //16ms for floor(34.83)
        int floor(double value) {
            return (int)value;
        }
        //Find the ceiling of a value
        //17ms for ceiling(34.83)
        int ceiling(double value) {
            double mod = value - (int)value;
            if (mod > 0) {
                return (int)value + 1;
            } else {
                return value;
            }
        }
        int ceil(double value) {
            double mod = value - (int)value;
            if (mod > 0) {
                return (int)value + 1;
            } else {
                return value;
            }
        }
        //Round a value to the nearest integer
        //18ms for round(34.83)
        int round(double value) {
            double mod = value - (int)value;
            if (mod >= 0.5) {
                return (int)value + 1;
            } else {
                return (int)value;
            }
        }
        //Finds a value to the power of a given power
        //16ms for pow(34, 6)
        int pow(int value, int power) {
            int result = 1;
            for (int i = 1; i <= power; i++) {
                result *= value;
            }
            return result;
        }
        double pow(double value, int power) {
            double result = 1.0;
            for (int i = 1; i <= power; i++) {
                result *= value;
            }
            return result;
        }
        double pow(int value, double power) {
            return std::pow(value, power);
        }
        double pow(double value, double power) {
            return std::pow(value, power);
        }
        //Squares a given value (value to the power of two)
        double square(double value) {
            return value * value;
        }
        //Cubes a given value (value to the power of three)
        double cube(double value) {
            return value * value * value;
        }
        //Triangles a number
        double triangle(double value) {
            return (value + 1) * (value/2);
        }
        double slowTriangle(double value) {
            return this->square(value)/2 + value/2;
        }
        //Finds minimum of 2 values
        int min(int val1, int val2) {
            if (val1 > val2) {
                return val2;
            } else {
                return val1;
            }
        }
        double min(double val1, double val2) {
            if (val1 > val2) {
                return val2;
            } else {
                return val1;
            }
        }
        double min(int val1, double val2) {
            if (val1 > val2) {
                return val2;
            } else {
                return val1;
            }
        }
        double min(double val1, int val2) {
            if (val1 > val2) {
                return val2;
            } else {
                return val1;
            }
        }
        //Finds maximum of 2 values
        int max(int val1, int val2) {
            if (val1 < val2) {
                return val2;
            } else {
                return val1;
            }
        }
        double max(double val1, double val2) {
            if (val1 < val2) {
                return val2;
            } else {
                return val1;
            }
        }
        double max(int val1, double val2) {
            if (val1 < val2) {
                return val2;
            } else {
                return val1;
            }
        }
        double max(double val1, int val2) {
            if (val1 < val2) {
                return val2;
            } else {
                return val1;
            }
        }
        //Finds the nth root of a value
        double NthRoot(double value, double n) {
            return this->pow(value, 1.0/n);
        };
        //Returns square root
        double sqrt(double value) {
            return this->NthRoot(value, 2);
        }
        //Returns cube root
        double cbrt(double value) {
            return this->NthRoot(value, 3);
        }
        //Finds E(Euler's number) to the power of x
        double exp(double x) {
            return this->pow(this->E, x);
        }
        //Gets a random number between min and max
        double rand(double min, double max) {
            time_t seconds;
            time(&seconds);
            srand((unsigned int) seconds);
            return std::rand() % ((int)max - (int)min + 1) + min;
        }
        //Gets a full number random
        double fullRand(double min, double max) {
            time_t seconds;
            time(&seconds);
            srand((unsigned int) seconds);
            return std::rand() % ((int)max - (int)min + 1) + (int)min;
        }
        //Standard JavaScript Math object functions that I couldn't be bothered to code
        double log(double x) {
            return std::log(x);
        }
        double acos(double x) {
            return std::acos(x);
        }
        double asin(double x) {
            return std::asin(x);
        }
        double atan(double x) {
            return std::atan(x);
        }
        double atan2(double y, double x) {
            return std::atan2(y, x);
        }
        double cos(double x) {
            return std::cos(x);
        }
        double cosh(double x) {
            return std::cosh(x);
        }
        double sin(double x) {
            return std::sin(x);
        }
        double sinh(double x) {
            return std::sinh(x);
        }
        double tan(double x) {
            return std::tan(x);
        }
        double tanh(double x) {
            return std::tanh(x);
        }
        //Returns a fibonacci number of the index specified. The sequence starts with 0,1,1,2,3,5,8,13,21.
        //Warning: fib(0) = 0, fib(1) = 1, fib(39) = 63245986
        int fibonacci(int index) {
            int seq[index];
            if (index < 3) {
                if (index > 0) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                seq[0] = 0;
                seq[1] = 1;
                for (int i = 2; i <= index; i++) {
                    seq[i] = seq[i - 1] + seq[i - 2];
                }
                return seq[index];
            }
        }
        //Will return the Fibonacci sequence up to and including the index specified
        string fibonacciString(int index) {
            int seq[index];
            if (index < 1) {
                return "0";
            } else if (index == 1) {
                return "1";
            } else {
                seq[0] = 0;
                seq[1] = 1;
                for (int i = 2; i <= index; i++) {
                    seq[i] = seq[i - 1] + seq[i - 2];
                }
                string result = "0,1";
                for (int j = 2; j <= index; j++) {
                    result += ",";
                    result += static_cast<ostringstream*>( &(ostringstream() << seq[j]) )->str();
                }
                return result;
            }
        }
        //Calculates the circlumference of a circle when a radius is given
        double circleCircumference(double radius) {
            return radius * this->PI * 2;
        }
        //Calculates the area of a circle that has a given radius
        double circleArea(double radius) {
            return this->square(radius) * this->PI;
        }
        //Calculates the area of a cylinder given the radius of its base and its height
        double cylinderArea(double radius, double height) {
            return (circleArea(radius) * height);
        }
        //Calculates the area of a cone given the radius of its base and its height
        double coneArea(double radius, double height) {
            return cylinderArea(radius, height)/3;
        }
        //Calculates the area of a sphere given the radius of its base circle
        double sphereArea(double radius) {
            return circleArea(radius) * radius * 4 / 3;
        }
        //Calculates the area of any rectangular prism
        double prism(double width, double length, double height) {
            return width * height * length;
        }
        //Calculates the area of a square pyramid given its height width and length
        double SqPyramidArea(double width, double length, double height) {
            return prism(width, length, height)/3;
        }
        //Calculates the hypotenuse of a right angle triangle given the two other sides
        double hypotenuse(double side1, double side2) {
            return this->sqrt(this->square(side1) + this->square(side2));
        }
        //Finds the side in a right angle triangle given the other side and hypotenuse
        double rightAngleTriSide(double side, double hypotenuse) {
            return this->sqrt(this->square(hypotenuse) - this->square(side));
        }
        //Finds the number of degrees in a number of radians
        double toDegrees(double radians) {
            return radians * (180/this->PI);
        }
        //Finds the number of radians in a number of degrees
        double toRadians(double degrees) {
            return degrees * (this->PI/180);
        }
        //Finds the mean of given values
        double mean(double num1, double num2) {
            return (num1 + num2)/2;
        }
        double mean(double num1, double num2, double num3) {
            return (num1 + num2 + num3)/3;
        }
        double mean(double num1, double num2, double num3, double num4) {
            return (num1 + num2 + num3 + num4)/4;
        }
        double mean(double num1, double num2, double num3, double num4, double num5) {
            return (num1 + num2 + num3 + num4 + num5)/5;
        }
        double mean(double num1, double num2, double num3, double num4, double num5, double num6) {
            return (num1 + num2 + num3 + num4 + num5 + num6)/6;
        }
        //Finds the median of a number of values
        double median(double num1, double num2) {
            return this->mean(num1, num2);
        }
        double median(double num1, double num2, double num3) {
            if ((num2 > num1 && num2 < num3) || (num2 < num1 && num2 > num3)) {
                return num2;
            } else if ((num3 > num1 && num3 < num2) || (num3 < num1 && num3 > num2)) {
                return num3;
            } else if ((num1 > num2 && num1 < num3) || (num1 < num2 && num1 > num3)) {
                return num1;
            }
        }
        //Finds the mode, or most recurring value
        double mode(double num1, double num2, double num3) {
            if (num1 == num2) {
                return num2;
            } else if (num2 == num3) {
                return num3;
            } else if (num3 == num1) {
                return num1;
            } else {
                return 0;
            }
        }
        //Finds the HCF, GCD and GCF (which are the same thing)
        double gcd(double num1, double num2) {
            int num1then = num1;
            while(num1 != num2) {
                num1then = num1;
                num1 = this->abs(num1 - num2);
                num2 = this->min(num1then, num2);
            }
            return num1;
        }
        double hcf(double num1, double num2) {
            return this->gcd(num1, num2);
        }
        double gcf(double num1, double num2) {
            return this->gcd(num1, num2);
        }
        //Finds the lcm
        double lcm(int num1, int num2) {
            int num1t = num1;
            if (this->min(num1, num2) == num1) {
                num1 = num2;
                num2 = num1t;
                num1t = num1;
            }
            while (num1t % num2 != 0) {
                num1t += num1;
            }
            return num1t;
        }
        //Finds whether a value is odd or even
        bool isEven(int value) {
            if (value % 2 == 0) {
                return true;
            } else {
                return false;
            }
        }
        bool isOdd(int value) {
            if (value % 2 == 0) {
                return false;
            } else {
                return true;
            }
        }
        //The following functions find whether a value is prime or composite
        string isPrimeString(int n1) {
            if (n1 < 0) {
				return "false";
			} else if (n1 == 1) {
				return "false";
			} else if (n1 == 0) {
				return "false";
			} else if (n1 == 2 || n1 == 3 || n1 == 5 || n1 == 7) {
				return "true";
			} else if (((n1 % 6 != 1)&&(n1 % 6 != 5))||(n1 % 5 == 0) || (n1 % 7 == 0)) {
				return "false";
			} else {
				for (int i = 11; i <= this->floor(this->sqrt(n1)); i++) {
					if (n1 % i != 0 && (i == this->floor(this->sqrt(n1)) || i == this->floor(this->sqrt(n1))-1)) {
						return "true";
					} else if (n1 % i == 0) {
					    return "false";
					}
				}
			}
        }
        bool isPrimeBool(int n1) {
            if (n1 < 0) {
				return false;
			} else if (n1 == 1) {
				return false;
			} else if (n1 == 0) {
				return false;
			} else if (n1 == 2 || n1 == 3 || n1 == 5 || n1 == 7) {
				return true;
			} else if (((n1 % 6 != 1)&&(n1 % 6 != 5))||(n1 % 5 == 0) || (n1 % 7 == 0)) {
				return false;
			} else {
				for (int i = 11; i <= this->floor(this->sqrt(n1)); i++) {
					if (n1 % i != 0 && (i == this->floor(this->sqrt(n1)) || i == this->floor(this->sqrt(n1))-1)) {
						return true;
					} else if (n1 % i == 0) {
					    return false;
					}
				}
			}
        }
        string isCompositeString(int n1) {
            if (n1 < 0) {
				return "false";
			} else if (n1 == 1) {
				return "false";
			} else if (n1 == 0) {
				return "true";
			} else if (n1 == 2 || n1 == 3 || n1 == 5 || n1 == 7) {
				return "false";
			} else if (((n1 % 6 != 1)&&(n1 % 6 != 5))||(n1 % 5 == 0) || (n1 % 7 == 0)) {
				return "true";
			} else {
				for (int i = 11; i <= this->floor(this->sqrt(n1)); i++) {
					if (n1 % i != 0 && (i == this->floor(this->sqrt(n1)) || i == this->floor(this->sqrt(n1))-1)) {
						return "false";
					} else if (n1 % i == 0) {
					    return "true";
					}
				}
			}
        }
        bool isCompositeBool(int n1) {
             if (n1 < 0) {
				return false;
			} else if (n1 == 1) {
				return false;
			} else if (n1 == 0) {
				return true;
			} else if (n1 == 2 || n1 == 3 || n1 == 5 || n1 == 7) {
				return false;
			} else if (((n1 % 6 != 1)&&(n1 % 6 != 5))||(n1 % 5 == 0) || (n1 % 7 == 0)) {
				return true;
			} else {
				for (int i = 11; i <= this->floor(this->sqrt(n1)); i++) {
					if (n1 % i != 0 && (i == this->floor(this->sqrt(n1)) || i == this->floor(this->sqrt(n1))-1)) {
						return false;
					} else if (n1 % i == 0) {
					    return true;
					}
				}
			}
        }
        string primeOrComposite(int n1) {
            if (n1 < 0) {
				return "neutral";
			} else if (n1 == 1) {
				return "neutral";
			} else if (n1 == 0) {
				return "neutral";
			} else if (n1 == 2 || n1 == 3 || n1 == 5 || n1 == 7) {
				return "prime";
			} else if (((n1 % 6 != 1)&&(n1 % 6 != 5))||(n1 % 5 == 0) || (n1 % 7 == 0)) {
				return "composite";
			} else {
				for (int i = 11; i <= this->floor(this->sqrt(n1)); i++) {
					if (n1 % i != 0 && (i == this->floor(this->sqrt(n1)) || i == this->floor(this->sqrt(n1))-1)) {
						return "prime";
					} else if (n1 % i == 0) {
					    return "composite";
					}
				}
			}
        }
        //Finds the prime decomposition of a number i.e. what primes the number is made up of (apart from one)
        string primeDecomposition(int n1) {
            if (this->round(n1) != n1 || n1 < 1) {
				return "";
			} else if (n1 == 1) {
				return "1";
			} else if (n1 == 2 || n1 == 3 || n1 == 5 || n1 == 7) {
				return static_cast<ostringstream*>( &(ostringstream() << (n1)) )->str();
			} else if (((n1 % 6 != 1)&&(n1 % 6 != 5))||(n1 % 5 == 0) || (n1 % 7 == 0)) {
			    string pd;
			    int n1pd = n1;
			    vector<int> n1pdnums;
			    vector<int> n1pdpowers;
				while (true) {
					if (n1pd == 1) {
						break;
					} else {
						for (int i = 2; i <= n1/2; i++) {
							if (((double)n1pd)/i == this->ceiling(n1pd/i)) {
								n1pd /= i;
								for (int j = 0; j < n1pdnums.size(); j++) {
									if (n1pdnums[j] == i) {
										n1pdpowers[j]++;
										break;
									} else if (j == n1pdnums.size()-1) {
										n1pdnums.push_back(i);
										n1pdpowers.push_back(1);
										break;
									}
								}
								if (n1pdnums.size() == 0) {
									n1pdnums.push_back(i);
									n1pdpowers.push_back(1);
								}
								break;
							}
						}
					}
				}
				for (int i = 0; i < n1pdnums.size(); i++) {
					pd += static_cast<ostringstream*>( &(ostringstream() << (n1pdnums[i])) )->str();
					if (n1pdpowers[i] != 1) {
						pd += ("^" + static_cast<ostringstream*>( &(ostringstream() << (n1pdpowers[i])) )->str());
					}
					if (i != n1pdnums.size()-1) {
						pd += " x ";
					}
				}
				return pd;
			} else {
				for (int i = 11; i <= this->floor(this->sqrt(n1)); i++) {
					if (n1 % i != 0 && (i == this->floor(this->sqrt(n1)) || i == this->floor(this->sqrt(n1))-1)) {
						return static_cast<ostringstream*>( &(ostringstream() << (n1)) )->str();
					} else if (n1 % i == 0) {
						string pd;
                        int n1pd = n1;
                        vector<int> n1pdnums;
                        vector<int> n1pdpowers;
                        while (true) {
                            if (n1pd == 1) {
                                break;
                            } else {
                                for (int i = 2; i <= n1/2; i++) {
                                    if (((double)n1pd)/i == this->ceiling(n1pd/i)) {
                                        n1pd /= i;
                                        for (int j = 0; j < n1pdnums.size(); j++) {
                                            if (n1pdnums[j] == i) {
                                                n1pdpowers[j]++;
                                                break;
                                            } else if (j == n1pdnums.size()-1) {
                                                n1pdnums.push_back(i);
                                                n1pdpowers.push_back(1);
                                                break;
                                            }
                                        }
                                        if (n1pdnums.size() == 0) {
                                            n1pdnums.push_back(i);
                                            n1pdpowers.push_back(1);
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                        for (int i = 0; i < n1pdnums.size(); i++) {
                            pd += static_cast<ostringstream*>( &(ostringstream() << n1pdnums[i]) )->str();
                            if (n1pdpowers[i] != 1) {
                                pd += "^" + static_cast<ostringstream*>( &(ostringstream() << (n1pdpowers[i])) )->str();
                            }
                            if (i != n1pdnums.size()-1) {
                                pd += " x ";
                            }
                        }
                        return pd;
					}
				}
			}
        }
        //Gets the factors of a number i.e. everything that the number is divisible by
        vector <int> getFactors(int n1) {
            vector<int> n1factors;
            if (n1 < 0 || n1 == 0 || this->round(n1) != n1) {
			} else if (n1 == 1) {
				n1factors.push_back(1);
			} else if (n1 == 2 || n1 == 3 || n1 == 5 || n1 == 7) {
				n1factors.push_back(1);
				n1factors.push_back(n1);
			} else if (((n1 % 6 != 1)&&(n1 % 6 != 5))||(n1 % 5 == 0) || (n1 % 7 == 0)) {
				for (int i = 2; i <= this->floor(this->sqrt(n1)); i++) {
					if (n1 == this->floor(this->sqrt(n1)) * this->floor(this->sqrt(n1)) && i == this->sqrt(n1)) {
						n1factors.push_back(i);
					} else if (n1 % i == 0) {
						n1factors.push_back(i);
						n1factors.push_back(n1/i);
					}
				}
				n1factors.push_back(1);
				n1factors.push_back(n1);
				Sort.quickSort(n1factors);
			} else {
				for (int i = 11; i <= this->floor(this->sqrt(n1)); i++) {
					if (n1 % i != 0 && (i == this->floor(this->sqrt(n1)) || i == this->floor(this->sqrt(n1))-1)) {
						n1factors.push_back(1);
						n1factors.push_back(n1);
					} else if (n1 % i == 0) {
						for (int i = 2; i <= this->floor(this->sqrt(n1)); i++) {
                            if (n1 == this->floor(this->sqrt(n1)) * this->floor(this->sqrt(n1)) && i == this->sqrt(n1)) {
                                n1factors.push_back(i);
                            } else if (n1 % i == 0) {
                                n1factors.push_back(i);
                                n1factors.push_back(n1/i);
                            }
                        }
                        n1factors.push_back(1);
                        n1factors.push_back(n1);
                        Sort.quickSort(n1factors);
					}
				}
			}
			return n1factors;
        }
        //Finds the current time
        time_t now() {
            time_t now;
            time(&now);
            return now;
        }
        //Returns a date string based on a timestamp
        string dateString(time_t timestamp) {
            return ctime(&timestamp);
        }
        //Returns the current time in a string
        string dateStringNow() {
            time_t now;
            time(&now);
            return ctime(&now);
        }
        //Factors the given numbers in the following format: (x +/- a)(x +/- b)
        string factor(string operator1, double a, string operator2, double b) {
            if (operator1 == "-") {
                a *= -1;
            }
            if (operator2 == "-") {
                b *= -1;
            }
            string result;
            result += "x^2";
            if (a + b > 0) {
                result += "+";
            }
            if ((a + b) != 1) {
                result += static_cast<ostringstream*>( &(ostringstream() << (a + b)) )->str();
            }
            result += "x";
            if (a * b > 0) {
                result += "+";
            }
            result += static_cast<ostringstream*>( &(ostringstream() << (a * b)) )->str();
            return result;
        }
        //Finds the two roots of a specified quadratic equation
        double quadRoot1(double a, double b, double c) {
             double d = b*b - 4*a*c;
             if (d > 0.0) {
                return (-b + this->sqrt(d)) / 2 / a;
             } else if (b*b - 4*a*c == 0) {
                return (-b / 2 / a);
             } else {
                return 0;
             }
        }
        double quadRoot2(double a, double b, double c) {
             double d = b*b - 4*a*c;
             if (d > 0.0) {
                return (-b - this->sqrt(d)) / 2 / a;
             } else if (b*b - 4*a*c == 0) {
                return (-b / 2 / a);
             } else {
                return 0;
             }
        }
        //The nPr function finds the number of permuations of r objects out of n objects
        //The number of permuations is the least number of ways to acheive something in a certain order
        int nPr(int n, int r){
            return (this->factorial(n))/(this->factorial(n - r));
        }
        //The nCr function finds the number of combinations of r objects out of n objects
        //The number of combinations is the least number of ways to acheive something where order does not matter
        int nCr(int n, int r) {
            return (this->factorial(n))/(this->factorial(r) * (this->factorial(n - r)));
        }
        //The following functions change the base of a number and returns value in new base.
        int changeBase(int num, int fromBase, int toBase) {
        }
        int fromBase10(int num, int toBase) {
        }
        int toBase10(double num, int fromBase) {
        }
};
myMath Math;
