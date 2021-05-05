#include "test.h"

#include "animal_atd.h"
#include "beast_atd.h"
#include "bird_atd.h"
#include "container_atd.h"
#include "fish_atd.h"
#include "node_atd.h"

namespace Animals
{
void container_out(Container * C, ofstream & ofst);
bool node_out(Node * N, ofstream & ofst);
bool animal_out(Animal * A, ofstream & ofst);
bool fish_out(Fish * F, ofstream & ofst);
bool bird_out(Bird * B, ofstream & ofst);
bool beast_out(Beast * B, ofstream & ofst);
void container_out_fish(Container * C, ofstream & ofst);
bool container_in(Container * C, ifstream & ifst);
Node * node_in(ifstream & ifst);
Animal * animal_in(ifstream & ifst);
Fish * fish_in(ifstream & ifst);
Bird * bird_in(ifstream & ifst);
Beast * beast_in(ifstream & ifst);
void container_init(Container * C);
void container_clear(Container * C);
void container_sort(Container * C);
bool animal_compare(Animal * FirstA, Animal * SecondA);
int animal_length_name(Animal * A);
}

using namespace Animals;

string TestProject::ReadFile(string FileName)
{
    ifstream ifst(FileName);
    if (ifst.is_open())
    {
        string Data;
        string TMP;
        while (getline(ifst, TMP))
        {
            Data += TMP;
        }
        ifst.close();
        return Data;
    }
    else
    {
        ifst.close();
        return NULL;
    }
}

void TestProject::TestContainerOut()
{
    Container * C = new Container;
    C->Size = 3;

    Fish * FirstFish = new Fish;
    FirstFish->Name = "carp";
    FirstFish->Place = RIVER;
    FirstFish->Age = 1;
    Animal * FirstAnimal = (Animal *)FirstFish;
    FirstAnimal->Key = FISH;
    Node * FirstNode = new Node;
    FirstNode->A = FirstAnimal;
    FirstNode->PrevNode = NULL;

    Bird * FirstBird = new Bird;
    FirstBird->Name = "dove";
    FirstBird->AttitudeFlight = NONMIGRATORY;
    FirstBird->Age = 2;
    Animal * SecondAnimal = (Animal *)FirstBird;
    SecondAnimal->Key = BIRD;
    Node * SecondNode = new Node;
    SecondNode->A = SecondAnimal;
    SecondNode->PrevNode = FirstNode;
    FirstNode->NextNode = SecondNode;

    Beast * FirstBeast = new Beast;
    FirstBeast->Name = "wolf";
    FirstBeast->D = PREDATOR;
    FirstBeast->Age = 3;
    Animal * ThirdAnimal = (Animal *)FirstBeast;
    ThirdAnimal->Key = BEAST;
    Node * ThirdNode = new Node;
    ThirdNode->A = ThirdAnimal;
    ThirdNode->PrevNode = SecondNode;
    SecondNode->NextNode = ThirdNode;
    ThirdNode->NextNode = NULL;
    C->LastNode = ThirdNode;

    ofstream ofst("OUT.txt");
    container_out(C, ofst);
    ofst.close();

    Node * N = C->LastNode;
    Node * TMP;
    while (N != NULL)
    {
        TMP = N->PrevNode;
        switch (N->A->Key)
        {
        case FISH:
            delete (Fish *)N->A;
            break;
        case BIRD:
            delete (Bird *)N->A;
            break;
        case BEAST:
            delete (Beast *)N->A;
            break;
        default:
            delete N->A;
            break;
        }
        delete N;
        N = TMP;
    }
    C->LastNode = NULL;
    C->Size = 0;
    delete C;

    string Result = ReadFile("OUT.txt");
    string Reference = ReadFile("TestContainerOut.txt");
    QCOMPARE(Result, Reference);
}

