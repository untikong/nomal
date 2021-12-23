const double EPS = 1e-8, PI = 2 * acos(0.0);
typedef complex<double> P;
namespace std {
    bool operator < (const P& a, const P& b) { return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b); } 
    bool operator == (const P& a, const P& b) { return abs(real(a) - real(b)) < EPS && abs(imag(a) - imag(b)) < EPS; }
    P operator / (const P& a, const double& b) { return P(real(a) / b, imag(a) / b); }
    P operator * (const P& a, const double& b) { return P(real(a) * b, imag(a) * b); }
}
double argument(const P &a, const P &b) { // argument for A->B[-PI,PI]
    double ax = real(a), ay = imag(a), bx = real(b), by = imag(b);
    return atan2(by - ay, bx - ax);
}
//engines
