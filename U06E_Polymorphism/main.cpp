#include "Question.hpp"

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int score = 0;
    int totalQuestions = 2;

    // TODO: Set up questions
    FillInTheBlankQuestion question1;
    question1.SetQuestion("What is the best programming language");
    question1.SetAnswer("C++");

    TrueFalseQuestion question2;
    question2.SetQuestion("Discrete structures hits different as a class");
    question2.SetAnswer(true);

    MultipleChoiceQuestion question3;
    question3.SetQuestion("What is the objective best build in Elden Ring?");
        array<string, 4> answers = { "Dex","Str","Faith","Magic" };
        question3.SetAnswer(answers, 0);

    // TODO: Run quiz

    cout << endl << "QUIZZER" << endl;
    cout << "--------------------------------------------" << endl;
    if (question1.AskQuestion() == true)
    {
        score += 1;
    }

    if (question2.AskQuestion() == true)
    {
        score += 1;
    }

    if (question3.AskQuestion() == true)
    {
        score += 1;
    }

    cout << endl << string( 80, '-' ) << endl << "RESULTS" << endl;
    cout << score << " correct out of " << totalQuestions << endl;

    return 0;
}
