#ifndef NUMBERTOSTRINGCONVERTOR_H
#define NUMBERTOSTRINGCONVERTOR_H
#include <vector>
#include <map>
#include <QString>
using namespace std;
class NumberToStringConvertor
{
public:
  NumberToStringConvertor();
  QString NumberToString(QString);
private:
  map<int, QString> main_array, magnitude;
  vector<int> split_numbers(QString);
  QString correct_word_endings(int , int);
  QString final_conversion(vector<int>);
};

#endif // NUMBERTOSTRINGCONVERTOR_H
