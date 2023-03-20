#include<bits/stdc++.h>

using namespace std;

enum Direction
{
    UP, DOWN
};

enum State
{
    MOVING, STOPPED, IDLE
};

class Elevator
{
    private:
        Direction direction;
        State currentState;
        int currentFloor;
        int capacity;
        int headCount;
    
    public:

        Elevator()
        {
            direction = UP;
            currentState = STOPPED;
            currentFloor = 0;
            capacity = 10;
            headCount = 0;
        }

        Elevator(Direction dir, State state, int floor, int)
        {
            direction = dir;
            currentState = state;
            currentFloor = floor;
            capacity = 10;
            headCount = 0;
        }

        void DisplayElevator()
        {
            cout<<"Elevator is on "<<currentFloor<<" floor and in "<<currentState<<" state while moving in "<<direction<<" direction"<<endl;
        }
};

Elevator elevator;

class InternalRequest
{
    //  request made once a person enters the elevator
    int destinationFloor = 0;

    public:
        int getDestinationFloor()
        {
            return destinationFloor;
        }

        void setDestinationFloor(int floor)
        {
            destinationFloor = floor;
        }
};

class ExternalRequest
{
    // request made when a person wishes to ride the elevator to a certain floor
    Direction requestDirection = UP;
    int sourceFloor = 0;

    public:
        Direction getRequestDirection()
        {
            return requestDirection;
        }
        void setRequestDirection(Direction reqDirection)
        {
            requestDirection = reqDirection;
        }

        int getSourceFloor()
        {
            return sourceFloor;
        }
        void setSourceFloor(int floor)
        {
            sourceFloor = floor;
        }
};

class Request
{
    InternalRequest internalRequest;
    ExternalRequest externalRequest;
};

int main()
{
    elevator.DisplayElevator();
    queue<Request>requests;
    while(true)
    {
        int num;
        cout<<"Enter number of requests: ";
        cin>>num;
        for(int i=0;i<num;i++)
        {
            Request r;
            cout<<"Enter Request "<<i + 1<<endl;
            cout<<"Direction, 0 for UP and 1 for DOWN: ";
            cin>>r.externalRequest.requestDirection;
            cout<<"Floor from which request is being made: ";
            cin>>r.externalRequest.sourceFloor;

            requests.push(r);
        }
        while(!requests.empty())
        {
            // code to cater each request
        }
    }
    return 0;
}