#ifndef sale_h
#define sale_h

namespace SALES
{
    const int QUARTERS = 4;
    class Sales
    {
    private:
        double sales[QUARTERS];
        double avg;
        double max;
        double min;
    public:
        Sales() {sales[0]=0; avg=0; max=0; min=0;}; // default constructor
        Sales(const double ar[], int n); // constructor
        ~Sales();
        void setSales();
        void showSales();
    };
}

#endif