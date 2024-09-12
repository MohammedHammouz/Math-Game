// Math-Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstdlib> 
#include "MathGame.h";
#include <vector>
using namespace std;
using namespace MathGame;
enum enQuestionLevel { Easy = 1, Medium = 2, Hard = 3, Mix1 = 4 };
enum enQuizResult { Fail = 1, Pass = 2 };
enum enOperationtype { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix2 = 5 };
enum enQuestionStatus { Correct = 1, Wrong = 2 };

struct strQuestionRound {
    unsigned int number1 = 0;
    unsigned int number2 = 0;
    unsigned int answer = 0;
    int myAnswer = 0;
    enQuestionStatus status;
    enQuestionLevel level;
    enOperationtype operation;
    string opt = "";
    string Level = "";
    enOperationtype randomoperation ;
};
struct strResult {
    unsigned int totalQuestions = 0;
    enQuestionLevel level;
    enOperationtype operationType;
    enQuizResult result;
    string quizresult = "";
    unsigned int rightQuestionsNumber = 0;
    unsigned int wrongQuestionsNumber = 0;
    unsigned int QuestionsNumber = 0;
};
//define function

unsigned int ReadAPositiveNumber(string message);
enOperationtype ChooseOperationType();
enQuestionLevel ChooseQuizLevel();
int GenerateNumberBasedOnLevel(enQuestionLevel level);
void SetScreenColor(enQuestionStatus status);
int FillYourAnswer();
string ChooseSymbol(strQuestionRound& operations);
string FindarrQuestionLevel(enQuestionLevel level);
string CheckResult(strResult result);
string FindarrOperationType(enOperationtype& op);
void ChooseRandomOperations(strQuestionRound& operations);
void ChooseOperation(strQuestionRound& operations);
string Checkarrstatus(enQuestionStatus status);
void QuestionRound(strQuestionRound& round, strResult result);
void QuizeResult(strResult result, strQuestionRound round); 
void StartQuiz(unsigned int questionNumber, enQuestionLevel level, enOperationtype operation);
void QuizResult();

unsigned int ReadAPositiveNumber(string message) {
    unsigned int number;
    do {
        cout << message;
        cin >> number;
    } while (number < 1);
    return number;
}

enOperationtype ChooseOperationType() {
    int operation;
    do {
        cout << "Choose operation type [1]: Add, [2]: Sub, [3]: Mul, [4]: Div, [5]: Mix: ";
        cin >> operation;
    } while (operation < 1 || operation > 5);
    return (enOperationtype)operation;
}
enQuestionLevel ChooseQuizLevel() {
    int operation;
    do {
        cout << "Choose question level [1]: Easy, [2]: Medium, [3]: Hard, [4]: Mix: \n";
        cin >> operation;
    } while (operation < 1 || operation > 4);
    return (enQuestionLevel)operation;
}
int GenerateNumberBasedOnLevel(enQuestionLevel level) {
    switch (level) {
    case Easy: return MathGame::RandomNumber(1, 50);
    case Medium: return MathGame::RandomNumber(51, 100);
    case Hard: return MathGame::RandomNumber(101, 150);
    default: return MathGame::RandomNumber(1, 150);
    }
}
void SetScreenColor(enQuestionStatus status) {
    if (status == Correct) {
        system("Color 2F");
    }
    else {
        cout << '\a';
        system("Color 4F");
    }
}
int FillYourAnswer() {
    unsigned int userAnswer;
    cin >> userAnswer;
    return userAnswer;
}
string ChooseSymbol(strQuestionRound& operations) {
    switch (operations.operation) {
    case enOperationtype::Add:
        return "+";
    case enOperationtype::Sub:
        return "-";
    case enOperationtype::Div:
        return "/";
    case enOperationtype::Mul:
        return "*";
    default:
        return "Mix";
    }
}
string FindarrQuestionLevel(enQuestionLevel level) {
    vector <string> arrquestionlevel = { "Easy", "Medium", "Hard", "Mix" };
    return arrquestionlevel[level - 1];
}
string CheckResult(strResult result) {
    if (result.rightQuestionsNumber < result.wrongQuestionsNumber) {
        return "Fail :(";
    }
    else {
        return "Pass :)";
    }
}
string FindarrOperationType(enOperationtype& op) {
    vector <string> arrOperationType = { "+", "-", "*", "/" };
    return arrOperationType[op - 1];
}
void ChooseRandomOperations(strQuestionRound& operations) {
    operations.randomoperation = enOperationtype(RandomNumber(1, 4));
    switch (operations.randomoperation) {
    case Add:
        operations.number1 = GenerateNumberBasedOnLevel(operations.level);
        operations.number2 = GenerateNumberBasedOnLevel(operations.level);
        operations.answer = operations.number1 + operations.number2;
        cout << operations.number1 << endl;
        cout << operations.number2 << "  " << FindarrOperationType(operations.randomoperation) << endl;
        cout << "-------------\n";
        operations.myAnswer = FillYourAnswer();
        break;
    case Sub:
        operations.number1 = GenerateNumberBasedOnLevel(operations.level);
        operations.number2 = GenerateNumberBasedOnLevel(operations.level);
        operations.answer = operations.number1 - operations.number2;
        cout << operations.number1 << endl;
        cout << operations.number2 << "  " << FindarrOperationType(operations.randomoperation) << endl;
        cout << "-------------\n";
        operations.myAnswer = FillYourAnswer();
        break;
    case Mul:
        operations.number1 = GenerateNumberBasedOnLevel(operations.level);
        operations.number2 = GenerateNumberBasedOnLevel(operations.level);
        operations.answer = operations.number1 * operations.number2;
        cout << operations.number1 << endl;
        cout << operations.number2 << "  " << FindarrOperationType(operations.randomoperation) << endl;
        cout << "-------------\n";
        operations.myAnswer = FillYourAnswer();
        break;
    case Div:
        operations.number1 = GenerateNumberBasedOnLevel(operations.level);
        operations.number2 = GenerateNumberBasedOnLevel(operations.level);
        operations.answer = operations.number1 / operations.number2;
        cout << operations.number1 << endl;
        cout << operations.number2 << "  " << FindarrOperationType(operations.randomoperation) << endl;
        cout << "-------------\n";
        operations.myAnswer = FillYourAnswer();
        break;
    }
}