void TestProject::TestNodeOut()
{
    Fish * FirstFish = new Fish;
    FirstFish->Name = "carp";
    FirstFish->Place = RIVER;
    FirstFish->Age = 1;
    Animal * FirstAnimal = (Animal *)FirstFish;
    FirstAnimal->Key = FISH;
    Node * FirstNode = new Node;
    FirstNode->A = FirstAnimal;
    FirstNode->NextNode = NULL;
    FirstNode->PrevNode = NULL;

    ofstream ofst("OUT.txt");
    node_out(FirstNode, ofst);
    ofst.close();

    delete FirstFish;
    delete FirstNode;

    string Result = ReadFile("OUT.txt");
    string Reference = ReadFile("TestNodeOut.txt");
    QCOMPARE(Result, Reference);
}

void TestProject::TestAnimalOut()
{
    Fish * FirstFish = new Fish;
    FirstFish->Name = "carp";
    FirstFish->Place = RIVER;
    FirstFish->Age = 1;
    Animal * FirstAnimal = (Animal *)FirstFish;
    FirstAnimal->Key = FISH;

    ofstream ofst("OUT.txt");
    animal_out(FirstAnimal, ofst);
    ofst.close();

    delete FirstFish;

    string Result = ReadFile("OUT.txt");
    string Reference = ReadFile("TestAnimalOut.txt");
    QCOMPARE(Result, Reference);
}

void TestProject::TestFishOut()
{
    Fish * FirstFish = new Fish;
    FirstFish->Name = "carp";
    FirstFish->Place = RIVER;
    FirstFish->Age = 1;
    FirstFish->Key = FISH;

    ofstream ofst("OUT.txt");
    fish_out(FirstFish, ofst);
    ofst.close();

    delete FirstFish;

    string Result = ReadFile("OUT.txt");
    string Reference = ReadFile("TestFishOut.txt");
    QCOMPARE(Result, Reference);
}

void TestProject::TestBirdOut()
{
    Bird * FirstBird = new Bird;
    FirstBird->Name = "dove";
    FirstBird->AttitudeFlight = NONMIGRATORY;
    FirstBird->Age = 2;
    FirstBird->Key = BIRD;

    ofstream ofst("OUT.txt");
    bird_out(FirstBird, ofst);
    ofst.close();

    delete FirstBird;

    string Result = ReadFile("OUT.txt");
    string Reference = ReadFile("TestBirdOut.txt");
    QCOMPARE(Result, Reference);
}

void TestProject::TestBeastOut()
{
    Beast * FirstBeast = new Beast;
    FirstBeast->Name = "wolf";
    FirstBeast->D = PREDATOR;
    FirstBeast->Age = 3;
    FirstBeast->Key = BEAST;

    ofstream ofst("OUT.txt");
    beast_out(FirstBeast, ofst);
    ofst.close();

    delete FirstBeast;

    string Result = ReadFile("OUT.txt");
    string Reference = ReadFile("TestBeastOut.txt");
    QCOMPARE(Result, Reference);
}

void TestProject::TestContainerOutFish()
{
    Container * C = new Container;
    C->Size = 3;

    Fish * FirstFish = new Fish;
    FirstFish->Name = "carp";
    FirstFish->Place = RIVER;
    FirstFish->Age = 1;
    Animal * FirstAnimal = (Animal *)FirstFish;
    FirstAnimal->Key = FISH;
    Node * FirstNode = new Node;
    FirstNode->A = FirstAnimal;
    FirstNode->PrevNode = NULL;

    Bird * FirstBird = new Bird;
    FirstBird->Name = "dove";
    FirstBird->AttitudeFlight = NONMIGRATORY;
    FirstBird->Age = 2;
    Animal * SecondAnimal = (Animal *)FirstBird;
    SecondAnimal->Key = BIRD;
    Node * SecondNode = new Node;
    SecondNode->A = SecondAnimal;
    SecondNode->PrevNode = FirstNode;
    FirstNode->NextNode = SecondNode;

    Beast * FirstBeast = new Beast;
    FirstBeast->Name = "wolf";
    FirstBeast->D = PREDATOR;
    FirstBeast->Age = 3;
    Animal * ThirdAnimal = (Animal *)FirstBeast;
    ThirdAnimal->Key = BEAST;
    Node * ThirdNode = new Node;
    ThirdNode->A = ThirdAnimal;
    ThirdNode->PrevNode = SecondNode;
    SecondNode->NextNode = ThirdNode;
    ThirdNode->NextNode = NULL;
    C->LastNode = ThirdNode;

    ofstream ofst("OUT.txt");
    container_out_fish(C, ofst);
    ofst.close();

    container_clear(C);
    delete C;

    string Result = ReadFile("OUT.txt");
    string Reference = ReadFile("TestContainerOutFish.txt");
    QCOMPARE(Result, Reference);
}

