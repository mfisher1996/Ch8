//
//  Validation.h
//  Wk10_ch8
//
//  Created by Mason Fisher on 10/30/18.
//  Copyright © 2018 Mason Fisher. All rights reserved.
//

#ifndef Validation_h
#define Validation_h

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
class Validation{
public:
    /**
     Author: MASON FISHER
     
     Validation constructor
     
     Perameters: none
     
     */
    Validation();
    /**
     Author: MASON FISHER
     
     Validation destructor
     
     Perameters: none
     
     
     */
    ~Validation();
    /**
     Author: MASON FISHER
     
     Validation yOn()
     
     Yes or no input validation.
     Returns true if user types Y or Yes and false if user inputs N or no
     
     Perameters: none
     
     Returns: true if 'Y' is input and false if 'N' is input
     
     */
    bool yOn();
    
    /**
     Author: MASON FISHER
     
     Validation numb(int)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call.
     
     Perameters:
     
     -int num
     
     Returns: an integer from input
     
     */
    int numb(int);
    /**
     Author: MASON FISHER
     
     Validation numb(int, int, int)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call, a low number that should not be less than the input and a high number that is not to be exceeded.
     
     Perameters:
     
     -int num
     -int high
     -int low
     
     Returns: an integer below high and above low
     
     */
    int numb(int, int, int);
    /**
     Author: MASON FISHER
     
     Validation numb(double)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call.
     
     Perameters:
     
     -double num
     
     Returns: a double
     
     */
    double numb(double);
    /**
     Author: MASON FISHER
     
     Validation numb(double, double, double)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call, a low number that should not be less than the input and a high number that is not to be exceeded.
     
     Perameters:
     
     -double num     // Number to be validated. Also passed to disabiguate function call.
     -double high    // Number that should not be exceded by num
     -double low     // Number that should not exced num
     
     Returns: a double below high and above low
     
     */
    double numb(double, int, int);
    /**
     Author: MASON FISHER
     
     Validation numb(float)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call.
     
     Perameters:
     
     -float num
     
     Returns: a float
     
     */
    float numb(float);
    /**
     Author: MASON FISHER
     
     Validation numb(float, float, float)
     
     Discribtion:
     Is passed an argument that will disabiguate the function call, a low number that should not be less than the input and a high number that is not to be exceeded.
     
     Perameters:
     
     -float num      // Number to be validated. Also passed to disabiguate function call.
     -float high     // Number that should not be exceded by num
     -float low      // Number that should not exced num
     
     Returns: a float below high and above low
     
     */
    float numb(float, int, int);
    /**
     Author: MASON FISHER
     
     Validation word()
     
     Discribtion:
     gets a line from input and asks the user if that is what they meant to type.
     
     Perameters: none
     
     Returns: a string that the user confirms
     */
    std::string word();
    /**
     Author: MASON FISHER
     
     Validation clear()
     
     Description:
     clears the input buffer. Used in input functions invloving numbers or anything not including strings.
     
     Perameters: none
     
     
     */
    void clear(){std::cin.clear(); std::cin.ignore(40,'\n');};
    void file(std::fstream *, std::string);
    void out(string output="");
    void out(string output, char x);
    std::string get_s(std::fstream *);
    void setBound(int i){if(bound>0)bound=i;}
private:
    int bound;
    
};

/**
 Validation constructor
 -parameters: none
 */
Validation :: Validation()
{
    bound = 55;
}

/**
 Validation destructor
 -perameters: none
 */
Validation :: ~Validation()
{
}

/**
 MASON FISHER
 Validation yOn()
 Yes or no input validation.
 Returns true if user types Y or Yes and false if user inputs N or no
 -perameters: none
 */
bool Validation :: yOn()
{
    
    std::string str ="";
    out();
    do
    {
        std::cout << "Enter 'Y' for yes or 'N' for No: ";
        std::cin >> str;
        clear();
        if(toupper(str[0]) == 'Y')
            return true;
        else if(toupper(str[0]) == 'N')
            return false;
        else
        {
            out();
            std::cout << "Invalid input, Please ";
        }
        
    }
    while((toupper(str[0]) != 'N'&&(toupper(str[0]) != 'Y')));
    return false;
}