void ChooseOperation(strQuestionRound& operations) {
    switch (operations.operation) {
        case Add:
            operations.number1 = GenerateNumberBasedOnLevel(operations.level);
            operations.number2 = GenerateNumberBasedOnLevel(operations.level);
            operations.answer = operations.number1 + operations.number2;
            cout << operations.number1 << endl;
            cout << operations.number2 << "  " << ChooseSymbol(operations) << endl;
            cout << "-------------\n";
            operations.myAnswer = FillYourAnswer();
            break;
        case Sub:
            operations.number1 = GenerateNumberBasedOnLevel(operations.level);
            operations.number2 = GenerateNumberBasedOnLevel(operations.level);
            operations.answer = operations.number1 - operations.number2;
            cout << operations.number1 << "\n";
            cout << operations.number2 << "  " << ChooseSymbol(operations) << "\n";
            cout << "-------------\n";
            operations.myAnswer = FillYourAnswer();
            break;
        case Mul:
            operations.number1 = GenerateNumberBasedOnLevel(operations.level);
            operations.number2 = GenerateNumberBasedOnLevel(operations.level);
            operations.answer = operations.number1 * operations.number2;
            cout << operations.number1 << "\n";
            cout << operations.number2 << "  " << ChooseSymbol(operations) << "\n";
            cout << "-------------\n";
            operations.myAnswer = FillYourAnswer();
            break;
        case Div:
            operations.number1 = GenerateNumberBasedOnLevel(operations.level);
            operations.number2 = GenerateNumberBasedOnLevel(operations.level);
            operations.answer = operations.number1 / operations.number2;
            cout << operations.number1 << "\n";
            cout << operations.number2 << "  " << ChooseSymbol(operations) << "\n";
            cout << "-------------\n";
            operations.myAnswer = FillYourAnswer();
            break;
        case Mix2:
            ChooseRandomOperations(operations);
    }
}    
string Checkarrstatus(enQuestionStatus status) {
    vector <string> arrstatus = {"Correct", "Wrong"};
    return arrstatus[status - 1];
}

void QuestionRound(strQuestionRound & round, strResult result) {
        ChooseOperation(round);
        if (round.myAnswer == round.answer) {
            round.status = Correct;
            SetScreenColor(round.status);
            cout << Checkarrstatus(round.status)<<'\n';
        }
        else {
            round.status = Wrong;
            SetScreenColor(round.status);
            cout << Checkarrstatus(round.status) << '\n';
            cout << "Correct answer is: " << round.answer << endl;
        } 
 }

void QuizeResult(strResult result, strQuestionRound round) {
        cout << "____________________________________________________________\n\n";
        cout << "Final result is: " << CheckResult(result) << '\n';
        cout << "____________________________________________________________\n\n";
        cout << "Number of  questions are: " << result.QuestionsNumber << '\n';
        cout << "Questions level: " << round.Level << '\n';
        cout << "Operation type: " << round.opt << '\n';
        cout << "Number of right question are: " << result.rightQuestionsNumber << endl;
        cout << "Number of wrong question are: " << result.wrongQuestionsNumber << "\n\n";
        if (result.rightQuestionsNumber >= result.wrongQuestionsNumber) {
            round.status = Correct;
            SetScreenColor(round.status);
        }
        else {
            round.status = Wrong;
            SetScreenColor(round.status);
        }
    }

void StartQuiz(unsigned int questionNumber, enQuestionLevel level, enOperationtype operation) {
        strQuestionRound round;
        unsigned int rightQuestionsNumber = 0;
        unsigned int wrongQuestionsNumber = 0;
        unsigned int QuestionsNumber = 0;
        round.level = level;
        round.operation = operation;
        strResult result;
        enQuizResult status1;
        for (unsigned int i = 1; i <= questionNumber; i++) {
            cout << "Question [" << i << "/" << questionNumber << "]" << endl;
            QuestionRound(round, result);
            QuestionsNumber++;
            if (round.myAnswer == round.answer) {
                rightQuestionsNumber++;
            }
            else {
                wrongQuestionsNumber++;
            }
        }
        round.Level = FindarrQuestionLevel(round.level);
        round.opt = ChooseSymbol(round);
        result.QuestionsNumber = QuestionsNumber;
        result.rightQuestionsNumber = rightQuestionsNumber;
        result.wrongQuestionsNumber = wrongQuestionsNumber;
        QuizeResult(result, round);
    }

void QuizResult() {
        char start = 'y';
        do{
            unsigned int questionNumber = ReadAPositiveNumber("Enter a number of questions that you want: \n");
            enQuestionLevel level = (enQuestionLevel)ChooseQuizLevel();
            enOperationtype operation = ChooseOperationType();
            enQuizResult status;
            StartQuiz(questionNumber, level, operation);
            ShowQuizEndScreen();
            cout << "Do you want to take another quiz (y/n)? ";
            cin >> start;
            Reset();
        } while (start == 'y' || start == 'Y');
}

int main() {
        srand((unsigned)time(NULL));
        QuizResult();
        return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
