#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cmath>


using namespace std;

int a; // determines the structure of the equation
int i;
int c;
double sumco;
double dsumco;
double Lsumco;
double Fsumco;
double coeff[1000];
double dcoeff[1000];
double Lcoeff[1000];
double Fcoeff[1000];
double Leqsol;
double Feqsol;
double eqsol;
double deqsol;
double par = 0;
double res1;
double res2;
double FinF;
double FinFprime;
double check;
int flx;
int dx;
int dx2;
double guess;
double nrm0;
double nrm1;
double DerivF;
int Var[1000];
int Deriv[1000];
char oper[1000];
char operC[1000];


int GetConst()
{
    cin >>  c;
    cout << "Enter operator: ";
    cin >> operC;
    cout << endl;
}

int GetEq()
{
    for ( i = a; i >= 1; i-- )
    {
        if (i > 1)
        {
            cout << "\n";
            cout << "x^[" << i << "]: " ;
            cin >> Var[i];
            cout << "Enter operator: ";
            cin >> oper[i];
            cout << "==================\n";

        }

        else if (i == 1)
        {
            cout << "\n";
            cout << "x: " ;
            cin >> Var[i];
            cout << "Enter operator: ";
            cin >> oper[i];
            cout << "==================\n";
        }
    }

}

int DisplayEq()
{
  for (int fla = a, flx = a; fla >= 1, flx >= 1; fla--, flx--)
  {
      cout << oper[fla] << " ";
      cout << Var[fla] << "x^" << fla << " ";
  }






    cout << operC << " ";
    cout << c;
}

int DisplayDeriv()
{
  for (int flb = a, flx = a-1; flb >= 1, flx >= 0; flb--, flx--)
  {
      Deriv[flb] = Var[flb];
      Deriv[flb] *= flb;
      cout << oper[flb] << " ";
      cout << Deriv[flb] << "x^" << flx << " ";
  }
}

int Solve()
{

    cout << "\n\n\tSolve" << endl;

    for (int sol = a; sol >= 1; sol--)
    {
        coeff[sol] = Var[sol];
        double expro = pow(guess, sol);
        coeff[sol] *= expro;
        sumco += coeff[sol];
        eqsol = sumco + c;


        cout << "\nCoefficient > " << Var[sol] << " | x0 > " << guess << " | Coeff * Guess^expo > " << coeff[sol] << " | expo > " << sol << " | [x0]^expo > " << expro << " | C > " << c << " | partial > " << sumco << " | full > " << eqsol << endl;




    }
}

int SolveDeriv()
{
    cout << "\n\n\tSolveDeriv()"<< endl;
    for (int sd = a, dx = a - 1; sd >= 2, dx >= 1; sd--, dx--)
    {

        dcoeff[sd] = Deriv[sd];
        double dexpro = pow(guess, dx);
        dcoeff[sd] *= dexpro;
        dsumco += dcoeff[sd];
        deqsol = dsumco + Deriv[1];



        cout << "\nCounter > " << sd << " | Coefficient > " << Deriv[sd] << " | x0 > " << guess << " | Coeff * Guess^expo > " << dcoeff[sd] << " | expo > " << dx << " | [Guess]^expo > " << dexpro << " | full > " << deqsol << " | Deriv[1] >" << Deriv[1] << endl;




    }

}

int SolveNRMInitial()
{

    nrm0 = eqsol / deqsol;
    nrm1 = guess - nrm0;


    cout << "\n\n\t\t you're in SolveNRMInitial() " << " \nDerivative Sub > " << DerivF << " | f(x) / f'(x) > " << nrm0 << " | First iteration > " << nrm1 << endl;
}

int f()
{
    for (int svi = a; svi >= 1; svi--)
        {
            Lcoeff[svi] = Var[svi];
            double Lexpro = pow(guess, svi);
            Lcoeff[svi] *= Lexpro;
            Lsumco += Lcoeff[svi];
            Leqsol = Lsumco + c;


            if ( svi == 1)
            {
                Lsumco = 0;
                FinF = Leqsol;


            }

        }
        return 0;

}

int fprime()
{
    for (int svi2 = a, dx2 = a - 1; svi2 >= 2, dx2 >= 1; svi2--, dx2--)
        {
            Fcoeff[svi2] = Deriv[svi2];
            double Fexpro = pow(guess, dx2);
            Fcoeff[svi2] *= Fexpro;
            Fsumco += Fcoeff[svi2];
            Feqsol = Fsumco + Deriv[1];


            if ( svi2 == 2 )
            {
                Fsumco = 0;
                FinFprime = Feqsol;



            }


        }
        return 0;
}

int SolveIterations()
{
    guess = nrm1;
    double guessiter = 0;
    int stopper;
    int fli = 2;
    do
        {
            f();
            cout << "\n\t\t +  \n" << endl;
            fprime();

            par = FinF / FinFprime;
            check = guess;
            guessiter = guess - par;
            guess = guessiter;
            stopper = guessiter / check;



            cout << "\n\n\n\t\t Iteration > " << fli << " | F(x) > " << FinF << " | F'(x) > " << FinFprime << " | F(x) / F'(x) > " << par <<" | Full > " << guessiter << " | check > " << check << endl;
            cout << "\n";
            fli++;

        } while ( stopper == 0 );


}

int main()
{

    cout << "Newton's Raphson Method Calculator \n" << endl;
    cout << "----------------------------------------\n";



    cout << "Please input the Highest Exponent in the equation. \n" << endl;
    cin >> a;
    cout << "\nThe Highest Exponent is: [" << a  << "]" << endl;
    cout << "\nThe Coefficients are:" << endl;

    GetEq();


    cout << "\n\nand the Constant is\nC: ";

    GetConst();

    cout << "\nThe Formula is f(x) = ";

    DisplayEq();

    cout << "\nPlease input guess number:";
    cin >> guess;
    cout << "\nGuess Number is: [" << guess << "]" << endl;

    Solve();

    DisplayDeriv();

    SolveDeriv();

    cout << "\n\tF(xn) = " << eqsol << endl;
    cout << "\n\tF'(xn) = " << deqsol << endl;

    SolveNRMInitial();

    SolveIterations();












}