/**
 Validation numb(int)
 integer validation.
 Returns true if user types an integer and returns false if the user does not
 -perameters: int
 */
int Validation :: numb(int num)
{
    out();
    std::cin >> num;
    
    while(!num)
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number: ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(int,int,int)
 ranged integer validation.
 Returns true if user types an integer equal to or between the low high variables
 returns false if int value is below the low value or above the high value
 -perameters: int, min int, max int
 */
int Validation :: numb(int num, int low, int high)
{
    out();
    std::cin >> num;
    
    while(!num||!(num<=high&&num>=low))
    {
        clear();
        out("Invalid input.");
        out();
        std::cout << "Please input a number above " << low-1 <<" but below " << high+1 << ": ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(double)
 double validation.
 Returns true if user types a double value and returns false if the user does not
 -perameters: double
 */
double Validation :: numb(double num)
{
    clear();
    std::cin >> num;
    
    while(!num)
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number: ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(double,int,int)
 ranged double validation.
 Returns true if user types an double that is equal to or between the low and high values
 returns false if double is below low value or above high value
 -perameters: double,min int,max int
 */
double Validation :: numb(double num, int low, int high)
{
    std::cin >> num;
    
    while(!num||!(num<=high||num>=low))
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number above " << low-1 <<" but below " << high+1 << ": ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(float)
 float validation.
 Returns true if user types a float value and returns false if the user does not
 -perameters: float
 */
float Validation :: numb(float num)
{
    std::cin >> num;
    
    while(!num)
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number: ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation numb(float,int,int)
 ranged float validation.
 Returns true if user types a float that is equal to or between the low and high values
 returns false if float is below low value or above high value
 -perameters: float,min int,max int
 */
float Validation :: numb(float num, int low, int high)
{
    std::cin >> num;
    
    while(!num||!(num<=high||num>=low))
    {
        clear();
        out();
        std::cout << "Invalid input.\n";
        out();
        std::cout << "Please input a number above " << low-1 <<" but below " << high+1 << ": ";
        std::cin >> num;
    }
    clear();
    return num;
}

/**
 Validation word()
 string validation.
 takes in string value
 -perameters: ~none~
 */
std::string Validation :: word()
{
    std::string strW = "";
    do{
        out();
        getline(std::cin, strW,'\n');
        out();
        std::cout << "You typed " << strW << ". Is this what you meant?\n";
        if(yOn())
            return strW;
        else
            strW = "";
        out();
        std::cout << "Please re-type your input: ";
    }while(strW == "");
    return strW;
}

/**
 Validation out()
 indents
 -perameters: ~none~
 */
void Validation :: out(string output)
{
    int per=2;
    cout << "\t\t" << setprecision(per);
    if(output.size()>0 && output.size()<=bound) // string passed is within the bounds
    cout << output << endl;
    else if(output.size()==0) // string passed is empty
    return;
    else{ // string passed is larger than bounds
        int i = bound;
        while(output[i]!=' ')
            i--;
        cout << output.substr(0,i) << endl;
        out(output.substr(i+1));
    }
}


void Validation :: out(string output, char x)
{
    int per=2;
    cout << "\t\t" << setprecision(per);
    if(output.size()>0 && output.size()<=bound) // string passed is within the bounds
        cout << output;
    else if(output.size()==0) // string passed is empty
        return;
    else{ // string passed is larger than bounds
        int i = bound;
        while(output[i]!=' ')
            i--;
        cout << output.substr(0,i) << endl;
        out(output.substr(i+1));
    }
}
void Validation :: file(std::fstream * file, std::string name){
    
    file->open(name);
    while(!file->is_open()){
        out("The file could not be found with the name: " + name + " \n");
        out("Please input a new name to check or type -99 to cancel: ");
        out();
        
        name = word();
        
        if(name == "-99")
            return;
        
        file->open(name.c_str());
    }
    if(name != "-99"){
        out();
        std::cout << "The file " << name << " was succesfully opened.\n";
    }
    
}


std::string Validation :: get_s(std::fstream * in){
    
    string output= "";
    getline(*in, output);
    return output;
}

#endif /* Validation_h */
