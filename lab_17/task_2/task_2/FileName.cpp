#include <iostream>
#include <string>
#include <functional>

using namespace std;

class Product 
{
protected:
    string name;
    double price;

public:
    Product(const string& n, double p) : name(n), price(p) {}

    virtual double getPrice() const 
    {
        return price;
    }

    string getName() const 
    {
        return name;
    }

    double getOriginalPrice() const 
    {
        return price;
    }

    virtual void printDiscountInfo() const 
    {
    }

    virtual ~Product() = default;
};

class DiscountedProduct : public Product 
{
private:
    double discountPercentage;

public:
    DiscountedProduct(const string& n, double p, double discount)
        : Product(n, p), discountPercentage(discount) 
    {
        if (discountPercentage < 0 || discountPercentage > 100) 
        {
            discountPercentage = 0;
            cout << "Warning: Invalid discount percentage for " << n << ". Set to 0%.\n";
        }
    }

    double getPrice() const override 
    {
        return calculateDiscount([this](double p) 
            {
            return p * (1.0 - discountPercentage / 100.0);
            });
    }

    double calculateDiscount(const function<double(double)>& discountFunc) const 
    {
        return discountFunc(price);
    }

    void printDiscountInfo() const override 
    {
        cout << "Discounted Price (" << discountPercentage << "% off): $" << getPrice() << "\n";
    }
};

int main() {

    Product* products[] = 
    {
        new DiscountedProduct("Laptop", 1000.0, 15.0),
        new DiscountedProduct("Smartphone", 800.0, 10.0),
        new Product("Headphones", 150.0)
    };

    for (const auto* product : products) 
    {
        cout << "Product: " << product->getName() << "\n";
        cout << "Price: $" << product->getOriginalPrice() << "\n";
        product->printDiscountInfo();
        cout << "------------------------\n";
    }

    for (auto* product : products) 
    {
        delete product;
    }

    return 0;
}