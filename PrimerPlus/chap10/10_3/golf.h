#ifndef golf_h
#define golf_h

class Golf {
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;
public:
    Golf() {fullname[0] = '\0'; handicap=0;}
    Golf(const char*, int); // constructor
    ~Golf(); //destructor
    void setgolf();
    void Handicap(int);
    void showgolf();
};

#endif
