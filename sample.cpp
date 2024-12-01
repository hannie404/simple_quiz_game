#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

// Questions, choices, and answers for the quiz
string questions[3][10] = {
    { // Easy Questions
        "What does C++ stand for?",
        "Which of the following is a valid C++ keyword?",
        "What is the default access specifier for class members in C++?",
        "What is the size of int in C++?",
        "How do you write a single-line comment in C++?",
        "Which of these is not a C++ data type?",
        "What is the output of std::cout << 'Hello, World!';?",
        "Which library must be included to use std::cout?",
        "What is the extension of a C++ source file?",
        "Which operator is used to access members of a class?"
    },
    { // Intermediate Questions
        "What is a constructor in C++?",
        "Which keyword is used to define a constant in C++?",
        "What is the output of '5/2' in C++?",
        "What does the 'this' pointer in C++ do?",
        "How do you define a function in C++?",
        "Which of these is used for dynamic memory allocation in C++?",
        "What is polymorphism in C++?",
        "How is encapsulation implemented in C++?",
        "What is the difference between '==' and '=' in C++?",
        "Which operator cannot be overloaded in C++?"
    },
    { // Difficult Questions
        "What is the purpose of a virtual function in C++?",
        "What is the order of constructor calls in inheritance?",
        "What happens if a pure virtual function is not overridden in C++?",
        "What is the size of a pointer on a 64-bit system?",
        "How can you prevent a class from being inherited in C++?",
        "What is a smart pointer in C++?",
        "What does the keyword 'volatile' indicate in C++?",
        "What is the difference between 'delete' and 'delete[]' in C++?",
        "What does the term RAII stand for in C++?",
        "Which type of cast should be avoided in C++?"
    }
};

string choices[3][10][4] = {
    { // Easy Choices
        {"A) C with Classes", "B) C Improved", "C) C Plus Plus", "D) None of the above"},
        {"A) for", "B) loop", "C) repeat", "D) None"},
        {"A) public", "B) private", "C) protected", "D) None of the above"},
        {"A) 2 bytes", "B) 4 bytes", "C) 8 bytes", "D) Platform dependent"},
        {"A) //", "B) /* */", "C) ##", "D) <!-- -->"},
        {"A) int", "B) float", "C) bool", "D) boolean"},
        {"A) Compile error", "B) Runtime error", "C) Prints 'Hello, World!'", "D) None of the above"},
        {"A) iostream", "B) stdio.h", "C) conio.h", "D) string"},
        {"A) .cpp", "B) .cxx", "C) .cc", "D) All of the above"},
        {"A) ->", "B) .", "C) ::", "D) Both A and B"}
    },
    { // Intermediate Choices
        {"A) Special member function", "B) Static variable", "C) Inline function", "D) None of the above"},
        {"A) const", "B) #define", "C) static", "D) immutable"},
        {"A) 2.5", "B) 2", "C) 3", "D) None of the above"},
        {"A) Refers to the current class", "B) Refers to the parent class", "C) Refers to the derived class", "D) None of the above"},
        {"A) return_type function_name()", "B) function_name return_type()", "C) return_type : function_name", "D) None of the above"},
        {"A) malloc", "B) new", "C) calloc", "D) realloc"},
        {"A) Overloading", "B) Abstraction", "C) Encapsulation", "D) Inheritance"},
        {"A) Access modifiers", "B) Functions", "C) Data members", "D) None of the above"},
        {"A) Both are the same", "B) '==' checks equality; '=' assigns value", "C) '=' checks equality; '==' assigns value", "D) None of the above"},
        {"A) +", "B) =", "C) ::", "D) ->"}
    },
    { // Difficult Choices
        {"A) Enables runtime polymorphism", "B) Provides compile-time abstraction", "C) Optimizes memory usage", "D) None of the above"},
        {"A) Derived to Base", "B) Base to Derived", "C) Random", "D) None of the above"},
        {"A) Compile-time error", "B) Runtime error", "C) Undefined behavior", "D) None of the above"},
        {"A) 4 bytes", "B) 8 bytes", "C) Depends on architecture", "D) None of the above"},
        {"A) By declaring as final", "B) By using private inheritance", "C) By using protected inheritance", "D) None of the above"},
        {"A) Manages memory", "B) Handles exceptions", "C) Prevents segmentation fault", "D) None of the above"},
        {"A) Variable is thread-safe", "B) Variable can change unexpectedly", "C) Variable is constant", "D) None of the above"},
        {"A) 'delete' releases single object; 'delete[]' releases array", "B) 'delete[]' releases single object; 'delete' releases array", "C) Both are the same", "D) None of the above"},
        {"A) Resource Acquisition Is Initialization", "B) Resource Allocation Is Implementation", "C) Runtime Allocation of Instance", "D) None of the above"},
        {"A) dynamic_cast", "B) reinterpret_cast", "C) const_cast", "D) static_cast"}
    }
};

