#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <limits> // Include for numeric_limits

using namespace std;

// Function to validate score inputs
bool isValidScore(double score, double maxScore) {
    return score >= 0 && score <= maxScore;
}

// Function to calculate the overall grade percentage
double calcOverallGrade(double assignScore, double midsemScore, double examScore,
                        double assignMax, double midsemMax, double examMax) {
    // Calculate total score and total max score
    double totalScore = assignScore + midsemScore + examScore;
    double totalMaxScore = assignMax + midsemMax + examMax;
    // Calculate overall grade percentage
    double percentage = (totalScore / totalMaxScore) * 100.0;
    return percentage;
}

// Function to calculate the letter grade
char calcLetterGrade(double overallGrade) {
    if (overallGrade >= 90)
        return 'A';
    else if (overallGrade >= 80)
        return 'B';
    else if (overallGrade >= 70)
        return 'C';
    else if (overallGrade >= 60)
        return 'D';
    else
        return 'F';
}

// Function to provide feedback based on the final grade
string getFeedback(double overallGrade, double examScore, char& letterGrade) {
    if (examScore < 40) {
        letterGrade = 'F';
        return "Failed";
    } else if (overallGrade >= 90) {
        letterGrade = 'A';
        return "Excellent work!";
    } else if (overallGrade >= 80) {
        letterGrade = 'B';
        return "Good job!";
    } else if (overallGrade >= 70) {
        letterGrade = 'C';
        return "You're doing fine.";
    } else if (overallGrade >= 60) {
        letterGrade = 'D';
        return "Some improvement needed.";
    } else {
        letterGrade = 'F';
        return "You need to work harder.";
    }
}

int main() {
    vector<string> names;
    vector<int> rollNos;
    vector<double> assigns;
    vector<double> midsems;
    vector<double> exams;

    double assignMax, midsemMax, examMax;

    // Input maximum marks for each category
    cout << "Enter maximum marks for assignments: ";
    cin >> assignMax;

    cout << "Enter maximum marks for midsem: ";
    cin >> midsemMax;

    cout << "Enter maximum marks for endsem: ";
    cin >> examMax;

    // Loop to input data for multiple students
    char repeat = 'y';
    while (repeat == 'y' || repeat == 'Y') {
        string name;
        int rno;
        double assign, midsem, exam;

        // Input student details
        cout << "Enter student name: ";
        cin >> name;
        names.push_back(name);

        cout << "Enter student Roll no: ";
        cin >> rno;
        rollNos.push_back(rno);

        // Input scores for each category with validation
        cout << "Enter assignment score (0-" << assignMax << "): ";
        cin >> assign;
        while (!isValidScore(assign, assignMax)) {
            cerr << "Error: Invalid assignment score input. Please enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> assign;
        }
        assigns.push_back(assign);

        cout << "Enter midsem score (0-" << midsemMax << "): ";
        cin >> midsem;
        while (!isValidScore(midsem, midsemMax)) {
            cerr << "Error: Invalid midsem score input. Please enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> midsem;
        }
        midsems.push_back(midsem);

        cout << "Enter exam score (0-" << examMax << "): ";
        cin >> exam;
        while (!isValidScore(exam, examMax)) {
            cerr << "Error: Invalid exam score input. Please enter again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> exam;
        }
        exams.push_back(exam);

        // Ask if the user wants to input data for another student
        cout << "Do you want to enter another student's data? (y/n): ";
        cin >> repeat;
    }

    // Output results
    cout << "\n\n";
    cout << "-------------------------------------------------------\n";
    cout << "Student Report:\n";
    cout << "-------------------------------------------------------\n";
    cout << setw(15) << "Name" << setw(10) << "ID" << setw(15) << "Overall %" << setw(10) << "Grade" << setw(10) << "Feedback\n";
    cout << "-------------------------------------------------------\n";

    // Iterate over student data to calculate grades and provide feedback
    for (size_t i = 0; i < names.size(); ++i) {
        double overallGrade = calcOverallGrade(assigns[i], midsems[i], exams[i],
                                               assignMax, midsemMax, examMax);
        char letterGrade;
        string feedback = getFeedback(overallGrade, exams[i], letterGrade);

        // Output student report
        cout << setw(15) << names[i] << setw(10) << rollNos[i] << setw(15) << overallGrade << setw(10) << letterGrade << setw(10) << feedback << "\n";
    }

    return 0;
}
