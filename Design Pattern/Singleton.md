# Singleton

Sinleton is the simplest and very common design pattern used in software object oriented design.

As the name suggests, the singleton design pattern ensures a class can only have one instance.

Where is Singleton get applied? Here are some exmaples:

* Windows Task Manager
* Database connection pool
* Some thread pools
* Configure files in your program
* Persistence layer in a database
* ...

We can explore singleton by using an example. Suppose I want to create a database connecting pool class, and we just omit other members or functions, and just focus on its initialization. As you can imagine, the database connection pool can help us to manage connections to a certain database(let's call it Devil DB ) in a more efficient way, and of course, we can only allow one such database pool existes in our program. 

## Naive Implementation

To guarantee that only one instance will be created, the first key is to keep the instance as a private member, and keep its constructor as a private method.

To get the instance, we should declare the getDBIntance() method as a static function, so we can call it outside the singleton class.

In constructor, we firstly check if the object is nullptr. If it is nullptr, we will create a new object instance and return it, if it's not nullptr, which means it has been initialized before, we just return it. There is a issue about this implemention, please see the code below and I will discuss it later.


```
#include <iostream>

class DevilDB {
public:
    static DevilDB* getDBInstance();

private:    
    // private constructor
    DevilDB();
    
    // private member, can only be accessed by using getDBInstance()
    static DevilDB* m_db;
};

DevilDB* DevilDB::m_db = nullptr;

DevilDB* DevilDB::getDBInstance() {
    if (m_db == nullptr) {
        m_db = new DevilDB();
    }
    return m_db;
}

DevilDB::DevilDB() {
    std::cout << "create a new devil DB." << std::endl;
}

int main(int argc, const char * argv[]) {
    // get instance, only the first time will new
    DevilDB* db = DevilDB::getDBInstance();
    DevilDB* db2 = DevilDB::getDBInstance();
    
    std::cout << "db addr:" << db << std::endl;
    std::cout << "db2 addr:" << db2 << std::endl;

    return 0;
}
```

The problem is that we cannot call a destructor ~DevilDB() to delete the resources we allocate. Why? Because when we handly call destructor, there will be infinite loop to call destructs again and again. Unless you can have an automatic release helper function to help you release memory, there is a memory leak issue.

## Meyers' Singleton:
To solve above issue, a well-known singleton to be introduced here is Meyers' Singleton, which name after Scott Meyers.

This solution uses local static objects, because static objects are initialized when the object's definition is first encountered during a call. So it's "politic right" to write the getDBInatnce() method like this:

```
DevilDB& DevilDB::getDBInstance() {
    static DevilDB m_db;
    return m_db;
}

```
And the full example code is:

```
#include <iostream>

class DevilDB {
public:
    static DevilDB& getDBInstance();

private:
    // private member, can only be accessed by using getDBInstance()
    static DevilDB m_db;
    
    // private constructor
    DevilDB();
};


DevilDB& DevilDB::getDBInstance() {
    static DevilDB m_db;
    return m_db;
}

DevilDB::DevilDB() {
    std::cout << "create a new devil DB." << std::endl;
}


int main(int argc, const char * argv[]) {
    // get instance, only the first time will new
    DevilDB& db = DevilDB::getDBInstance();
    DevilDB& db2 = DevilDB::getDBInstance();
    std::cout << "db addr:" << &db << std::endl;
    std::cout << "db2 addr:" << &db2 << std::endl;
    return 0;
}
```

#### Features:
* No leak issue.
* Only construct when used and only the first time used.
* Good news: C++11 ensures that constructs static variable in getInstance method is thread safe, because each static variable has a guard now.
*

## Deferences between static and singleton

You may name a lot of diffeces between using singleotn and just use a static variable directly. Here is what I feel:

1. Singleton is more easier to mock in the unit test, which means singleton is more testable than static variable. While static variable cannot be replaced or mocked in unit tests.
2. Accessing static variable is a little slow.
3. Sintleton provides tight coupling in OOD scenario, and in many cases, it sounds more sense to me.