void TestProject::TestContainerIn()
{
    Container * C = new Container;
    C->Size = 0;
    C->LastNode = NULL;
    ifstream ifst("TestContainerIn.txt");
    container_in(C, ifst);

    if ((C->Size == 3) && (C->LastNode != NULL))
    {
        ifst.close();

        Container * ContainerReference = new Container;
        ContainerReference->Size = 3;

        Fish * FirstFish = new Fish;
        FirstFish->Name = "carp";
        FirstFish->Place = RIVER;
        FirstFish->Age = 1;
        Animal * FirstAnimal = (Animal *)FirstFish;
        FirstAnimal->Key = FISH;
        Node * FirstNode = new Node;
        FirstNode->A = FirstAnimal;
        FirstNode->PrevNode = NULL;

        Bird * FirstBird = new Bird;
        FirstBird->Name = "dove";
        FirstBird->AttitudeFlight = NONMIGRATORY;
        FirstBird->Age = 2;
        Animal * SecondAnimal = (Animal *)FirstBird;
        SecondAnimal->Key = BIRD;
        Node * SecondNode = new Node;
        SecondNode->A = SecondAnimal;
        SecondNode->PrevNode = FirstNode;
        FirstNode->NextNode = SecondNode;

        Beast * FirstBeast = new Beast;
        FirstBeast->Name = "wolf";
        FirstBeast->D = PREDATOR;
        FirstBeast->Age = 3;
        Animal * ThirdAnimal = (Animal *)FirstBeast;
        ThirdAnimal->Key = BEAST;
        Node * ThirdNode = new Node;
        ThirdNode->A = ThirdAnimal;
        ThirdNode->PrevNode = SecondNode;
        SecondNode->NextNode = ThirdNode;
        ThirdNode->NextNode = NULL;
        ContainerReference->LastNode = ThirdNode;

        Node * TMPNode = C->LastNode;
        Animal * TMPAnimal = TMPNode->A;
        Node * TMPNodeReference = ContainerReference->LastNode;
        Animal * TMPAnimalReference = TMPNodeReference->A;
        while(TMPNodeReference != NULL)
        {
            TMPAnimal = TMPNode->A;
            TMPAnimalReference = TMPNodeReference->A;

            QCOMPARE(TMPAnimal->Key, TMPAnimalReference->Key);
            QCOMPARE(TMPAnimal->Name, TMPAnimalReference->Name);
            QCOMPARE(TMPAnimal->Age, TMPAnimalReference->Age);
            switch (TMPAnimalReference->Key)
            {
            case FISH:
            {
                Fish * TMPFish = (Fish *)TMPAnimal;
                Fish * TMPFishReference = (Fish *)TMPAnimalReference;
                QCOMPARE(TMPFish->Place, TMPFishReference->Place);
                break;
            }
            case BIRD:
            {
                Bird * TMPBird = (Bird *)TMPAnimal;
                Bird * TMPBirdReference = (Bird *)TMPAnimalReference;
                QCOMPARE(TMPBird->AttitudeFlight, TMPBirdReference->AttitudeFlight);
                break;
            }
            case BEAST:
            {
                Beast * TMPBeast = (Beast *)TMPAnimal;
                Beast * TMPBeastReference = (Beast *)TMPAnimalReference;
                QCOMPARE(TMPBeast->D, TMPBeastReference->D);
                break;
            }
            }
            TMPNodeReference = TMPNodeReference->PrevNode;
            TMPNode = TMPNode->PrevNode;
        }

        QVERIFY(TMPNode == NULL);

        TMPNode = C->LastNode;
        Node * TMP;
        while (TMPNode != NULL)
        {
            TMP = TMPNode->PrevNode;
            switch (TMPNode->A->Key)
            {
            case FISH:
                delete (Fish *)TMPNode->A;
                break;
            case BIRD:
                delete (Bird *)TMPNode->A;
                break;
            case BEAST:
                delete (Beast *)TMPNode->A;
                break;
            default:
                delete TMPNode->A;
                break;
            }
            delete TMPNode;
            TMPNode = TMP;
        }
        C->LastNode = NULL;
        C->Size = 0;
        delete C;

        TMPNode = ContainerReference->LastNode;
        while (TMPNode != NULL)
        {
            TMP = TMPNode->PrevNode;
            switch (TMPNode->A->Key)
            {
            case FISH:
                delete (Fish *)TMPNode->A;
                break;
            case BIRD:
                delete (Bird *)TMPNode->A;
                break;
            case BEAST:
                delete (Beast *)TMPNode->A;
                break;
            default:
                delete TMPNode->A;
                break;
            }
            delete TMPNode;
            TMPNode = TMP;
        }
        ContainerReference->LastNode = NULL;
        ContainerReference->Size = 0;
        delete ContainerReference;
    }
    else
    {
        ifst.close();
        QCOMPARE(true, false);
    }
}

