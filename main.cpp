#include<iostream>
#include <string>
#include <fstream>
#include<stdexcept>
using namespace std;

class Vehicle{
    private:
    int vehicle_id;
    string brand;
    string model;
    float price;
    bool available;

    public:
    virtual void displayDetails()=0;
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
    void updatePrice(float price){
        if(price<=0){
            throw invalid_argument("Price must be greater than 0"); 
        }
        this->price=price;
    }
    void displayBasicDetails(){
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
    public:
    virtual bool isInsuranceAvailable()=0;

    virtual void setAvailability(bool status)=0;
    virtual void displayDetails_insurance()=0;
    virtual ~Insurable(){}
};

class Car : public Vehicle, public Insurable{
    private:
    string fuel_type;
    bool insurance;
    int insurance_cost;
    public:
    Car(int id, string b, string m,float p,string f): Vehicle(id,b,m,p),Insurable(){
        fuel_type=f;
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
    void displayDetails() override{
        displayBasicDetails();
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
    void displayDetails() override{
        displayBasicDetails();
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
    void displayDetails() override{
        displayBasicDetails();
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
    void displayDetails() override{
        Car::displayDetails();
        cout<<"Electric Car Kilometers : "<<kilometers<<endl;
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
        Car::displayDetails();
        displayPremiumFeatures();
    }
};    
Vehicle *vehicles[50];
int count=0;

void addVehicle(){
    int choice,id,engine_capacity;
    string brand,model,fuel_type,type;
    float price,kilometers;
    cout<<"---Vehicle Type---"<<endl;
    cout<<"1. Car"<<endl;
    cout<<"2. Scooter"<<endl;
    cout<<"3. Bike"<<endl;
    cout<<"4. Electric Car"<<endl;
    cout<<"5. Premium Car"<<endl;
    cout<<"Enter vehicle type: ";
    cin>>choice;

    if(count>=50){
        cout<<"\nVehicle Storage is full!"<<endl;
        return;
    }

    cout<<"\nEnter Details-";
    cout<<"\n1.Vehicle Id:";
    cin>>id;
    cout<<"\n2.Brand:";
    cin>>brand;
    cout<<"\n3.Model:";
    cin>>model;
    cout<<"\n4.Price:";
    cin>>price;
    switch(choice){
        case 1: 
            cout<<"\n5.Fuel type:";
            cin>>fuel_type;
            vehicles[count]=new Car(id,brand,model,price,fuel_type);
            cout<<"\nCar added"<<endl;

            break;
        case 2:
            cout<<"\n5.Type:";
            cin>>type;
            cout<<"Scooter selected"<<endl;
            vehicles[count]=new Scooter(id,brand,model,price,type);
           
            break;
        case 3:
            cout<<"\n5.Engine capacity:";
            cin>>engine_capacity;
            cout<<"Bike selected"<<endl;
            vehicles[count]=new Bike(id,brand,model,price,engine_capacity);
         
            break;
        case 4: 
            cout<<"\n5.Fuel type:";
            cin>>fuel_type;
            cout<<"\n6.Kilometers:";
            cin>>kilometers;
            cout<<"Electric Car selected"<<endl;
            vehicles[count]=new ElectricCar(id,brand,model,price,fuel_type,kilometers);
         
            break;
        case 5:
            cout<<"\n5.Fuel type:";
            cin>>fuel_type;
            cout<<"Premium Car selected"<<endl;
            vehicles[count]=new PremiumCar(id,brand,model,price,fuel_type);
          
            break;
        default:
            cout<<"Invalid choice!"<<endl;
    }
    count++;
}
void displayVehicles(){
    if(count==0){
        cout<<"No vehicles available"<<endl;
        return;
    }
    cout<<"\n======Vehicle Records=======\n";
    for(int i=0;i<count;i++){
        cout<<"\nVehicle-"<<i+1;
        vehicles[i]->displayDetails();
    }
    cout<<"\n-----------------------------\n";
}



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
    pc.displayPremiumCarDetails();
    //Method overloading
    Car c(101, "Honda", "City", 1500000, "Petrol");
    c.SearchVehicle(101);
    c.SearchVehicle("suzuki");
    c.SearchVehicle("Honda","City");
    //Method overriding 
    Car c(101, "Honda", "City", 1500000, "Petrol");
    Bike b(102, "Bajaj", "Pulsar", 100000, 120);
    Scooter s(103, "Honda", "Activa", 70000, "Petrol");
    //c.displayDetails();
    //b.displayDetails();
    //s.displayDetails();
    //runtime polymorphism
    Vehicle* v;
    v = &c;
    v->displayDetails();
    v = &b;
    v->displayDetails();
    v = &s;
    v->displayDetails();

    //this pointer
    Car c(101, "Honda", "City", 150000, "Petrol");
    cout<<"\nBefore updating price";
    c.displayDetails();
    try{
    cout<<"\nAfter updating price"<<endl;
    c.updatePrice(0);
    c.displayDetails();
    }
    catch(invalid_argument &e){
        cout<<"Error! "<<e.what()<<endl;
    }

    //Abstract class
    Car c(101, "Honda", "City", 150000, "Petrol");
    c.displayDetails();
    //interface pointer
    Insurable* i =&c;
    i->displayDetails_insurance();
    //if v object is created using vehicle class it will give error
    //because it is a abstract class and abstract class cannot create objects
    //Vehicle v(101, "Honda", "City", 150000);
    //v.displayBasicDetails();
    ofstream writefile("vehicles.txt");
    if(writefile.is_open()){
        writefile<<"101, Honda, City, 1500000"<<endl;
        writefile<<"102, Bajaj, Pulsar, 100000"<<endl;

        writefile.close();
        cout<<"Vehicle data saved successfully"<<endl;
    }
    else{
        cout<<"Error opening file!"<<endl;
    }
    ofstream appendFile("vehicles.txt",ios::app);
    if(appendFile.is_open()){
        appendFile<<"103, Honda, Activa, 70000"<<endl;
        appendFile.close();
        cout<<"New vehicle added successfully!"<<endl;
    }
    else{
        cout<<"Error opening file!"<<endl;
    }
    ifstream readFile("vehicles.txt");
    string line;
    if(readFile.is_open()){
        cout<<"---Vehicle Records---"<<endl;
        while(getline(readFile,line)){
            cout<<line<<endl;
        }
        readFile.close();
    }
    else{
        cout<<"Error opening file!"<<endl;
    }*/
    //Menu
    int choice;
    do{
        cout<<"\n-----Vehicle Management System-----"<<endl;
        cout<<"1. Add Vehicle"<<endl;
        cout<<"2. Display vehicles"<<endl;
        cout<<"3. Search Vehicle"<<endl;
        cout<<"4. Update Vehicle price"<<endl;
        cout<<"0. Exit";

        cout<<"\nEnter Choice: ";
        cin>>choice;

        switch(choice){
            case 0:
                break;
            case 1:
                addVehicle();
                break;
            case 2:
                displayVehicles();
                break;
            default:
                cout<<"Invalid Choice!"<<endl;
                break;
        }
    }
    while(choice!=0);
    return 0;
}
