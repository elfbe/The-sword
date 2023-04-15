#include "knight2.h"

std::string BaseKnight::toString() const{
    static/*make it static*/ std::array<std::string,4>/*use C++ array*/ typeString = { "PALADIN","LANCELOT","DRAGON","NORMAL" };
    std::string s;
    s += "[Knight:id:"+std::to_string(id)
        +",hp:"+std::to_string(hp)
        +",maxhp:"+std::to_string(maxhp)
        +",level:"+std::to_string(level)
        +",gil:"+std::to_string(gil)
        +","+bag->toString()
        +",knight_type:"+typeString[static_cast<size_t>/*cast it*/(knightType)]
        +"]";
    return s;
}
playerTeam::playerTeam(const std::string& file_armyknights){

}

int playerTeam::count() const{
    return 0;
}
BaseKnight* playerTeam::lastKnight() const{
    return 0;
}

void playerTeam::printInfo() const{
    std::cout<<"No. knights: "<<this->count();
    if(this->count()>0){
        BaseKnight* lknight = lastKnight(); // last knight
        std::cout<<";"<<lknight->toString();
    }
    std::cout<< ";PaladinShield:"<<this->hasPaladinShield()
             << ";LancelotSpear:"<<this->hasLancelotSpear()
             << ";GuinevereHair:"<<this->hasGuinevereHair()
             << ";ExcaliburSword:"<<this->hasExcaliburSword()
             << std::endl
             << std::string(50,'-')<<std::endl;
}
void playerTeam::printResult(bool win) const{
    std::cout << (win?"WIN":"LOSE") << std::endl;
}
KnightAdventure::KnightAdventure(){
    armyKnights = nullptr;
    events = nullptr;
}
KnightAdventure::~KnightAdventure(){

}
void KnightAdventure::loadArmyKnights(const std::string& file_armyknights){
    std::ifstream(knights);
    int numKnights;
    knights.open(file_armyknights,std::ios::in);
    knights>>numKnights;
    knights.ignore();

    std::vector<std::string> knightinfo(numKnights);
    for(int i = 0; i<numKnights; i++){
        getline(knights,knightinfo[i]);
        std::stringstream ss(knightinfo[i]);
        int HP,level,phoenixdownI,gil,antidote;
        ss>>HP>>level>>phoenixdownI>>gil>>antidote;
        BaseKnight::create(1,HP,level,gil,antidote,phoenixdownI);

    }
    knights.close();
}
void KnightAdventure::loadEvents(const std::string&){

}
void KnightAdventure::run(){
    // armyKnights->printInfo();
}
