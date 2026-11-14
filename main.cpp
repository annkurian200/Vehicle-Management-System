#include<iostream>
#include <string>
using namespace std;

class Vehicle{
    private:
    int vehicle_id;
    string brand;
    string model;
    float price;
    bool available;

    public:
    Vehicle(){
        vehicle_id=0;
        brand="";
        model="";
        price=0.0;
        available=true;
    }

    Vehicle(int id, string b, string m,float p){
        vehicle_id=id;
        brand=b;
        model=m;
        price=p;
        available=true;

    }
    bool isAvailable(){
        return available;
    }

    void setAvailability(bool status){
        available=status;
    }
    void displayDetails(){
        cout << "\nVehicle ID: " << vehicle_id;
        cout << "\nBrand: " << brand;
        cout << "\nModel: " << model;
        cout << "\nPrice: Rs. " << price;
        cout << "\nAvailability: "
             << (available ? "Available" : "Not Available");
    }
    void SearchVehicle(int id){
        if(vehicle_id==id){
            displayDetails();
        }
    }
    void SearchVehicle(string b){
        if(brand==b){
            displayDetails();
        }
    }
    void SearchVehicle(string b,string m){
        if(brand==b && model==m){
            displayDetails();
        }
    }
};

class Insurable {
    private:
    bool insurance;
    int insurance_cost;
    public:
    Insurable(){
        insurance=true;
        insurance_cost=2000;
    }
    bool isInsuranceAvailable(){
        return insurance;
    }

    void setAvailability(bool status){
        insurance=status;
    }
    void displayDetails_insurance(){
        cout << "\nInsurance Availability: "
             << (insurance ? "Available" : "Not Available");
        cout<<"\nInsurance cost : Rs. "<<insurance_cost;
    }

};

class Car : public Vehicle, public Insurable{
    private:
    string fuel_type;
    public:
    Car(int id, string b, string m,float p,string f): Vehicle(id,b,m,p),Insurable(){
        fuel_type=f;
    }
    void displayDetails_car(){
        displayDetails();
        cout<<"\nFuel Type: "<<fuel_type;
        displayDetails_insurance();
        cout<<endl;
    }

};
class Bike : public Vehicle{
    private:
    int engine_capacity;
    public:
    Bike(int id, string b, string m,float p,int e): Vehicle(id,b,m,p){
        engine_capacity=e;
    }
    void displayDetails_bike(){
        displayDetails();
        cout<<"\nEngine Capacity: "<<engine_capacity<<endl;
    }
};
class Scooter : public Vehicle{
    private:
    string type;
    public:
    Scooter(int id, string b, string m,float p,string t): Vehicle(id,b,m,p){
        type=t;
    }
    void displayDetails_scooter(){
        displayDetails();
        cout<<"\nType: "<<type<<endl;
    }
};

class ElectricCar:public Car{
    private:
    float kilometers;
    public:
    ElectricCar(int id, string b, string m,float p,string f,float km):Car(id,b,m,p,f){
        kilometers=km;
    }
    void displayDetails_electricCar(){
        displayDetails_car();
        cout<<"Electric Car Kilometers : "<<kilometers;
        cout<<endl;
    }
};

class PremiumFeatures{
    private:
    bool sunroof;
    bool leatherSeats;
    public:
    PremiumFeatures(){
        sunroof=true;
        leatherSeats=true;
    }
    void displayPremiumFeatures(){
        cout<<"\nSunroof Available : "<<(sunroof ? "Available": "Not Available");
        cout<<"\nLeather Seats Available : "<<(leatherSeats ? "Available":"Not Available");
    }
};

class PremiumCar :public Car,public PremiumFeatures{
    public:
    PremiumCar(int id, string b, string m,float p,string f):Car(id,b,m,p,f),PremiumFeatures(){
    }
    void displayPremiumCarDetails(){
        displayDetails_car();
        displayPremiumFeatures();
    }
};

int main(){
    /*Scooter s(1234,"Activa","120M",70000,"Petrol");
    s.displayDetails_scooter();
    Car c(0001,"honda","TSK20",300000,"Petrol");
    c.Vehicle::setAvailability(false);
    c.displayDetails_car();
    Bike b(0002,"Pulsar","120cc",100000,120);
    b.displayDetails_bike();
    Insurable i;
    i.displayDetails_insurance();
    ElectricCar e(0001,"honda","TSK20",300000,"No fuel",90);
    e.displayDetails_electricCar();
    PremiumCar pc(101, "Honda", "City", 1500000, "Petrol");
    pc.displayPremiumCarDetails();*/
    Car c(101, "Honda", "City", 1500000, "Petrol");
    c.SearchVehicle(101);
    c.SearchVehicle("suzuki");
    c.SearchVehicle("Honda","City");
    return 0;
}