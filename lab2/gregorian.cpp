#include "gregorian.h"

using namespace std;

const int MONTHS_PER_YEAR = 12;
const int DAYS_PER_WEEK = 7;
enum Month_days {january=31,february=28,march=31,april=30,may=31,june=30,july=31,august=31,september=30,october=31,november=30,december=31};

lab2::Gregorian::Gregorian(){
    #ifdef DEBUG
    cout << "in Gregorian()" << endl;
    #endif

    setCurrentDate();
};

lab2::Gregorian::Gregorian(int year,int month,int day):Date(year,month,day){
    #ifdef DEBUG
    cout << "in Gregorian(int,int,int): "<< endl;
    #endif

    if(isDateOutOfRange() ){
        throw out_of_range("OOR!");
    }
};

lab2::Gregorian::Gregorian(const Date& d) {
    #ifdef DEBUG
    cout << "in Gregorian(const Date&): "<<endl;
    #endif
    _year = d.year();
    _month = d.month();
    _day = d.day();
    *this += (d.mod_julian_day() - this->mod_julian_day() ); //convert from arbitrary Date class(e.g. Julian) to Gregorian
};

lab2::Gregorian::Gregorian(const Date* d) {
    #ifdef DEBUG
    cout << "in Gregorian(const Date*): "<<endl;
    #endif
    _year = d->year();
    _month = d->month();
    _day = d->day();
    *this += (d->mod_julian_day() - this->mod_julian_day() );
};

lab2::Gregorian::~Gregorian(){};

lab2::Gregorian& lab2::Gregorian::operator=(const Date& d){
    #ifdef DEBUG
    cout<<"in Gregorian::operator="<< endl;
    #endif
    if(this != &d){ //to avoid self assignment
        _year = d.year();
        _month = d.month();
        _day = d.day();
        #ifdef DEBUG
        cout << "The difference is " << d.mod_julian_day() - this->mod_julian_day() << " days" << endl;
        #endif

        *this += ( d.mod_julian_day() - this->mod_julian_day() ); //convert to Gregorian

        #ifdef DEBUG
        cout << "The difference after adjusting to the calendar: " << d.mod_julian_day() - this->mod_julian_day() << " days (must be =0)" << endl;
        #endif
    }
    return *this;
};

void lab2::Gregorian::setCurrentDate(){

    time_t mytime; //used for both debug and not debug

    #ifdef DEBUG
    //manually set the kattistime(kattis will handle this later)
    time(&mytime);
    set_k_time(mytime);
    #endif



    k_time(&mytime);

    // För att få ut datum lokalt
    struct tm *t = gmtime(&mytime);
    _year  = t->tm_year + 1900;
    _month = t->tm_mon + 1;      // månaderna och dagarna
    _day   = t->tm_mday;         // indexerade från ETT


  //  time_t rawtime;
 //   struct tm * timeinfo;

 //   time ( &rawtime );
 //   k_time(&rawtime);

 //   timeinfo = localtime(&rawtime);
 //   _year = 1900+timeinfo->tm_year;
 //   _month = 1+timeinfo->tm_mon;
 //   _day = timeinfo->tm_mday;



    #ifndef DEBUG
        //code for kattis get_time

        //TODO make kattis know the time

    #else
        //local code to get_time
        //http://www.utas.edu.au/infosys/info/documentation/C/CStdLib.html#time.h

        //cout << "in Gregorian::setCurrentTime()" << endl;

        //gets the current Gregorian time


    #endif
};

int lab2::Gregorian::week_day() const{
    int mjd_010101 = -678575;
    return (mod_julian_day() - mjd_010101 )% 7 + 1; //since mod_julian_day is negative for dates before Gregorian(1858-11-17) we use an early monday (in this case 01-01-01) as a reference
};

const int lab2::Gregorian::days_per_week() const{
    return DAYS_PER_WEEK;
};

const int lab2::Gregorian::months_per_year() const{
    return MONTHS_PER_YEAR;
};

string lab2::Gregorian::week_day_name() const{
    switch( week_day() ){
        case 1: return "monday";
        case 2: return "tuesday";
        case 3: return "wednesday";
        case 4: return "thursday";
        case 5: return "friday";
        case 6: return "saturday";
        case 7: return "sunday";
        default: cerr << "not a week day" << endl; return "not_a_weekday!!1";
    }
};

string lab2::Gregorian::month_name() const{
    switch(_month){
        case 1: return "january";
        case 2: return "february";
        case 3: return "march";
        case 4: return "april";
        case 5: return "may";
        case 6: return "june";
        case 7: return "july";
        case 8: return "august";
        case 9: return "september";
        case 10: return "october";
        case 11: return "november";
        case 12: return "december";
        default: cerr << "not a month" << endl;return "not_a_month!!1";
    }
};

int lab2::Gregorian::days_this_month() const{
    switch(_month){
        case 1: return Month_days(january);
	    case 2: if(leap_year())
			        return Month_days(february) + 1;
		        else
			        return Month_days(february);
	    case 3: return Month_days(march);
	    case 4: return Month_days(april);
	    case 5: return Month_days(may);
	    case 6: return Month_days(june);
	    case 7: return Month_days(july);
	    case 8: return Month_days(august);
	    case 9: return Month_days(september);
	    case 10: return Month_days(october);
	    case 11: return Month_days(november);
	    case 12: return Month_days(december);
        default: cerr << "not a month" << endl; return -1;
    }
};

int lab2::Gregorian::month_jump() const{
    return 30;
};


/*
*  Dubbel checkad och tar fram mod_julian_day()=0 rätt
*
*
*/

/*int lab2::Gregorian::mod_julian_day() const{ // valid for year >= 0
//http://scienceworld.wolfram.com/astronomy/GregorianCalendar.html

    //double ??
    float jd = 367.0f*(float)_year - floor( 7.0f*( (float)_year + floor((float)(_month+9)/12.0f)) / 4.0f ) - floor(3.0f*( floor( ((float)_year + (float)(_month-9)/7.0f) /100.0f) +1.0f)/4.0f) + floor(275.0f/9.0f*(float)_month) + (float)_day + 1721028.5;
    
	return (int)floor(jd-2400000.5f);
	
    //fulfix (för att rätta till)
    //gregorian 2200 06 11
    //gregorian 2101 1 6
    //gregorian 2488 2 29

add_month 9
add_month 261
copy away 261 445
copy 261* 445
add_year
add_year 261
add_month -5
add_month 261
add_year 9
add_year 261
add_month
add_month 261
d-- 261
d+= -3
d+= 261
d++ 261
copy 261 185
copy 261 185*
add_year
add_year 185
add_month -1
add_month 185
d-- 185
add_year
add_year 185
year 185
day 185
month 185


*/

int lab2::Gregorian::mod_julian_day() const{ //valid for _year >= -4800

    int a;
    int y;
    int m;
    int jdn; // julian day number
    a = (14-_month) / 12;
    y = _year + 4800 - a;
    m = _month + 12*a - 3;
    //http://en.wikipedia.org/wiki/Julian_day
    jdn = _day + (153*m + 2) / 5 + 365*y + y/4 - y/100 + y/400 - 32045;
    float mjd = jdn - 2400000.5;

    return (floor(mjd));
};

bool lab2::Gregorian::leap_year() const {
    return( _year%400 == 0 || (_year%4 == 0 && _year%100 != 0) );
};


