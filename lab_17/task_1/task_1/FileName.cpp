#include <iostream>
#include <string>
#include <functional>

using namespace std;

class Notification 
{
protected:
    string title;
    string message;
public:
    Notification(const string& t, const string& m) : title(t), message(m) {}

    virtual void display() const 
    {
        cout << "Title: " << title << "\nMessage: " << message << endl;
    }

    virtual ~Notification() = default;
};

class PriorityNotification : public Notification 
{
public:
    enum priorityLevel { low, medium, high };
private:
    priorityLevel priority;

public:
    PriorityNotification(const string& t, const string& m, priorityLevel p)
        : Notification(t, m), priority(p) {}

    void display() const override 
    {
        cout << "Title: " << title << "\nMessage: " << message
             << "\nPriority: " << PriorityToString() << endl;
    }

    void displayWithAction(function<void()> action) 
    {
        display();
        if (priority == high) 
        {
            action();
        }
    }

private:

    string PriorityToString() const 
    {
        switch (priority) 
        {
            case low: return "Low";
            case medium: return "Medium";
            case high: return "High";
            default: return "Unknown";
        }
    }
};

int main() {

    PriorityNotification Notification(
        "System Alert",
        "Server maintenance scheduled at midnight.",
        PriorityNotification::high
    );

    auto action = []() 
        {
        cout << "Confirmation required!" << endl;
    };

    Notification.displayWithAction(action);

    return 0;
}