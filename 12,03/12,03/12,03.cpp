#include <iostream>
#include <vector>

class Transport {
public:
    virtual void input() = 0;
    virtual void output() const = 0;
    virtual double fuelConsumption() const = 0;
    virtual double getCost() const = 0;
    virtual void setCost(double cost) = 0;
    virtual double getCapacity() const = 0;
    virtual int getPassengerCapacity() const = 0;
    virtual ~Transport() {}
};

class Car : public Transport {
private:
    double cost;
    double fuel;
    double capacity;
    int passengerCapacity;
public:
    Car(double cost, double fuel, double capacity, int passengerCapacity) : cost(cost), fuel(fuel), capacity(capacity), passengerCapacity(passengerCapacity) {}

    void input() override {}

    void output() const override {}

    double fuelConsumption() const override {
        return fuel / 100.0;
    }

    double getCost() const override {
        return cost;
    }

    void setCost(double cost) override {
        this->cost = cost;
    }

    double getCapacity() const override {
        return capacity;
    }

    int getPassengerCapacity() const override {
        return passengerCapacity;
    }
};

class Truck : public Transport {
private:
    double cost;
    double fuel;
    double capacity;
    int passengerCapacity;
public:
    Truck(double cost, double fuel, double capacity, int passengerCapacity) : cost(cost), fuel(fuel), capacity(capacity), passengerCapacity(passengerCapacity) {}

    void input() override {}

    void output() const override {}

    double fuelConsumption() const override {
        return fuel / 50.0;
    }

    double getCost() const override {
        return cost;
    }

    void setCost(double cost) override {
        this->cost = cost;
    }

    double getCapacity() const override {
        return capacity;
    }

    int getPassengerCapacity() const override {
        return passengerCapacity;
    }
};

int main() {
    std::vector<Transport*> vehicles;

    vehicles.push_back(new Car(20000, 50, 500, 5));
    vehicles.push_back(new Truck(50000, 150, 2000, 2));

    for (Transport* vehicle : vehicles) {
        vehicle->input();
        vehicle->output();
        std::cout << "Fuel consumption: " << vehicle->fuelConsumption() << " L/km\n";
        std::cout << "Cost: " << vehicle->getCost() << " $\n";
        std::cout << "Capacity: " << vehicle->getCapacity() << " kg\n";
        std::cout << "Passenger capacity: " << vehicle->getPassengerCapacity() << "\n\n";
        delete vehicle;
    }

    return 0;
}
