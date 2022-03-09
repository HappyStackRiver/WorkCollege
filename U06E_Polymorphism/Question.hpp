#ifndef _QUESTION_HPP
#define _QUESTION_HPP

#include <iostream>
#include <string>
#include <array>
using namespace std;

class IQuestion
{
public:
    virtual void SetQuestion(string question);
    virtual void DisplayQuestion();
    virtual bool AskQuestion() = 0;

protected:
    string m_question;
};

class FillInTheBlankQuestion : public IQuestion
{
public:
    void SetAnswer(string);
    bool AskQuestion();

protected:
    string m_answer;

};

class TrueFalseQuestion : public IQuestion
{
public:
    void SetAnswer(bool);
    bool AskQuestion();
protected:
    bool m_answer;
};

class MultipleChoiceQuestion : public IQuestion
{
public:
    void SetAnswer(array<string,4>, int);
    bool AskQuestion();
protected:
    array<string,4> m_answers;
    int m_correctIndex;
};

#endif
