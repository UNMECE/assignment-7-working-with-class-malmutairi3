#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

 // this is electric field class
class Electric_Field {
private:
    double *E;

public:
    // this is default  ructor
    Electric_Field() {
        E = new double[3]{0.0, 0.0, 0.0};
    }

    // it is parameteric  ructor
    Electric_Field(double x, double y, double z) {
        E = new double[3]{x, y, z};
    }

    // this is destructor to free memory
    ~Electric_Field() {
        delete[] E;
    }

    // setter functions
    void set_X(double x) { 
        E[0] = x; 
    }
    void set_Y(double y) { 
        E[1] = y; 
    }
    void set_Z(double z) 
    { 
        E[2] = z; 
    }

    // getters
    double get_X()   { 
        return E[0]; 
    }
    double get_Y()   { 
        return E[1]; 
    }
    double get_Z()    { 
        return E[2] ;  
    }

    
    double calculateMagnitude()   {
        double squareRoot;
        squareRoot = sqrt( E[0] *E[0] + E[1]*E[1] + E[2]*E[2]);
        return squareRoot ;
    }

     
    double calculateInnerProduct()   {
        double innerProduct = E[0]* E[0] + E[1] *E[1] + E[2]*E[2];
        return innerProduct;
    }

    
    void printField()   {
        cout << "Electric Field (E): [" ;
        cout << E[0] << ", " << E[1] << ", " << E[2] << "]" << endl;
    }
};

 
class Magnetic_Field {
private:
    double *B;

public:
    
    Magnetic_Field() {
        B = new double[3]{0.0, 0.0, 0.0};
    }

     
    Magnetic_Field(double x, double y, double z) {
        B = new double[3]{x,  y, z};
    }

     
    ~Magnetic_Field() {
        delete[] B;
    }

     
    void set_X(double x) { B[0] = x; }
    void set_Y(double y) { B[1] = y; }
    void set_Z(double z) { B[2] = z; }

    // getters
    double get_X()   { return B[0]; }
    double get_Y()   { return B[1]; }
    double get_Z()   { return B[2]; }

    
    double calculateMagnitude()   {
        double mag = sqrt(B[0]* B[ 0] + B[1]*B[1] + B[2]*B[2] ) ;
        return mag;
    }

    
    void calculateUnitVector()   {
        double mag = calculateMagnitude();
        if (mag == 0 ) 
        {
            cout << "magnetic field is zero vector no unit vector defined." << endl;
        } 
        else 
        {
            cout << fixed << setprecision(3);
            cout << "Unit vector of Magnetic Field (B): [";
            cout     << B[0]/mag << ", " << B[1]/mag << ", " << B[2]/mag << "]" << endl;
        }
    }

    
    void printField()  
    {
        cout << "Magnetic Field (B): ["; 
        cout << B[0] << ", " << B[1] << ", " << B[2] << "]" << endl;
    }
};


int main() {
    // by using default  ructor
    Electric_Field E_default;
    Magnetic_Field B_default;

    // ny using parameterized  ructor
    Electric_Field E_components(1e5, 10.9, 1.7e2);
    Magnetic_Field B_components(3.5, 4.2, 1.1);

    // by using setters
    E_default.set_X(2.0);
    E_default.set_Y(4.0);
    E_default.set_Z(1.0);

    B_default.set_X(0.1);
    B_default.set_Y(0.2);
    B_default.set_Z(0.3);

     
    cout << "----- Electric Fields -----" << endl;
    E_default.printField();
    E_components.printField();
    cout << "Magnitude of E_default: " << E_default.calculateMagnitude() << endl;
    cout << "Magnitude of E_components: " << E_components.calculateMagnitude() << endl;
    cout << "Inner product of E_components: " << E_components.calculateInnerProduct() << endl;

    cout << "\n----- Magnetic Fields -----" << endl;
    B_default.printField();
    B_components.printField();
    cout << "Magnitude of B_default: " <<  B_default.calculateMagnitude()  << endl;
    cout <<  "Magnitude of B_components: " << B_components.calculateMagnitude()  <<  endl;
      B_components.calculateUnitVector();

    return 0;
}
