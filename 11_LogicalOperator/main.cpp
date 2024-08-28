/*
not     !
and     &&
or      ||

Precedence ->not->and->or
es: temperature > 100 && is_humid || is_raining
    Prima controlla la temperatura con umidità. Poi fa' l'or

short-circuit evalutazione
expr1 && expr2 && expr3 && expr4
Appena trova un expr non vera si blocca e non controlla le altre


*/

#include <iostream>

using namespace std;

int main() {
    //   Determine is you need to wear a coat based on temperature and wind speed    
    cout << boolalpha;
    

    bool wear_coat {false}; 
    double temperature {};
    int wind_speed {};
    
    const int wind_speed_for_coat { 25 };       // wind over this value requires a coat
    const double temperature_for_coat {45}; // temperature below this value requires a coat
    
    // Require a coat if either wind is too high OR temperature is too low
    cout << "\nEnter the current temperature in (F) :" ;
    cin >> temperature;
    cout << "Enter windspeed in (mph): ";
    cin >> wind_speed;
    
    wear_coat = (temperature < temperature_for_coat || wind_speed > wind_speed_for_coat);
    cout << "Do you need to wear a coat using OR? " << wear_coat << endl;
    
    
    // Require a coat if BOTH the windspeed is too high AND temperature is too low
    wear_coat = (temperature < temperature_for_coat && wind_speed > wind_speed_for_coat);
    cout << "Do you need to wear a coat using AND? " << wear_coat << endl;
    
    
    cout << endl;
    return 0;

}