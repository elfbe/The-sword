#include "knight2.h"
/* * * BEGIN implementation of class BaseBag * * */

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const 
{
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    string s("");
    s   += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
    ArmyKnights::ArmyKnights(const string & file_armyknights)
    {
        knights.clear();
        std::fstream file(file_armyknights, std::ios::in);
        std::string str;
        std::getline(file, str);
        std::size_t num = 0;
        for(char ch : str){
            num *= 10;
            num += (ch - '0');
        }
        while(num--){
            std::getline(file, str);
            unsigned data[5] = {0, 0, 0, 0, 0};
            unsigned* cur = data;
            for(char ch : str){
                if(ch == ' ') {
                    ++cur;
                    continue;
                }
                (*cur) *= 10;
                (*cur) += (ch - '0');
            }
            knights.push_back(BaseKnight(data[0], data[1], data[2], data[3], data[4]));
        }
        file.close();
    }

    int ArmyKnights::count() const
    {
        return 0;
    }
    BaseKnight * ArmyKnights::lastKnight() const
    {
        return 0;
    }
    bool ArmyKnights::hasPaladinShield() const
    {
        return 0;
    }
    bool ArmyKnights::hasLancelotSpear() const
    {
        return 0;
    }
    bool ArmyKnights::hasGuinevereHair() const
    {
        return 0;
    }
    bool ArmyKnights::hasExcaliburSword() const
    {
        return 0;
    }

void ArmyKnights::printInfo() const 
{
    cout << "No. knights: " << knights.length();
    if (!knights.empty()) 
    {
        for(const BaseKnight& kn : knights){
            std::cout << "Knight:\n\tHP:\t" << kn.hp
                << "\n\tLEVEL:\t" << kn.maxhp
                << "\n\tPhenonixDownL:\t" << kn.level
                << "\n\tGil:\t" << kn.gil
                << "\n\tAntidote:\t" << kn.antidote
                << '\n';
        }
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
KnightAdventure::~KnightAdventure()
{

}
void KnightAdventure::loadArmyKnights(const string & file_armyknights)
{
    armyKnights = new ArmyKnights(file_armyknights);
}
void KnightAdventure::loadEvents(const string &)
{

}
void KnightAdventure::run()
{
    armyKnights->printInfo();
    std::cout << "okay" << std::endl;
}

/* * * END implementation of class KnightAdventure * * */