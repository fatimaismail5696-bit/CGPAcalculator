#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int numCourses;
    cout << "Enter number of courses this semester: ";
    cin >> numCourses;

    double grade, creditHours;
    double totalCredits = 0, totalGradePoints = 0;

    // For storing data for display
    double grades[50];
    double credits[50];

    for (int i = 0; i < numCourses; i++) {
        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Enter grade (e.g. 4.0 for A, 3.0 for B): ";
        cin >> grade;
        cout << "Enter credit hours: ";
        cin >> creditHours;

        grades[i] = grade;
        credits[i] = creditHours;

        totalCredits += creditHours;
        totalGradePoints += grade * creditHours;
    }

    double semesterGPA = totalGradePoints / totalCredits;

    // Get previous record for CGPA calculation
    double prevCredits, prevGradePoints;
    cout << "\nEnter previous total credits: ";
    cin >> prevCredits;
    cout << "Enter previous total grade points: ";
    cin >> prevGradePoints;

    // Update totals
    double overallCredits = prevCredits + totalCredits;
    double overallGradePoints = prevGradePoints + totalGradePoints;

    double CGPA = overallGradePoints / overallCredits;

    // Display results
    cout << fixed << setprecision(2);
    cout << "\n--- Semester Summary ---\n";
    for (int i = 0; i < numCourses; i++) {
        cout << "Course " << i + 1 
             << ": Grade = " << grades[i]
             << ", Credits = " << credits[i] << "\n";
    }
    cout << "Semester GPA: " << semesterGPA << "\n";
    cout << "Overall CGPA: " << CGPA << "\n";

    return 0;
}

