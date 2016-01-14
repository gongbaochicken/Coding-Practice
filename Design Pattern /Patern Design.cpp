//Patern Design

//C++ Singleton Sample Implementation Code

// Declaration
class Singleton {
public: 
    static Singleton* Instance();
protected: 
    Singleton();
private:
    static Singleton* _instance;
}

// Implementation 
Singleton* Singleton::_instance = 0;

Singleton* Singleton::Instance() {
    if (_instance == 0) {
        _instance = new Singleton;
    }
    return _instance;
}