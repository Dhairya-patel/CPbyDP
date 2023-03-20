#include<bits/stdc++.h>

using namespace std;

//  3 vehicle types allowed for this Parking lot
enum VehicleType
{
    MotorCycle, Car, Bus;
};

//  Entrypoint of Parking Lot
class Entrypoint
{
    int entrypointID;
    int entryCount;

    public:
        Entrypoint(int id)
        {
            entrypointID = id;
            entryCount = 0;
        }
};

//  Exitpoint of Parking Lot
class Exitpoint
{
    int exitpointID;
    int exitCount;

    public:
        Exitpoint(int id)
        {
            exitpointID = id;
            exitCount = 0;
        }
};

//  Slot is the place assigned to each vehicle type
class Slot
{
    int slotID;
    int floorID;
    bool isOccupied;
    time_t inTime;
    time_t outTime;
};

//  Slot meant only for motorcycles
class MotorcycleSlot : public Slot
{
    public:
        MotorcycleSlot(int slotid, int floorid)
        {
            slotID = slotid;
            floorID = floorid;
            isOccupied = false;
        }
};

//  Slot meant only for Cars
class CompactSlot : public Slot
{
    public:
        CompactSlot(int slotid, int floorid)
        {
            slotID = slotid;
            floorID = floorid;
            isOccupied = false;
        }
};

//  Slot meant only for Buses
class LargeSlot : public Slot
{
    public:
        LargeSlot(int slotid, int floorid)
        {
            slotID = slotid;
            floorID = floorid;
            isOccupied = false;
        }
};

//  A floor has a collection of all the three types of slots
//  And is responsible for assigning slot to a vehicle
class Floor
{
    int floorID;
    
    MotorcycleSlot motorcycleSlots[100];
    CompactSlot compactSlots[50];
    LargeSlot largeSlots[10];

    public:
        Floor(int id)
        {
            floorID = id;
            for(int i=0;i<100;i++)
                motorcycleSlots[i] = new MotorcycleSlot(i + 1, id);
            for(int i=0;i<50;i++)
                compactSlots[i] = new CompactSlot(i + 1, id);
            for(int i=0;i<10;i++)
                largeSlots[i] = new LargeSlot(i + 1, id);
        }

        bool hasSpace(vehicleType vt)
        {
            if(vt == 0)
            {
                //  
            }
        }
};

class ParkingLot
{
    Entrypoint entrypoints[10];
    Exitpoint exitpoints[10];

    Floor floors[10];

    public:
        ParkingLot()
        {
            for(int i=0;i<10;i++)
            {
                entrypoints[i] = new Entrypoint(i + 1);
                exitpoints[i] = new Exitpoint(i + 1);

                floors[i] = new Floor(i + 1);
            }
        }

        //  add a new vehicle entry and start its parking process
        bool addEntry(int id, VehicleType vt)
        {
            entrypoints[id - 1].entryCount++;
            //  allocate the floor
            for(int i=0;i<10;i++)
            {

            }
        }

};

//  Shall contain vehicle details and Slot ID assigned later on will be stamped here, default being -1
class Vehicle
{
    VehicleType vt;
    string vehicleNumberPlate;

    int slotID;

    public:
        Vehicle(VehicleType vehicleType, string &vehicleNumber)
        {
            slotID = -1;

            vt = vehicleType;
            vehicleNumberPlate = vehicleNumber;
        }
};

class Ticket
{
    int slotID;
    int floorID;
    int price;
    time_t inTime;
    time_t maxTime;

    Vehicle v;
};

int main()
{
    ParkingLot parkingLot = new ParkingLot();
    cout<<"Parking Lot is Functional..."<<endl;
    while(true)
    {
        VehicleType vt;
        string numberPlate;
        Entrypoint ep;
        cout<<"Welcome! Tell us about your vehicle"<<endl;
        cout<<"Enter: 0 - Motorcycle, 1 - Car, 2 - Bus, 3 - Others ";
        cin>>vt;
        cout<<"Enter Vehicle Number Plate: ";
        cin>>numberPlate;
        if(numberPlate.size() < 2)
        {
            cout<<"Invalid Number Plate"<<endl<<endl;
            return;
        }
        cout<<"Enter entry point: ";
        cin>>ep.entrypointID;
        switch(vt)
        {
            case 0:
                //  It's Motorcycle
                ParkingLot.addEntry(entrypointID, vehicleType);
            case 1:
                //  It's Car
            case 2:
                //  It's Bus
            default:
                cout<<"We are deeply sorry. Currently we provide parking only for Motorcycle, Car and Bus. Thank you."<<endl;
        }
    }
}