//
// Created by Zhou Yitao on 2018-12-04.
//

#ifndef HIERARCHICALSCHEDULING_PACKAGE_H
#define HIERARCHICALSCHEDULING_PACKAGE_H


class Package {
private:
    int timeStamp;
    // To Do: need to add the flow this packet packet belongs to, the packet number and the packet length

public:
    Package(int timeStamp);
    int getTimeStamp() const;
};


#endif //HIERARCHICALSCHEDULING_PACKAGE_H
