//
// Created by mrbab on 04.04.2023.
//

#ifndef LAB4_PDTTESTOBJECT_H
#define LAB4_PDTTESTOBJECT_H

#include <ostream>
#include <iostream>
#include <iomanip>

class PDTTestObject {
private:
    int x;
    double y;
    float z;

public:
    bool operator==(const PDTTestObject &rhs) const {
        return x == rhs.x;
//               y == rhs.y &&
//               z == rhs.z;
    }

    bool operator!=(const PDTTestObject &rhs) const {
        return !(rhs == *this);
    }

    friend bool operator>(const PDTTestObject &lhs, const PDTTestObject &rhs) {
        return lhs.x > rhs.x;
    }

    friend bool operator<(const PDTTestObject &lhs, const PDTTestObject &rhs) {
        return lhs.x < rhs.x;
    }

    friend bool operator<=(const PDTTestObject &lhs, const PDTTestObject &rhs) {
        return lhs.x <= rhs.x;
    }

    friend bool operator>=(const PDTTestObject &lhs, const PDTTestObject &rhs) {
        return lhs.x >= rhs.x;
    }

    PDTTestObject() {
        x = std::rand() ;
        y = std::rand() ;
        z = std::rand() ;
//        std::cout << *this << std::endl;
    }

    PDTTestObject(int x, double y, float z) : x(x), y(y), z(z) {}

    friend std::ostream &operator<<(std::ostream &os, const PDTTestObject &object) {
        os.setf(std::ios::right);
        os << " x: " << std::setw(5) << object.x
           << " y: " << std::setw(5) << object.y
           << " z: " << std::setw(5)
           << object.z;
        return os;
    }
};

#endif //LAB4_PDTTESTOBJECT_H
