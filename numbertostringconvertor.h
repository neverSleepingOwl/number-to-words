#ifndef NUMBERTOSTRINGCONVERTOR_H
#define NUMBERTOSTRINGCONVERTOR_H
#include <vector>
#include <map>
#include <QString>
using namespace std;
class NumberToStringConvertor
{
/*class containing several functions to convert number into it's number name in russian
 * russian cursive is used to prevent problems with encodings
 * algorythm is simple: firstly, main array of three digit number names is filled (once for all time of work of a program)
 * initialisation of this array is included in class constructor
 * then for each request from main program several actions are done:
 * number is splitted by three digit numbers
 * then each number is named and its order of magnitude is named, after that all
 * names are concatenated
 * for instance: 123456-> 123 456 ->sto dvadcat' tri tisyachi chetyresta pyatdecyat shest'*/
public:
  NumberToStringConvertor();
  QString NumberToString(QString);//function, which converts number, represented as a QString it's name in russian, written in cursive
private:
  map<int, QString> main_array, magnitude;
  vector<int> split_numbers(QString);//function which splits number by 3 (123234 - > 123  234)
  QString correct_word_endings(int , int);//function to correct endings of words(suitable just for russian language)
  QString final_conversion(vector<int>);//function
};

#endif // NUMBERTOSTRINGCONVERTOR_H