void TestProject::TestNodeIn()
{
    ifstream ifst("TestNodeIn.txt");
    Node * N = node_in(ifst);

    if (N != NULL)
    {
        ifst.close();

        Fish * FirstFish = new Fish;
        FirstFish->Name = "carp";
        FirstFish->Place = RIVER;
        FirstFish->Age = 1;
        Animal * FirstAnimal = (Animal *)FirstFish;
        FirstAnimal->Key = FISH;
        Node * FirstNode = new Node;
        FirstNode->A = FirstAnimal;
        FirstNode->NextNode = NULL;
        FirstNode->PrevNode = NULL;

        QCOMPARE(N->A->Key, FirstNode->A->Key);
        QCOMPARE(N->A->Name, FirstNode->A->Name);
        QCOMPARE(N->A->Age, FirstNode->A->Age);
        if (N->A->Key == FirstNode->A->Key)
        {
            Fish * TMPFish = (Fish *)N->A;
            Fish * TMPFishReference = (Fish *)FirstNode->A;
            QCOMPARE(TMPFish->Place, TMPFishReference->Place);
        }

        QVERIFY(N->NextNode == NULL);
        QVERIFY(N->PrevNode == NULL);

        delete FirstFish;
        delete FirstNode;

        switch (N->A->Key)
        {
        case FISH:
            delete (Fish *)N->A;
            break;
        case BIRD:
            delete (Bird *)N->A;
            break;
        case BEAST:
            delete (Beast *)N->A;
            break;
        default:
            delete N->A;
            break;
        }
        delete N;
    }
    else
    {
        ifst.close();
        QCOMPARE(true, false);
    }
}

void TestProject::TestAnimalIn()
{
    ifstream ifst("TestAnimalIn.txt");
    Animal * A = animal_in(ifst);
    if(A != NULL)
    {
        ifst.close();

        Fish * FirstFish = new Fish;
        FirstFish->Name = "carp";
        FirstFish->Place = RIVER;
        FirstFish->Age = 1;
        Animal * FirstAnimal = (Animal *)FirstFish;
        FirstAnimal->Key = FISH;

        QCOMPARE(A->Key, FirstAnimal->Key);
        QCOMPARE(A->Name, FirstAnimal->Name);
        QCOMPARE(A->Age, FirstAnimal->Age);
        if (A->Key == FirstAnimal->Key)
        {
            Fish * TMPFish = (Fish *)A;
            Fish * TMPFishReference = (Fish *)FirstAnimal;
            QCOMPARE(TMPFish->Place, TMPFishReference->Place);
        }

        delete FirstFish;

        switch (A->Key)
        {
        case FISH:
            delete (Fish *)A;
            break;
        case BIRD:
            delete (Bird *)A;
            break;
        case BEAST:
            delete (Beast *)A;
            break;
        default:
            delete A;
            break;
        }
    }
    else
    {
        ifst.close();
        QCOMPARE(true, false);
    }
}

