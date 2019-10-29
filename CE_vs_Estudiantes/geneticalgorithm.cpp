#include "geneticalgorithm.h"
#include <random>
#include "estudiantefactory.h"
#include "concreteestudiantefactory.h"
GeneticAlgorithm::GeneticAlgorithm()
{
    poblacionInicial = new QList<Estudiante*>();
    oleada = new QList<Estudiante*>();
    seleccionados = new QList<Estudiante*>();

    generationCount = 0;
}

int GeneticAlgorithm::getGeneration()
{
    return generationCount;
}

void GeneticAlgorithm::initializePopulation()
{
    srand(time(NULL));

    ConcreteEstudianteFactory *factory = new ConcreteEstudianteFactory;

    for(int i = 0; i<30; i++){


        int seleccionadorRandom = std::rand()%100;

        if(seleccionadorRandom >= 0 && seleccionadorRandom < 50){

            int vidaRandom = 500 + (std::rand() % (1023-500+1));
            std::vector<int> vidaVector(10);
            vidaVector = decimalToBinary(vidaRandom);

            Ogro *ogro = factory->createOgroInstance(vidaVector);

            ogro->fitness = 0;
            poblacionInicial->append(ogro);
        }

        if(seleccionadorRandom >= 50 && seleccionadorRandom < 70){

            int vidaRandom = 100 + (std::rand() % (1023-100+1));
            std::vector<int> vidaVector(10);
            vidaVector = decimalToBinary(vidaRandom);

            Elfo_oscuro *elfo = factory->createElfoInstance(vidaVector);

            elfo->fitness = 0;
            poblacionInicial->append(elfo);
        }
        if(seleccionadorRandom >= 70 && seleccionadorRandom < 90){
            int vidaRandom = 100 + (std::rand() % (1023-100+1));
            std::vector<int> vidaVector(10);
            vidaVector = decimalToBinary(vidaRandom);

            Harpia *harpia = factory->createHarpiaInstance(vidaVector);

            harpia->fitness = 0;
            poblacionInicial->append(harpia);
        }
        if(seleccionadorRandom >= 90 && seleccionadorRandom < 99){
            int vidaRandom = 200 + (std::rand() % (1023-200+1));
            std::vector<int> vidaVector(10);
            vidaVector = decimalToBinary(vidaRandom);

            Mercenario *mercenario = factory->createMercenarioInstance(vidaVector);

            mercenario->fitness = 0;
            poblacionInicial->append(mercenario);
        }
    }

}


std::vector<int> GeneticAlgorithm::decimalToBinary(int n)
{

    std::vector<int> binaryNum(10);

    for(int i=0; n>0; i++){
        binaryNum.at(i) = n%2;
        n=n/2;
    }

    return binaryNum;

}

void GeneticAlgorithm::fitnessFunction()
{
    for(int i=0; i<poblacionInicial->size();i++){
        if(poblacionInicial->at(i)->getHealth()>=0 && poblacionInicial->at(i)->getHealth()<300){
            poblacionInicial->at(i)->fitness = 1;
        }
        if(poblacionInicial->at(i)->getHealth()>=300 && poblacionInicial->at(i)->getHealth()<500){
            poblacionInicial->at(i)->fitness = 2;
        }
        if(poblacionInicial->at(i)->getHealth()>=500 && poblacionInicial->at(i)->getHealth()<700){
            poblacionInicial->at(i)->fitness = 3;
        }
        if(poblacionInicial->at(i)->getHealth()>=700 && poblacionInicial->at(i)->getHealth()<900){
            poblacionInicial->at(i)->fitness = 4;
        }
        if(poblacionInicial->at(i)->getHealth()>=900 && poblacionInicial->at(i)->getHealth()<1023){
            poblacionInicial->at(i)->fitness = 5;
        }

    }

}

void GeneticAlgorithm::selection()
{
    for(int i = 0; i<poblacionInicial->size();i++){
        if(poblacionInicial->at(i)->fitness == 5 || poblacionInicial->at(i)->fitness == 4 || poblacionInicial->at(i)->fitness == 3){
            seleccionados->append(poblacionInicial->at(i));
        }
    }
}

