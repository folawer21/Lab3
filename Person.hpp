#ifndef PERSON_HPP
#define PERSON_HPP
#include <ctime>
#include <string>
class Personid
{
    friend class Person;
private:
    int number;
    int series;
public:
    int Get_number()
    {
        return this->number;
    }
    int Get_series()
    {
        return this->series;
    }
};
class Person
{
private:
    Personid iD;
    char *firstName;
    char *middleName;
    char *lastName;
    time_t birthData;
public:
    Personid Get_iD();
    char *Get_first();
    char *Get_middle();
    char *Get_last();
    char *Get_fullname();
    time_t Get_bday();
};
Personid Person::Get_iD()
{
    return this->iD;
}

char* Person::Get_first()
{
    return this->firstName;
}
char* Person::Get_middle()
{
    return this->middleName;
}
char* Person::Get_last()
{
    return this->lastName;
}
char* Person::Get_fullname()
{
    char *f=Get_first();
    char *m=Get_middle();
    char *l=Get_last();
    int len_f= strlen(f);
    int len_m= strlen(m);
    int len_l= strlen(l);
    int len=len_l+len_m+len_f;
    char *full=new char(len);
    for (int i=0;i<len;i++) {
        if (i < len_f) {
            full[i] = f[i];
        } else {
            if (i - len_f < len_m)
                full[i] = m[i];
            else
                full[i] = l[i];
        }
    }
    return full;
}

time_t Person::Get_bday()
{
    return this->birthData;
}
#endif //PERSON_HPP
