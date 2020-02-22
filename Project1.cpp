/*
Elijah Stultz
CISP 400 - MW 3:00PM
Programming Project 1
February 9, 2020
*/

#include <iostream>
using namespace std;

typedef unsigned Date;
enum DATE_STYLE {MM_DD_YYYY, MON_DD_YYYY};

unsigned numDigits ( unsigned num );
int nthDigit ( unsigned num, unsigned nth );
Date makeDate ( unsigned m, unsigned d, unsigned y );
void displayDate ( const Date& date, ostream& = cout, DATE_STYLE = MM_DD_YYYY );
Date incrementDate ( const Date& date );
bool wellFormed ( const Date& date );
unsigned month ( const Date& date );
unsigned day ( const Date& date );
unsigned year ( const Date& date );
bool isLeapYear ( const Date& date );
unsigned monthLength ( const Date& date );
bool lessThan ( const Date& date1, const Date& date2 );
bool isPalindrome ( const Date& date );

//January equals 1, February equals 2, and so on
enum MONTH {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

const Date MIN_DATE = 1010001, MAX_DATE = 12319999;
const unsigned DAY = 10000, MONTH = 1000000, YEAR = 1000;
const string ERR_MSG = "\nError: date is not valid.\n";
const int BASE_TEN = 10;

int main()
{
  Date i;

  for ( i=1010001; lessThan(i,12316000); )
 {
   if ( isPalindrome(i) )
   {
     displayDate(i,cout,MM_DD_YYYY);
     cout <<" is a palindrome" << endl;
   }
    i = incrementDate(i);
 }

  return 0;
}

unsigned numDigits ( unsigned num )
{
  if (num < BASE_TEN) return 1;
  return 1 + numDigits(num / BASE_TEN);
}

//gives a digit's "nths" place
int nthDigit ( unsigned num, unsigned nth )
{

  int index = -1, divisor = BASE_TEN;

  if (nth <= numDigits(num))
  {
    for (unsigned i = 0; i < nth; i++) divisor *= BASE_TEN;
    index = (num % divisor) / (divisor / BASE_TEN);
  }
  return index;
}

Date makeDate ( unsigned m, unsigned d, unsigned y )
{
  Date newDate;

  m *= MONTH;
  d *= DAY;

  newDate = m + d + y;

  return newDate;
}

void displayDate ( const Date& date, ostream& ostr, DATE_STYLE dStyle )
{
  string mon, zero = "0";

  const unsigned dtM = month(date), dtD = day(date), dtY = year(date);

  int zeroCounter = 0, i = numDigits(YEAR);

  //counts how many zeros to print later on - years 0001-0009 gives 3, 0010-0099 2, etc
  while (i > numDigits(dtY))
  {
      zeroCounter++;
      i--;
  }

  if (!wellFormed(date)) ostr << ERR_MSG;
  {
    if (dStyle == MM_DD_YYYY)
    {
      //prints out a 0 before any month or day less than 10
      if (dtM < BASE_TEN) ostr << zero << dtM;
      else ostr << dtM;

      ostr << "/";

      if (dtD < BASE_TEN) ostr << zero << dtD;
      else ostr << dtD;

      ostr << "/";

      for (i = 0; i < zeroCounter; i++) cout << zero;

      ostr << dtY;

      ostr << endl;
    }
    else
    {
      switch(dtM)
      {
        case JAN:
          mon = "Jan";
          break;
        case FEB:
          mon = "Feb";
          break;
        case MAR:
          mon = "Mar";
          break;
        case APR:
          mon = "Apr";
          break;
        case MAY:
          mon = "May";
          break;
        case JUN:
          mon = "Jun";
          break;
        case JUL:
          mon = "Jul";
          break;
        case AUG:
          mon = "Aug";
          break;
        case SEP:
          mon = "Sep";
          break;
        case OCT:
          mon = "Oct";
          break;
        case NOV:
          mon = "Nov";
          break;
        default:
          mon = "Dec";
      }

      //formatted as MON DD, YYYY
      ostr << mon << " ";

      if (dtD < BASE_TEN) ostr << zero << dtD;
      else ostr << dtD;

      ostr << ", ";

      for (i = 0; i < zeroCounter; i++) cout << zero;

      ostr << dtY;
    }
  }
}

Date incrementDate ( const Date& date )
{
  const unsigned dtM = month(date), dtD = day(date), dtY = year(date), dtMLen = monthLength(date);

  Date newDate = makeDate(dtM, dtD, dtY);

  if (!wellFormed(date)) cout << ERR_MSG;
  else
  {
    //date goes back to 01/01 or Jan 01 and adds 1 to the year, aka new year
    if (dtM == DEC && dtD == dtMLen)
    {
      newDate -= (dtM - 1) * MONTH + (dtMLen - 1) * DAY;
      newDate += 1;
    }
    //day goes back to 01 and month increases by 1
    else if (dtD == dtMLen)
    {
      newDate -= (dtMLen - 1) * DAY;
      newDate += MONTH;
    }
    else newDate += DAY;
  }
  return newDate;
}

bool wellFormed ( const Date& date )
{
  bool isWellFormed = false;

  if (date >= MIN_DATE && date <= MAX_DATE)
  {
    isWellFormed = true;
  }

  return isWellFormed;
}

unsigned month ( const Date& date )
{
  if (!wellFormed(date)) cout << ERR_MSG;
  else return date / MONTH;
}

unsigned day( const Date& date )
{
  if (!wellFormed(date)) cout << ERR_MSG;
  else return (date % MONTH) / DAY;
}

unsigned year ( const Date& date )
{
  if (!wellFormed(date)) cout << ERR_MSG;
  else return date % DAY;
}

bool isLeapYear ( const Date& date )
{
  bool leapYear = false;

  if (wellFormed(date))
  {
    if (date % 100 == 0)
    {
      if (date % 400 == 0) leapYear = true;
    }
    else if (date % 4 == 0) leapYear = true;
  }
  else cout << ERR_MSG;

  return leapYear;
}

unsigned monthLength ( const Date& date )
{
  unsigned daysInMonth;
  const unsigned dateMonthNum = month(date);

  if (wellFormed(date))
  {
    //february has 28 days except for leap years in which it has 29 instead
    if (dateMonthNum == FEB)
    {
      if (isLeapYear(date)) daysInMonth = 29;
      else daysInMonth = 28;
    }
    //Months with 30 days
    else if (dateMonthNum == APR || dateMonthNum == JUN || dateMonthNum == SEP || dateMonthNum == NOV)
    {
      daysInMonth = 30;
    }
    else daysInMonth = 31;
  }
  else cout << ERR_MSG;

  return daysInMonth;
}

//compares two dates and returns true if date1 comes earlier than date2
bool lessThan( const Date& date1, const Date& date2 )
{
  bool isLessThan = false;

  const unsigned sumDate1 = day(date1) + month(date1) + year(date1);
  const unsigned sumDate2 = day(date2) + month(date2) + year(date2);

  if (wellFormed(date1) && wellFormed(date2))
  {
    if (sumDate1 < sumDate2) isLessThan = true;
  }
  else cout << ERR_MSG;

  return isLessThan;
}

bool isPalindrome ( const Date& date )
{
  bool isPal = false;
  const unsigned dtM = month(date), dtY = year(date);

  int i, k = 0;

  if (wellFormed(date))
  {
    //minus one because numDigits doesn't return index
    i = numDigits(date) - 1;

    //skips the trailing zero in years like 2020 due to the leading zero not being stored
    if (dtM < BASE_TEN)
    {
      if (nthDigit(date, k) == 0)
      {
        isPal = true;
        k++;
      }
    }
    else if (nthDigit(date, i) == nthDigit(date, k)) isPal = true;

    while (i > k && isPal)
    {
      if (nthDigit(date, i) != nthDigit(date, k)) isPal = false;

      i--;
      k++;
    }
  }
  else cout << ERR_MSG;

  return isPal;
}
