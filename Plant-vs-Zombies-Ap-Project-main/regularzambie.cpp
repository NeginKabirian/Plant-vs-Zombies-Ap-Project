#include "regularzambie.h"

RegularZambie::RegularZambie(QObject *parent)
    : ZombieBase{parent}
{}

RegularZambie::RegularZambie() :ZombieBase(500,1,25,1,100){}
