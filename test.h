#ifndef TEST_H
#define TEST_H

#include <QtTest>

using namespace std;

class TestProject : public QObject
{
    Q_OBJECT

public:
    string ReadFile(string);

private slots:
    void TestContainerOut();
    void TestContainerOutFish();
    void TestNodeOut();
    void TestAnimalOut();
    void TestBirdOut();
    void TestBeastOut();
    void TestFishOut();

    void TestContainerIn();
    void TestNodeIn();
    void TestAnimalIn();
    void TestBirdIn();
    void TestBeastIn();
    void TestFishIn();

    void TestContainerInit();
    void TestContainerClear();
    void TestContainerSort();
    void TestAnimalCompare();
    void TestAnimalLengthName();
};

#endif
