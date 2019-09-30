//  Dugga2, created in xCode.
//  Johan Sten, 9704148734


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main ()

{
    //Declaring the variables needed for the first loop to function as we wish, if the user enters non valid input the executes again.
    int half_side = 0;
    int radius = 0;
    int max_side = 5;
    bool invalid_input = false;
    //Asking for user input
    do {
        cout << "Radius: " << endl;
        cin >> radius;
        cout << "Length: " << endl;
        cin >> half_side;
        invalid_input = (radius <= max_side  || half_side <= max_side);
        
        if (invalid_input)
        {
            cout << "Not valid input!!" << endl;
        }
        
    } while (invalid_input);
    //Declaring our first arrays, one for the x-axis along with one for the y-axis.
    //Since the assignment does not state the size of each array, I interpretated that a size of maximum 100 slots should be enough.
    constexpr int SIZE = 100;
    int a = 0;
    int x[SIZE] = { 0 };
    int y[SIZE] = { 0 };
    
    //Ask for user input
    cout << "Enter the points: " << endl;
    //Declaring the variables to put in the array aswell as the "i" for our further loops.
    int kappa_x = 0;
    int delta_y = 0;
    int i = 0;
    //While the users enters the coordinates. The for-loop along with the if-statements checks each set of data to exclude duplicates along with points outside of the square.
    while ((cin >> kappa_x  >> delta_y) && a < SIZE)
    {
        for (i = 0; i < a; i++)
        {
            if (kappa_x == x[i] && delta_y == y[i]) {
                break;
            }
        }
        
        if ((kappa_x > half_side) || (kappa_x < -half_side) || ((delta_y > half_side) || (delta_y < -half_side)  ))
        {
            
        }
        else if (i == a) {
            x[a] = kappa_x;
            y[a] = delta_y;
            
            a = a + 1;
        }
    }
    
    // Declaring the variable for the distance from each points to origo, along with our new array which stores the points as a value of the distance to origo. i.e "distance_from_zero".
    double distance_from_zero = 0.0;
    double sorted_list[SIZE] = { 0.0 };
    
    
    //Loop through the array, checking if the value is outside or inside the circle. The distance from each point to origo is also stored in the array "sorted_list".
    for (i = 0; i < a; ++i)
    {
        distance_from_zero = sqrt((x[i] * x[i] + (y[i] * y[i])));
        
        if (sqrt((x[i] * x[i]) + (y[i] * y[i])) < radius)
        {
            cout << "(" << x[i] << "," << y[i] << ")" << "in the circle." << endl;
            sorted_list[i] = distance_from_zero;
        }
        else {
            
            cout << "(" << x[i] << "," << y[i] << ")" << "NOT in the circle!" << endl;
            sorted_list[i] = distance_from_zero;
        }
        
    }
    
    //Sort the new array "sorted_list", making it easier to calculate the median. 
    for (int pass = 1; pass <= a - 1; ++pass)
    {
        for (int i = 0; i < a - 1; ++i)
        {
            if (sorted_list[i] > sorted_list[i + 1])
            {
                double temp_value = sorted_list[i];
                sorted_list[i] = sorted_list[i + 1];
                sorted_list[i + 1] = temp_value;
            }
        }
    }
    //Declaring the variables for calculating the median.
    double even_median = 0.0;
    int value_odd = 0;
    int value_even = 0;
    
    //Formula for separating when the amount of values are even/odd, i.e 2 values in the middle which needs counting.
    value_odd = (a / 2);
    value_even = value_odd - 1;
    even_median = (sorted_list[value_odd] + sorted_list[value_even]) / 2;
    
    //If amount of values are even, display the calculated "even_median"
    if (a % 2 == 0)
    {
        cout << "Median distance to point (0,0): "
        << fixed << setprecision(2) << even_median;
    }
    //If not even, display the middle number divided by two. E.g "value_odd"
    else
    {
        cout << "Median distance to point (0,0): "
        << fixed << setprecision(2) << sorted_list[value_odd];
    }
    
    
    return 0;
}