char answers[3][10] = {
    {'C', 'A', 'B', 'D', 'A', 'D', 'C', 'A', 'D', 'D'}, // Easy answers
    {'A', 'A', 'B', 'A', 'A', 'B', 'A', 'A', 'B', 'C'}, // Intermediate answers
    {'A', 'A', 'A', 'C', 'A', 'A', 'B', 'A', 'A', 'B'}  // Difficult answers
};

// Function to clear the screen
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Validates user input for difficulty
int getDifficulty() {
    int difficulty;
    while (true) {
        cout << "Choose difficulty level:\n"
             << "1) Easy\n2) Intermediate\n3) Difficult\n"
             << "Your choice: ";
        cin >> difficulty;

        if (cin.fail() || difficulty < 1 || difficulty > 3) {
            cout << "Invalid input! Please select 1, 2, or 3.\n" << endl;
            cin.clear();
        } else {
            return difficulty - 1;
        }
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        clearScreen();
    }
}

// Validates user input for quiz answers
char getAnswer() {
    char answer;
    while (true) {
        cout << "\nYour answer (A, B, C, D): ";
        cin >> answer;
        answer = toupper(answer);

        if (answer >= 'A' && answer <= 'D') {
            return answer;
        } else {
            cout << "Invalid input! Please enter A, B, C, or D.\n";
        }
    }
}

// Starts the quiz
void startQuiz(int difficulty) {
    clearScreen();
    int score = 0;

    for (int i = 0; i < 10; ++i) {
        clearScreen();
        cout << "+-------------------------------------------------------+\n"
             << "                        C++ QUIZ GAME\n"
             << "+-------------------------------------------------------+\n"
             << "Question " << i + 1 << ": " << questions[difficulty][i] << "\n";
        for (int j = 0; j < 4; ++j) {
            cout << choices[difficulty][i][j] << "\n";
        }
        char userAnswer = getAnswer();

        if (userAnswer == answers[difficulty][i]) {
            cout << "Correct!\n";
            ++score;
        } else {
            cout << "Wrong! The correct answer was: " << answers[difficulty][i] << "\n";
        }
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    clearScreen();
    cout << "Quiz complete! Your final score is: " << score << "/10\n";
    if (score >= 7) {
        cout << "\n+-------------------------------------------------------+\n"
             << "                Great job! You passed!\n"
             << "+-------------------------------------------------------+\n";
    } else {
        cout << "\n+-------------------------------------------------------+\n"
             << "                Better luck next time!\n"
             << "+-------------------------------------------------------+\n";
    }
}

// Gets username and ensures it is valid
string getUsername() {
    string username;
    while (true) {
        cout << "Enter your username: ";
        getline(cin, username);

        if (!username.empty()) {
            return username;
        } else {
            cout << "Username cannot be empty. Please try again.\n";
        }
    }
}

int main() {
    char rp;
    cout << "+-------------------------------------------------------+\n"
         << "                        C++ QUIZ GAME\n"
         << "+-------------------------------------------------------+\n";

    string username = getUsername();

    do{
        clearScreen();
        cout << "+-------------------------------------------------------+\n"
             << "                        C++ QUIZ GAME\n"
             << "+-------------------------------------------------------+\n";

        cout << "Welcome, " << username << "!\n\n";
        int difficulty = getDifficulty();
        startQuiz(difficulty);

        cout << "\nDo you want to take a quiz again?(y/n): ";
        cin >> rp;
    }while(rp=='y' || rp=='Y');

    clearScreen();
    cout << "+-------------------------------------------------------+\n"
         << "                You did well. Keep it up!\n"
         << "+-------------------------------------------------------+\n";

    return 0;
}