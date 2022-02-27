#ifndef _QUESTION_HPP
#define _QUESTION_HPP

#include <iostream>
#include <string>
using namespace std;

class IQuestion
{
};

class FillInTheBlankQuestion : public IQuestion
{
};

class TrueFalseQuestion : public IQuestion
{
};

class MultipleChoiceQuestion : public IQuestion
{
};

#endif
