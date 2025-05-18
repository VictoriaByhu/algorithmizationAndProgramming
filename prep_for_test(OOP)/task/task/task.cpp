#include <iostream>
using namespace std;

class Tree {
protected:
    string type;
    int age;
    int yieldPerYear;
public:
    Tree() : type("Apple"), age(2), yieldPerYear(200) {}

    Tree(string t) : type(t), age(0), yieldPerYear(0) {}

    Tree(string t, int a, int y) : type(t), age(a), yieldPerYear(y) {}

    void increaseYieldByPercent(double percent) {
        yieldPerYear += yieldPerYear * (percent / 100.0);
    }

    bool isMature() const {
        return age >= 3;
    }

    virtual void getInfo() const {
        cout << "Tree information:\n";
        cout << "Type: " << type << endl;
        cout << "Age: " << age << endl;
        cout << "Yield per year: " << yieldPerYear << endl;
    }

    bool operator>(const Tree& other) const {
        return yieldPerYear > other.yieldPerYear;
    }

    bool operator<(const Tree& other) const {
        return yieldPerYear < other.yieldPerYear;
    }
};

class InoculatedTree : public Tree {
private:
    int inoculations;
public:
    InoculatedTree(string t, int a, int y, int i = 0) : Tree(t, a, y), inoculations(i) {
        if (inoculations > 5) {
            increaseYieldByPercent(20);
        }
    }

    void addNumOfInoculations(int num) {
        inoculations += num;
        if (inoculations > 5) {
            increaseYieldByPercent(20);
        }
    }

    void getInfo() const override {
        Tree::getInfo();
        cout << "Number of inoculations: " << inoculations << endl;
    }
};

// Template function to find max element
template <typename T>
T findMax(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    Tree trees[3] = {
        Tree("Apple", 3, 400),
        Tree("Pear", 4, 500),
        Tree("Cherry", 2, 300)
    };

    InoculatedTree inoculatedTrees[2] = {
        InoculatedTree("Plum", 5, 450, 3),
        InoculatedTree("Orange", 6, 480, 6)
    };

    cout << "Regular trees:\n";
    for (int i = 0; i < 3; i++) {
        trees[i].getInfo();
        cout << endl;
    }

    cout << "Inoculated trees:\n";
    for (int i = 0; i < 2; i++) {
        inoculatedTrees[i].getInfo();
        cout << endl;
    }

    Tree maxTree = findMax(trees, 3);
    cout << "Tree with maximum yield among regular trees:\n";
    maxTree.getInfo();

    return 0;
}
