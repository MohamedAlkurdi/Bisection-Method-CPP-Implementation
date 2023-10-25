#include <iostream>
using namespace std;
const double epsilon = 0.1;
double getValue() {
    double x;
    cin >> x;
    return x;
}
double equation(double x) {
    return pow(x, 2) - 2 * x - 7;
}
double multiply(double x1, double x2) {
    return equation(x1) * equation(x2);
}
double seperateDomain(double x1, double x2) {
    return (x1 + x2) / 2;
}
bool checkError(double x1,double x2) {
    if (abs(equation(x1) - equation(x2)) < epsilon) {
        return false;
    }
    else {
        return true;
    }
}
bool checkRootExistance(double x1,double x2) {
    if (multiply(x1, x2) < 0) {
        return true;
    }
    else {
        return false;
    }
}
int main()
{
    double Low = getValue();
    double High = getValue();

    if (checkRootExistance(Low, High)) {
        do
        {
            double newPoint = seperateDomain(Low, High);
            if (checkRootExistance(newPoint, High)) {
                Low = newPoint;
            }
            else {
                High = newPoint;
            }
        } while (checkError(Low, High));
    }
    else {
        cout << "there is not root in the domain you have entered." << endl;
    }
    cout << "low: " << Low << endl;
    cout << "high: " << High << endl;
    cout << "the point bwetween: " <<seperateDomain(Low,High) << endl;


    return 0;
}
