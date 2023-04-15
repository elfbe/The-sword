#include "knight2.h"

string BaseKnight::toString() const{
    string typeString[4] = { "PALADIN","LANCELOT","DRAGON","NORMAL" };
    string s("");
    s += "[Knight:id:"+to_string(id)
        +",hp:"+to_string(hp)
        +",maxhp:"+to_string(maxhp)
        +",level:"+to_string(level)
        +",gil:"+to_string(gil)
        +","+bag->toString()
        +",knight_type:"+typeString[knightType]
        +"]";
    return s;
}
ArmyKnights::ArmyKnights(const string& file_armyknights){

}

int ArmyKnights::count() const{
    return 0;
}
BaseKnight* ArmyKnights::lastKnight() const{
    return 0;
}
bool ArmyKnights::hasPaladinShield() const{
    return 0;
}
bool ArmyKnights::hasLancelotSpear() const{
    return 0;
}
bool ArmyKnights::hasGuinevereHair() const{
    return 0;
}
bool ArmyKnights::hasExcaliburSword() const{
    return 0;
}

void ArmyKnights::printInfo() const{
    cout<<"No. knights: "<<this->count();
    if(this->count()>0){
        BaseKnight* lknight = lastKnight(); // last knight
        cout<<";"<<lknight->toString();
    }
    cout<<";PaladinShield:"<<this->hasPaladinShield()
        <<";LancelotSpear:"<<this->hasLancelotSpear()
        <<";GuinevereHair:"<<this->hasGuinevereHair()
        <<";ExcaliburSword:"<<this->hasExcaliburSword()
        <<endl
        <<string(50,'-')<<endl;
}
void ArmyKnights::printResult(bool win) const{
    cout << (win?"WIN":"LOSE") << endl;
}
KnightAdventure::KnightAdventure(){
    armyKnights = nullptr;
    events = nullptr;
}
KnightAdventure::~KnightAdventure(){

}
void KnightAdventure::loadArmyKnights(const string& file_armyknights){
    ifstream(knights);
    int numKnights;
    knights.open(file_armyknights,ios::in);
    knights>>numKnights;
    knights.ignore();

    string* knightinfo = new string[numKnights];
    for(int i = 0; i<numKnights; i++){
        getline(knights,knightinfo[i]);
        stringstream ss(knightinfo[i]);
        int HP,level,phoenixdownI,gil,antidote;
        ss>>HP>>level>>phoenixdownI>>gil>>antidote;
        BaseKnight::create(1,HP,level,gil,antidote,phoenixdownI);

    }
    knights.close();
}
void KnightAdventure::loadEvents(const string&){

}
void KnightAdventure::run(){
    // armyKnights->printInfo();
}