void TestProject::TestFishIn()
{
    ifstream ifst("TestFishIn.txt");
    Fish * F = fish_in(ifst);

    if (F != NULL)
    {
        ifst.close();

        Fish * FirstFish = new Fish;
        FirstFish->Name = "carp";
        FirstFish->Place = RIVER;
        FirstFish->Age = 1;

        QCOMPARE(F->Name, FirstFish->Name);
        QCOMPARE(F->Age, FirstFish->Age);
        QCOMPARE(F->Place, FirstFish->Place);

        delete FirstFish;
        delete F;
    }
    else
    {
        ifst.close();
        QCOMPARE(true, false);
    }
}

void TestProject::TestBirdIn()
{
    ifstream ifst("TestBirdIn.txt");
    Bird * B = bird_in(ifst);

    if (B != NULL)
    {
        ifst.close();

        Bird * FirstBird = new Bird;
        FirstBird->Name = "dove";
        FirstBird->AttitudeFlight = NONMIGRATORY;
        FirstBird->Age = 2;

        QCOMPARE(B->Name, FirstBird->Name);
        QCOMPARE(B->Age, FirstBird->Age);
        QCOMPARE(B->AttitudeFlight, FirstBird->AttitudeFlight);

        delete FirstBird;
        delete B;
    }
    else
    {
        ifst.close();
        QCOMPARE(true, false);
    }
}

void TestProject::TestBeastIn()
{
    ifstream ifst("TestBeastIn.txt");
    Beast * B = beast_in(ifst);

    if (B != NULL)
    {
        ifst.close();

        Beast * FirstBeast = new Beast;
        FirstBeast->Name = "wolf";
        FirstBeast->D = PREDATOR;
        FirstBeast->Age = 3;

        QCOMPARE(B->Name, FirstBeast->Name);
        QCOMPARE(B->Age, FirstBeast->Age);
        QCOMPARE(B->D, FirstBeast->D);

        delete FirstBeast;
        delete B;
    }
    else
    {
        ifst.close();
        QCOMPARE(true, false);
    }
}

void TestProject::TestContainerInit()
{
    Container * C = new Container;
    container_init(C);

    QCOMPARE(C->Size, 0);
    QVERIFY(C->LastNode == NULL);

    delete C;
}

void TestProject::TestContainerClear()
{
    Container * C = new Container;
    C->Size = 3;

    Fish * FirstFish = new Fish;
    FirstFish->Name = "carp";
    FirstFish->Place = RIVER;
    FirstFish->Age = 1;
    Animal * FirstAnimal = (Animal *)FirstFish;
    FirstAnimal->Key = FISH;
    Node * FirstNode = new Node;
    FirstNode->A = FirstAnimal;
    FirstNode->PrevNode = NULL;

    Bird * FirstBird = new Bird;
    FirstBird->Name = "dove";
    FirstBird->AttitudeFlight = NONMIGRATORY;
    FirstBird->Age = 2;
    Animal * SecondAnimal = (Animal *)FirstBird;
    SecondAnimal->Key = BIRD;
    Node * SecondNode = new Node;
    SecondNode->A = SecondAnimal;
    SecondNode->PrevNode = FirstNode;
    FirstNode->NextNode = SecondNode;

    Beast * FirstBeast = new Beast;
    FirstBeast->Name = "wolf";
    FirstBeast->D = PREDATOR;
    FirstBeast->Age = 3;
    Animal * ThirdAnimal = (Animal *)FirstBeast;
    ThirdAnimal->Key = BEAST;
    Node * ThirdNode = new Node;
    ThirdNode->A = ThirdAnimal;
    ThirdNode->PrevNode = SecondNode;
    SecondNode->NextNode = ThirdNode;
    ThirdNode->NextNode = NULL;
    C->LastNode = ThirdNode;

    container_clear(C);

    QCOMPARE(C->Size, 0);
    QVERIFY(C->LastNode == NULL);

    delete C;
}

