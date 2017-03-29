#include "numbertostringconvertor.h"
#include <map>
#include <vector>
#include <QString>
using namespace std;
NumberToStringConvertor::NumberToStringConvertor()//initialisation of main array, where all number names from 0 to 999 are stored
{
  QString temporary;//storing all those number names isn't neccesary and increases consumption of memory,
  //but it optimises multiple conversions
  main_array = {{0, "nol"}, {1,"odin"},{2, "dva"},{3, "tri"}, {4, "chetire"}, {5, "pyat"}, {6, "shest"}, {7,"sem"}, {8, "vosem"},
  {9,"devyat"}, {10,"desyat"}, {11,"odinnadtcat"}, {12,"dvennadcat"}, {13,"trinadcat"}, {14,"chetirnadcat"}, {15,"pyatnadcat"},
  {16, "shestnadcat"}, {17, "semnadcat"}, {18, "vosemnadcat"}, {19, "devyatnadcat"}, {20, "dvadcat"}, {30, "tridcat"},
  {40, "sorok"}, {50, "pyatdecyat"}, {60, "shestdecyat"}, {70, "semdecyat"}, {80, "vocemdesyat"}, {90, "devyanosto"},
  {100, "sto"}, {200, "dvesti"}, {300, "trista"}, {400, "chetiresta"}, {500, "pyatsot"}, {600, "shestsot"}, {700, "semsot"}, {800, "vosemsot"}, {900, "devyatsot"}};
  magnitude = {{1,"tisyach"}, {2, "millionov"}, {3, "milliardov"}, {4, "trillionov"}, {5, "quadrillionov"}};
  for(int i = 0; i<1000; i++){
      temporary = "";
      if (main_array.count(i) == 0){
          temporary += ((i-(i%100)) > 0)?main_array[i-(i%100)]+ " ":"";
          if(((i%100) > 9) && ((i%100) < 20)){
              temporary += main_array[i%100];
          }
          else{
              if (((i%100) - (i%10)) > 0) temporary += main_array[i%100 - i%10]+" ";
              if (i%10 != 0) temporary += main_array[i%10];
          }
          main_array.insert(pair<int, QString>(i, temporary));
      }
   }
}
QString NumberToStringConvertor::NumberToString(QString input){//returns string of words if input is correct, else returns "*"
  bool err = false;//error flag
  if((input.size()/3) <= 6){//this program doesn't work with numbers with order of magn. higher than qaudrillions
      QString mainstr;
      if (input.startsWith("-")){//working with negative numbers
          mainstr += "minus ";
          input.remove(0,1);
      }
      for(int i = 0; i < input.size(); i++){//checking if string is a number
          if (!input[i].isDigit()){
              err = true;
              break;
          }
      }
      if (err){//returning '*' is the same as throwing exception
          return "*";
      }
      else{
          mainstr += final_conversion(split_numbers(input));//final conversion
          return mainstr;
      }
  }
  return "*";
}
vector<int> NumberToStringConvertor::split_numbers(QString input){//this function splits number by triads because each number: 1234 -> {1, 234}
    QString str = input;//is represented like <any number> ::= <value> <order of magn.>||<value>; for example 1000 -> <value = "odna"> <order of.. = "tysyacha">
    vector<int> splitted, inverted;
    while(str.size()>3){//splitting by triads
        inverted.push_back(str.mid((str.size()- 3), 3).toInt());//splitting goes from right to left, so we get inverted vector
        str.chop(3);
    }
    if(str.size() > 0) inverted.push_back(str.toInt());
    for(int i = 1; i <= inverted.size();i++){// inversion of a vector
         splitted.push_back(inverted[inverted.size() - i]);
    }
    return splitted;
}
QString NumberToStringConvertor::correct_word_endings(int order_of_magnitude, int value){//function, which fixes words endings(ONLY for russian language)
    /*this function gets a three digit number and it's order of magnitude and returns name of those number with name of order of magnitude
     * and corrected word endings*/
    QString tmp1, tmp2, summ;//tmp1 is temporary variable to storage name of a three digit numbers, tmp2 is for storing name of order of mag.
    //summ is for output
    if (value != 0){//we ignore zero values,cause all number names except 0 doesn't contain 'zero' substring
        tmp1 = main_array[value];//we get names of three digit numbers from main array
        if (order_of_magnitude == 1){//for thousands(cause thousands in russian need special ending conversion)
            tmp2 = magnitude[order_of_magnitude];//getting order of magnitude()
            if ((value%100<9)||(value%100>20)){//numbers from 10 to 19 doesn't need to be converted
                if ((value%10>0) && (value%10<5)){//special line-ending conversion for 1,2,3,4
                    if (value%10 == 1){
                        tmp1.replace("odin", "odna");
                        tmp2 += "a";
                    }
                    else if (value%10 == 2){
                        tmp1.replace("dva", "dve");
                        tmp2 += "i";
                    }
                    else{
                        tmp2 += "i";
                    }
                }
            }
            summ = " " + tmp1 + " " + tmp2;
        }
        else if(order_of_magnitude>0){//for billions/trillions etc.
            tmp2 = magnitude[order_of_magnitude];
            if ((value%100<9)||(value%100>20)){//the same conversion of line endings for billions/...
                if ((value%10>0) && (value%10<5)){
                    if (value%10 == 1){
                        tmp2.replace("ov", "");//TODO rewrite this part of code to make it more clear
                    }
                    else if (value%10 == 2){
                        tmp2.replace("ov", "a");
                    }
                    else{
                        tmp2.replace("ov", "a");
                    }
                }
            }
            summ = " " + tmp1 + " " + tmp2;
        }
        else summ += " " + tmp1;
    }
    return summ;
}
QString NumberToStringConvertor::final_conversion(vector<int> num){
    QString output = "";
    for(int i = 0; i < num.size(); i++){
        if (!correct_word_endings(num.size() - i - 1, num[i]).isEmpty())output+=correct_word_endings(num.size() - i - 1, num[i]);
        else if ((output.size() == 0)&&(i == num.size()-1)) output+=" nol";
    }
    return output;
}
