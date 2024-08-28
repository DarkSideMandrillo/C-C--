// Section 19
// stringstreams
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>

int main() {
    int num{};
    double total{};
    std::string name{};
    
    std::string info {"Moe 100 1234.5"}; 
    std::istringstream iss {info};// inizializzo'oggetto istringstream (lettura) la stringa info
    
    iss >> name  >> num >>  total; // estraggo come se fosse un file (quindi lo spazio è la fine di una parola)
    std::cout << std::setw(10) << std::left << name  
                   << std::setw(5) << num
                   << std::setw(10) << total << std::endl;
    
    std::cout << "\n---------------------------------------" << std::endl;
    
    std::ostringstream oss {}; // Dichiaro l'oggetto ostringstream (scrittura)
    oss << std::setw(10) << std::left << name 
          << std::setw(5) << num
          << std::setw(10) << total << std::endl;  //Assegno con la spaziatura diverse stringhe
    std::cout << oss.str() << std::endl; // stampo l'oggetto ostringstream
    
    
    std::cout << "\n--- Data validation ------------------------------------" << std::endl;
    
    int value{};
    std::string entry {};
    bool done = false;
    do {
        std::cout << "Please enter an integer: ";
        std::cin >> entry;
        std::istringstream validator {entry}; 
        if (validator >> value)  // Assegno l'oggetto istream a una variabile INT - Se non è un int ci sarà un errore e l'IF andrà in false
            done = true;
        else 
            std::cout << "Sorry, that's not an integer" << std::endl;
            
         // discards the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // Cancella il buffer del CIN (se digito in cin-> 12.34 è come se avessi fatto 2 input, perciò al prossimo cin prende la parte dopo il punto)
    } while (!done);
    
    std::cout << "You entered the integer: " << value << std::endl;
    
    std::cout << std::endl;
    return 0;
}

