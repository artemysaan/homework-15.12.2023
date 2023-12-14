#include <iostream>
#include <string>

class Reservoir {

private:

    std::string name;

    double width;

    double length;

    double maxDepth;


public:

    Reservoir() {

        name = "";

        width = 0.0;

        length = 0.0;

        maxDepth = 0.0;

    }



    Reservoir(std::string n, double w, double l, double d) {

        name = n;

        width = w;

        length = l;

        maxDepth = d;

    }

    ~Reservoir() {

        std::cout << "Reservoir destroyed" << std::endl;

    }

    Reservoir(const Reservoir& other) {

        name = other.name;

        width = other.width;

        length = other.length;

        maxDepth = other.maxDepth;

    }

    std::string getName() const {

        return name;

    }



    void setName(std::string n) {

        name = n;

    }



    double getWidth() const {

        return width;

    }



    void setWidth(double w) {

        width = w;

    }



    double getLength() const {

        return length;

    }



    void setLength(double l) {

        length = l;

    }



    double getMaxDepth() const {

        return maxDepth;

    }



    void setMaxDepth(double d) {

        maxDepth = d;

    }

    double getVolume() const {

        return width * length * maxDepth;

    }

    double getSurfaceArea() const {

        return width * length;

    }

    bool sameType(const Reservoir& other) const {

        if ((name == "Море" && other.name == "Море") || (name == "Бассейн" && other.name == "Бассейн")) {

            return true;

        }

        else if ((name == "Пруд" && other.name == "Пруд") || (name == "Река" && other.name == "Река")) {

            return true;

        }

        else {

            return false;

        }

    }

    bool operator==(const Reservoir& other) const {

        return getSurfaceArea() == other.getSurfaceArea();

    }

    Reservoir copy() const {

        return Reservoir(name, width, length, maxDepth);

    }

};



int main() {

    Reservoir r1("Море", 10.0, 20.0, 5.0);

    Reservoir r2("Бассейн", 5.0, 5.0, 3.0);

    std::cout << "Объем первого водоема: " << r1.getVolume() << std::endl;

    std::cout << "Объем второго водоема: " << r2.getVolume() << std::endl;

    std::cout << "Площадь первого водоема: " << r1.getSurfaceArea() << std::endl;

    std::cout << "Площадь второго водоема: " << r2.getSurfaceArea() << std::endl;


    if (r1.sameType(r2)) {

        std::cout << "Водоемы относятся к одному типу" << std::endl;

    }

    else {

        std::cout << "Водоемы относятся к разным типам" << std::endl;

    }

    if (r1 == r2) {

        std::cout << "Площади водных поверхностей равны" << std::endl;

    }

    else {

        std::cout << "Площади водных поверхностей не равны" << std::endl;

    }

    Reservoir r3 = r1.copy();

    std::cout << "Название третьего водоема: " << r3.getName() << std::endl;

    std::cout << "Ширина третьего водоема: " << r3.getWidth() << std::endl;

    std::cout << "Длина третьего водоема: " << r3.getLength() << std::endl;

    std::cout << "Максимальная глубина третьего водоема: " << r3.getMaxDepth() << std::endl;



    return 0;

}
