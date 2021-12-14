#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
# define PI           3.14159265358979323846



void task1(char &letter){

        if (isupper(letter) || islower(letter)){
            letter = letter;
        }
        else {
            letter = 95;
        }


}




int calculate_trig_from_series(double x, int z, double &sin, double &cos){
    x = 1.0*x*PI/180;
    int fact1 = 1, fact2 = 1;

for (int n=z; n>0; n--){
    for(int i=1; i<=(2*n+1); i++){
      fact1 = fact1 * i;}

    for(int i=1; i<=(2*n); i++){
      fact2 = fact2 * i;}

    sin += (pow(-1, n)*pow(x, 2*n+1))/fact1;

    cos += (pow(-1, n)*pow(x, 2*n))/fact2;

}
}
double polynomial(double coefs[],int n, int x){
    int p=n-1, sum=0;
    for (int i = 0; i<4; i++){
        coefs[i] = coefs[i]*pow(x,p);
        p--;
    }
    for(int i = 0; i<4 ; i++){
          sum+=coefs[i];
       }
    return sum;
}




int mean(int arr[]){
    int sum=0, mean;
    for(int i = 0; i<100 ; i++){
          sum+=arr[i];
       }
    mean = sum/100;
    return mean;
}




int main(){

    int task = 0, exit = 1;

     while (exit == 1) {
    std::cout << "Select task or exit with 0" << std::endl;
    std::cin >> task;

    switch (task){


    case 1: {
            char text[20];
            std::cout << "Enter text with symbols: " << std::endl;
            std::cin >> text;
            std::cout<<std::endl;
            for (int i=0; i<strlen(text); i++ ){
            task1 (text[i]);
            std::cout<< text[i];}
            std::cout<<std::endl;
            break;
        }


    case 2: {
            int  precision;
            double value, sin = 0, cos = 0;
    std::cout << "enter a value";
    std::cin >> value;
    std::cout << std::endl;
    std::cout << "enter precision";
    std::cin >> precision;
    std::cout<<std::endl;
    calculate_trig_from_series(value, precision, sin, cos);
    std::cout << "sin_val = " << sin << ' ' << "cos_val = " << cos  << std::endl;
    break;
    }


    case 3: {
            // f(x) = -3x^3 + 2x^2 – 3x + 5 // f(2) = - 17
            double coefs[4] = {-3, 2, -3, 5};
            int n = 4;
            double x = 2;
            std::cout << polynomial(coefs, n, x) << std::endl;
            break;
        }


    case 4: {
            srand(time(nullptr));
            int arr[100];
            for (int i = 0; i<100; i++){
                arr[i] = rand() % 100 + 50;
            }
            std::cout << mean(arr) << std::endl;
            break;
        }


    case 0: {
        std::cout << "goodbye" << std::endl;
        exit = 0;
        break;
        }
    default: {
            std::cout << "there is no such task" << std::endl;
        }
     }}}