void TestProject::TestContainerSort()
{
    Container * C = new Container;
    C->Size = 3;

    Fish * FirstFish = new Fish;
    FirstFish->Name = "salmon";
    FirstFish->Place = RIVER;
    FirstFish->Age = 1;
    Animal * FirstAnimal = (Animal *)FirstFish;
    FirstAnimal->Key = FISH;
    Node * FirstNode = new Node;
    FirstNode->A = FirstAnimal;
    FirstNode->PrevNode = NULL;

    Bird * FirstBird = new Bird;
    FirstBird->Name = "eagle";
    FirstBird->AttitudeFlight = NONMIGRATORY;
    FirstBird->Age = 2;
    Animal * SecondAnimal = (Animal *)FirstBird;
    SecondAnimal->Key = BIRD;
    Node * SecondNode = new Node;
    SecondNode->A = SecondAnimal;
    SecondNode->PrevNode = FirstNode;
    FirstNode->NextNode = SecondNode;

    Beast * FirstBeast = new Beast;
    FirstBeast->Name = "wolf";
    FirstBeast->D = PREDATOR;
    FirstBeast->Age = 3;
    Animal * ThirdAnimal = (Animal *)FirstBeast;
    ThirdAnimal->Key = BEAST;
    Node * ThirdNode = new Node;
    ThirdNode->A = ThirdAnimal;
    ThirdNode->PrevNode = SecondNode;
    SecondNode->NextNode = ThirdNode;
    ThirdNode->NextNode = NULL;
    C->LastNode = ThirdNode;

    container_sort(C);

    Node * TMP = C->LastNode;
    QCOMPARE(TMP->A->Key, BEAST);
    QCOMPARE(TMP->A->Name, "wolf");
    QCOMPARE(TMP->A->Age, 3);
    if (TMP->A->Key == BEAST)
    {
        Beast * TMPBeast = (Beast *)TMP->A;
        QCOMPARE(TMPBeast->D, PREDATOR);
    }
    TMP = TMP->PrevNode;
    QCOMPARE(TMP->A->Key, BIRD);
    QCOMPARE(TMP->A->Name, "eagle");
    QCOMPARE(TMP->A->Age, 2);
    if (TMP->A->Key == BIRD)
    {
        Bird * TMPBird = (Bird *)TMP->A;
        QCOMPARE(TMPBird->AttitudeFlight, NONMIGRATORY);
    }
    TMP = TMP->PrevNode;
    QCOMPARE(TMP->A->Key, FISH);
    QCOMPARE(TMP->A->Name, "salmon");
    QCOMPARE(TMP->A->Age, 1);
    if (TMP->A->Key == FISH)
    {
        Fish * TMPFish = (Fish *)TMP->A;
        QCOMPARE(TMPFish->Place, RIVER);
    }

    delete FirstFish;
    delete FirstNode;
    delete FirstBird;
    delete SecondNode;
    delete FirstBeast;
    delete ThirdNode;
    delete C;
}

void TestProject::TestAnimalCompare()
{
    Fish * FirstFish = new Fish;
    FirstFish->Name = "carp";
    FirstFish->Place = RIVER;
    FirstFish->Age = 1;
    Animal * FirstAnimal = (Animal *)FirstFish;
    FirstAnimal->Key = FISH;

    Fish * SecondFish = new Fish;
    SecondFish->Name = "salmon";
    SecondFish->Place = RIVER;
    SecondFish->Age = 1;
    Animal * SecondAnimal = (Animal *)SecondFish;
    SecondAnimal->Key = FISH;

    bool Result = animal_compare(FirstAnimal, SecondAnimal);
    bool Reference = true;
    QCOMPARE(Result, Reference);

    delete FirstFish;
    delete SecondFish;
}

void TestProject::TestAnimalLengthName()
{
    Fish * FirstFish = new Fish;
    FirstFish->Name = "carp";
    FirstFish->Place = RIVER;
    FirstFish->Age = 1;
    Animal * FirstAnimal = (Animal *)FirstFish;
    FirstAnimal->Key = FISH;

    int Result = animal_length_name(FirstAnimal);
    int Reference = 4;
    QCOMPARE(Result, Reference);

    delete FirstFish;
}
