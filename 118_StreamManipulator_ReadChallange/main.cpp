// Section 19
// Challenge 2 - Solution
// Automated Grader
#include <iostream>
#include <fstream>
#include <iomanip>

// function prototypes
void print_header();
void print_footer(double average);
void print_student(const std::string &student, int score);
int process_response(const std::string &response, const std::string &answer_key);

void print_header()
{
    std::cout << std::setw(15) << std::left << "Student"
              << std::setw(5) << "Score" << std::endl;
    std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
}

void print_footer(double average)
{
    std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(15) << std::left << "Average score"
              << std::setw(5) << std::right << average;
}

void print_student(const std::string &student, int score)
{
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << std::setw(15) << std::left << student
              << std::setw(5) << std::right << score << std::endl;
}

int process_response(const std::string &response, const std::string &answer_key)
{
    int i{0};
    int point{0};
    for (char c : answer_key)
    {
        if (response.at(i) == c)
        {
            point++;
            i++;
        }
    }
    return point;
}

int main()
{
    std::ifstream inFile;
    std::string answerKey{};
    std::string name{};
    std::string responce{};
    int totalStudents{0};
    double averageScore{0};
    int runningSum{0};
    int score{0};

    inFile.open("./responses.txt");
    if (!inFile)
    {
        std::cerr << "Problem to open a file" << std::endl;
        std::exit(1);
    }
    // ************************

    inFile >> answerKey;

    print_header();

    while (inFile >> name >> responce)
    {
        totalStudents++;
        score = process_response(responce, answerKey);
        print_student(name, score);
        runningSum += score;
    }
    if (totalStudents != 0)
    {
        averageScore = static_cast<double>(runningSum) / totalStudents;
    }

    print_footer(averageScore);

    inFile.close();
    std::cout << std::endl
              << std::endl;
}