void GeneticAlgorithm::reproduction()
{
    ConcreteEstudianteFactory *factory = new ConcreteEstudianteFactory;

    for(int i=0; i<30; i++){

        int seleccionadorRandom = std::rand()%100;


        int pos1 = std::rand()%seleccionados->size();
        int pos2 = std::rand()%seleccionados->size();


        if(seleccionadorRandom >= 0 && seleccionadorRandom < 50){

            std::vector<int> vidaPrimero = decimalToBinary(seleccionados->at(pos1)->getHealth());
            std::vector<int> vidaSegundo = decimalToBinary(seleccionados->at(pos2)->getHealth());

            std::vector<int> vidaCruce(10);

            for(int z=0; z<5; z++){
                vidaCruce.at(z) = vidaPrimero.at(z);
            }

            for(int z=0;z<9;z++){
                vidaCruce.at(z) = vidaSegundo.at(z);
            }

            Ogro *ogro = factory->createOgroInstance(vidaCruce);

            ogro->fitness = 0;
            oleada->append(ogro);
        }

        if(seleccionadorRandom >= 50 && seleccionadorRandom < 70){

            std::vector<int> vidaPrimero = decimalToBinary(seleccionados->at(pos1)->getHealth());
            std::vector<int> vidaSegundo = decimalToBinary(seleccionados->at(pos2)->getHealth());

            std::vector<int> vidaCruce(10);

            for(int z=0; z<5; z++){
                vidaCruce.at(z) = vidaPrimero.at(z);
            }

            for(int z=0;z<9;z++){
                vidaCruce.at(z) = vidaSegundo.at(z);
            }

            Elfo_oscuro *elfo = factory->createElfoInstance(vidaCruce);

            elfo->fitness = 0;
            oleada->append(elfo);
        }
        if(seleccionadorRandom >= 70 && seleccionadorRandom < 90){
            std::vector<int> vidaPrimero = decimalToBinary(seleccionados->at(pos1)->getHealth());
            std::vector<int> vidaSegundo = decimalToBinary(seleccionados->at(pos2)->getHealth());

            std::vector<int> vidaCruce(10);

            for(int z=0; z<5; z++){
                vidaCruce.at(z) = vidaPrimero.at(z);
            }

            for(int z=0;z<9;z++){
                vidaCruce.at(z) = vidaSegundo.at(z);
            }


            Harpia *harpia = factory->createHarpiaInstance(vidaCruce);

            harpia->fitness = 0;
            oleada->append(harpia);
        }
        if(seleccionadorRandom >= 90 && seleccionadorRandom < 99){
            std::vector<int> vidaPrimero = decimalToBinary(seleccionados->at(pos1)->getHealth());
            std::vector<int> vidaSegundo = decimalToBinary(seleccionados->at(pos2)->getHealth());

            std::vector<int> vidaCruce(10);

            for(int z=0; z<5; z++){
                vidaCruce.at(z) = vidaPrimero.at(z);
            }

            for(int z=0;z<9;z++){
                vidaCruce.at(z) = vidaSegundo.at(z);
            }

            Mercenario *mercenario = factory->createMercenarioInstance(vidaCruce);

            mercenario->fitness = 0;
            oleada->append(mercenario);
        }


    }

}

void GeneticAlgorithm::mutation()
{
    if(oleada->size() == 30){
        int pos = 0;
        std::cout<<oleada->size()<<std::endl;
        if(oleada->size()>0){
            pos = std::rand()%oleada->size();
        }

        int byteToChange = std::rand()%10;

        std::vector<int> vida = decimalToBinary(oleada->at(pos)->getHealth());

        oleada->at(pos)->setPixmap(oleada->at(pos)->pixmap().scaled(70,70,Qt::KeepAspectRatio));

        if(vida.at(byteToChange) == 0){
            vida.at(byteToChange) = 1;
        }
        else if(vida.at(byteToChange) == 1){
            vida.at(byteToChange) = 0;
        }

        int i;
        int output = 0;
        int power = 1;

        for(i=0; i<10; i++){
            output += vida.at(9-i)*power;
            power *=2;
        }

        oleada->at(pos)->setHealth(output);

    }

}

void GeneticAlgorithm::inversion()
{
    if(oleada->size() == 30){
        int pos = 0;
        if(oleada->size()>0){
            pos = std::rand()%oleada->size();
        }

        int byteToChange1 = std::rand()%10;
        int byteToChange2 = std::rand()%10;
        int byteToChange3 = std::rand()%10;
        int byteToChange4 = std::rand()%10;

        std::vector<int> vida = decimalToBinary(oleada->at(pos)->getHealth());

        oleada->at(pos)->setPixmap(oleada->at(pos)->pixmap().scaled(70,70,Qt::KeepAspectRatio));

        if(vida.at(byteToChange1) == 0){
            vida.at(byteToChange1) = 1;
        }
        else if(vida.at(byteToChange1) == 1){
            vida.at(byteToChange1) = 0;
        }

        if(vida.at(byteToChange2) == 0){
            vida.at(byteToChange2) = 1;
        }
        else if(vida.at(byteToChange2) == 1){
            vida.at(byteToChange2) = 0;
        }

        if(vida.at(byteToChange3) == 0){
            vida.at(byteToChange3) = 1;
        }
        else if(vida.at(byteToChange3) == 1){
            vida.at(byteToChange3) = 0;
        }

        if(vida.at(byteToChange4) == 0){
            vida.at(byteToChange4) = 1;
        }
        else if(vida.at(byteToChange4) == 1){
            vida.at(byteToChange4) = 0;
        }

        int i;
        int output = 0;
        int power = 1;

        for(i=0; i<10; i++){
            output += vida.at(9-i)*power;
            power *=2;
        }

        oleada->at(pos)->setHealth(output);
    }
}

void GeneticAlgorithm::setNextPopulation(QList<Estudiante *> *newPop)
{
    poblacionInicial = newPop;
}

QList<Estudiante *>* GeneticAlgorithm::getOleada()
{
    return oleada;
}




