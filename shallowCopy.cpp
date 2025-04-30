#include <iostream>
using namespace std;

class ResourceHandler {
    private:
        int* resource;
    public:
        ResourceHandler(int value) {
            resource = new int(value); 
        }
        ResourceHandler(const ResourceHandler& other) {
            resource = other.resource;
        }
        ~ResourceHandler() {
            delete resource;
            cout << "Resource cleaned up" << endl;
        }
        void show() {
            cout << *resource << endl;
        }
        void update(int newValue) {
            *this->resource = newValue; 
        }
};

int main() {
    ResourceHandler handler1(750);
    handler1.show();
    ResourceHandler handler2 = handler1;
    handler2.show();
    handler1.show();
    return 0;
}

