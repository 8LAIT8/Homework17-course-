/*1)
#include <iostream>
using namespace std;

class MyClass {
public:
    int normalVar;          
    static int staticVar;   

   
    MyClass(int value) {
        normalVar = value;    
        staticVar++;          
        cout << "Constructor: normalVar = " << normalVar << ", staticVar = " << staticVar << endl;
    }

    ~MyClass() {
        staticVar--;  
        cout << "Destructor: staticVar = " << staticVar << endl;
    }
};

int MyClass::staticVar = 0;

int main() {
    MyClass obj1(25);  
    MyClass obj2(100); 
    return 0;
}*/
/* #include <iostream>
using namespace std;

class MyClass {
public:
    int normalVar;          
    static int staticVar;   

    MyClass(int value) {
        normalVar = value;    
        staticVar++;          
        cout << "Constructor: normalVar = " << normalVar << ", staticVar = " << staticVar << endl;
    }

    ~MyClass() {
        staticVar--;  
        cout << "Destructor: staticVar = " << staticVar << endl;
    }
};

int MyClass::staticVar = 0;

int main() {
    MyClass obj1(2);  
    MyClass obj2(20);
    MyClass obj3(22);

    cout << "After creating objects:" << endl;
    cout << "obj1: normalVar = " << obj1.normalVar << ", staticVar = " << MyClass::staticVar << endl;
    cout << "obj2: normalVar = " << obj2.normalVar << ", staticVar = " << MyClass::staticVar << endl;
    cout << "obj3: normalVar = " << obj3.normalVar << ", staticVar = " << MyClass::staticVar << endl;

    cout << "\nDeleting objects..." << endl;
    

    return 0;
}
*/
/*3)
#include <iostream>
using namespace std;

class MyClass {
private:
    int normalVar;          
    static int staticVar;   

public:
    
    MyClass(int value) {
        normalVar = value;    
        staticVar++;          
        cout << "Constructor: normalVar = " << normalVar << ", staticVar = " << staticVar << endl;
    }

    
    ~MyClass() {
        staticVar--;  
        cout << "Destructor: staticVar = " << staticVar << endl;
    }

    
    static int getStaticVar() {
        return staticVar;
    }

    
    static void setStaticVar(int value) {
        staticVar = value;
    }
};

int MyClass::staticVar = 0;

int main() {
    MyClass obj1(2);
    MyClass obj2(20);
    MyClass obj3(22);

    cout << "\nAfter creating objects:" << endl;
    cout << "obj1: normalVar = " << obj1.getStaticVar() << ", staticVar = " << MyClass::getStaticVar() << endl;
    cout << "obj2: normalVar = " << obj2.getStaticVar() << ", staticVar = " << MyClass::getStaticVar() << endl;
    cout << "obj3: normalVar = " << obj3.getStaticVar() << ", staticVar = " << MyClass::getStaticVar() << endl;

    cout << "\nDeleting objects..." << endl;

    return 0;
}*/
/*4)
#include <iostream>
using namespace std;

class MyClass {
private:
    int normalVar;          
    static int staticVar;   

public:
    MyClass(int value) {
        normalVar = value;    
        staticVar++;          
        cout << "Constructor: normalVar = " << normalVar << ", staticVar = " << staticVar << endl;
    }

    ~MyClass() {
        staticVar--;  
        cout << "Destructor: staticVar = " << staticVar << endl;
    }

    int getNormalVar() const {
        return normalVar;
    }

    static int getStaticVar() {
        return staticVar;
    }

    static void setStaticVar(int value) {
        staticVar = value;
    }
};

int MyClass::staticVar = 0;

int main() {
    MyClass obj1(2);
    MyClass obj2(20);
    MyClass obj3(22);

    int (MyClass:: * getNormalPointer)() const = &MyClass::getNormalVar;

    cout << "\nAfter creating objects:" << endl;
    cout << "obj1: normalVar = " << (obj1.*getNormalPointer)() << ", staticVar = " << MyClass::getStaticVar() << endl;
    cout << "obj2: normalVar = " << (obj2.*getNormalPointer)() << ", staticVar = " << MyClass::getStaticVar() << endl;
    cout << "obj3: normalVar = " << (obj3.*getNormalPointer)() << ", staticVar = " << MyClass::getStaticVar() << endl;

    cout << "\nDeleting objects..." << endl;

    return 0;
}
*/
/*5)
#include <iostream>
using namespace std;

class MyClass {
private:
    int normalVar;          
    static int staticVar;   
    double doubleVar;       
    string stringVar;       

public:
    MyClass(int value, double dValue, string sValue) {
        normalVar = value;    
        staticVar++;          
        doubleVar = dValue;   
        stringVar = sValue;   
        cout << "Constructor: normalVar = " << normalVar << ", staticVar = " << staticVar
            << ", doubleVar = " << doubleVar << ", stringVar = " << stringVar << endl;
    }

    ~MyClass() {
        staticVar--;  
        cout << "Destructor: staticVar = " << staticVar << endl;
    }

    int getNormalVar() const {
        return normalVar;
    }

    static int getStaticVar() {
        return staticVar;
    }

    double getDoubleVar() const {
        return doubleVar;
    }

    string getStringVar() const {
        return stringVar;
    }

    static void setStaticVar(int value) {
        staticVar = value;
    }

    template <typename T>
    T getValue(int choice) const {
        switch (choice) {
        case 1: return static_cast<T>(normalVar);
        case 2: return static_cast<T>(staticVar);
        case 3: return static_cast<T>(doubleVar);
        case 4: return static_cast<T>(stringVar);
        default: return T();
        }
    }
};

int MyClass::staticVar = 0;

int main() {
    MyClass obj1(5, 10.5, "Hello");
    MyClass obj2(10, 20.5, "World");
    MyClass obj3(15, 30.5, "C++");

    int (MyClass:: * getIntPointer)() const = &MyClass::getNormalVar;
    double (MyClass:: * getDoublePointer)() const = &MyClass::getDoubleVar;
    string(MyClass:: * getStringPointer)() const = &MyClass::getStringVar;

    cout << "\nAfter creating objects:" << endl;
    cout << "obj1: normalVar = " << (obj1.*getIntPointer)()
        << ", doubleVar = " << (obj1.*getDoublePointer)()
        << ", stringVar = " << (obj1.*getStringPointer)() << endl;

    cout << "obj2: normalVar = " << (obj2.*getIntPointer)()
        << ", doubleVar = " << (obj2.*getDoublePointer)()
        << ", stringVar = " << (obj2.*getStringPointer)() << endl;

    cout << "obj3: normalVar = " << (obj3.*getIntPointer)()
        << ", doubleVar = " << (obj3.*getDoublePointer)()
        << ", stringVar = " << (obj3.*getStringPointer)() << endl;

    cout << "\nUsing getValue method:" << endl;
    cout << "obj1 normalVar: " << obj1.getValue<int>(1) << endl;
    cout << "obj1 staticVar: " << obj1.getValue<int>(2) << endl;
    cout << "obj1 doubleVar: " << obj1.getValue<double>(3) << endl;
    cout << "obj1 stringVar: " << obj1.getValue<string>(4) << endl;

    cout << "\nDeleting objects..." << endl;

    return 0;
}*/
