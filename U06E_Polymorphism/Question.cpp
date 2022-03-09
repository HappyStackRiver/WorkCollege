#include "Question.hpp"

#include <iostream>
#include <string>
using namespace std;

void IQuestion::SetQuestion(string question)
{
	m_question = question;
}

void IQuestion::DisplayQuestion()
{
	cout << endl << "Question" << endl << m_question << endl;
}

void FillInTheBlankQuestion::SetAnswer(string answer)
{
	m_answer = answer;
}

bool FillInTheBlankQuestion::AskQuestion()
{
	DisplayQuestion();
	string temp;
	cin.ignore();
	getline(cin, temp);

	if (m_answer == temp)
	{
		cout << "Correct!" << endl;
		return true;
	}
	else
		cout << "Wrong!" << endl;
		return false;
}

void TrueFalseQuestion::SetAnswer(bool answer)
{
	m_answer = answer;
}

bool TrueFalseQuestion::AskQuestion()
{
	DisplayQuestion();
	
	cout << "0. false" << endl << "1. true" << endl << "Your answer: ";
	int temp;
	cin >> temp;
	if (temp == m_answer)
	{
		cout << "Correct!";
		return true;
	}
	else
		cout << "Wrong!";
		return false;
	
}

void MultipleChoiceQuestion::SetAnswer(array<string, 4> answers, int inputIndex)
{
	m_correctIndex = inputIndex;
	m_answers = answers;

}

bool MultipleChoiceQuestion::AskQuestion()
{
	DisplayQuestion();
	for (int i = 0; i < 4; i++)
	{
		cout << i << ". " << m_answers[i] << endl;
	}
	cout << "Your answer: ";
	int temp;
	cin >> temp;
	if (temp == m_correctIndex)
	{
		cout << "Correct!";
		return true;
	}
	else
	{
		cout << "Wrong!";
		return false;
	}
}
