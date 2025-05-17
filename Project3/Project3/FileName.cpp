#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:

    Time(int h = 0, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    ~Time() {}

    void input() {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;
    }

    void output() const {
        cout << setfill('0') << setw(2) << hours << ":"
            << setw(2) << minutes << ":"
            << setw(2) << seconds << endl;
    }

    bool check() const {
        return (hours >= 0 && hours <= 23 &&
            minutes >= 0 && minutes <= 59 &&
            seconds >= 0 && seconds <= 59);
    }

    Time operator+(const Time& t) const {
        return Time(hours + t.hours, minutes + t.minutes, seconds + t.seconds);
    }

    Time operator-(const Time& t) const {
        int total1 = hours * 3600 + minutes * 60 + seconds;
        int total2 = t.hours * 3600 + t.minutes * 60 + t.seconds;
        int diff = total1 - total2;
        if (diff < 0) diff += 86400;

        int h = diff / 3600;
        int m = (diff % 3600) / 60;
        int s = diff % 60;
        return Time(h, m, s);
    }

    bool operator==(const Time& t) const {
        return hours == t.hours && minutes == t.minutes && seconds == t.seconds;
    }

    bool operator>(const Time& t) const {
        return (hours * 3600 + minutes * 60 + seconds) >
            (t.hours * 3600 + t.minutes * 60 + t.seconds);
    }

    bool operator<(const Time& t) const {
        return (hours * 3600 + minutes * 60 + seconds) <
            (t.hours * 3600 + t.minutes * 60 + t.seconds);
    }
};


int main() {
    Time t1, t2;

    cout << "Enter first time:\n";
    t1.input();
    if (!t1.check()) {
        cout << "First time is invalid!\n";
        return 1;
    }

    cout << "Enter second time:\n";
    t2.input();
    if (!t2.check()) {
        cout << "Second time is invalid!\n";
        return 1;
    }

    cout << "First time: ";
    t1.output();

    cout << "Second time: ";
    t2.output();

    Time sum = t1 + t2;
    cout << "Sum: ";
    sum.output();

    Time diff = t1 - t2;
    cout << "Difference: ";
    diff.output();

    if (t1 == t2) cout << "Times are equal\n";
    if (t1 > t2) cout << "First time is greater\n";
    if (t1 < t2) cout << "Second time is greater\n";

    return 0;
}