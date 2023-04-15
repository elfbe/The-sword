#pragma once 
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<array>
#include<string>
// #define DEBUG

enum ItemType{/* TODO: */
};

class BaseItem;
class BaseBag{
    public:
    virtual bool insertFirst(BaseItem* item);
    virtual BaseItem* get(ItemType itemType);
    virtual std::string toString() const;
};

class BaseOpponent;

enum class KnightType : size_t{
    PALADIN=0u,LANCELOT=1u,DRAGON=2u,NORMAL=3u
};
class BaseKnight{
    protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    BaseBag* bag;
    KnightType knightType;

    public:
    static BaseKnight* create(int id,int maxhp,int level,int gil,int antidote,int phoenixdownI);
    std::string toString() const;
};
class Events;
class playerTeam{
    bool psh;
    bool lls;
    bool gnh;
    bool ecs;
    public:
    playerTeam(const std::string& file_armyknights);
    bool fight(BaseOpponent* opponent);
    bool adventure(Events* events);
    int count() const;
    BaseKnight* lastKnight() const;

    bool hasPaladinShield() const{return psh;}
    bool hasLancelotSpear() const{return lls;}
    bool hasGuinevereHair() const{return gnh;}
    bool hasExcaliburSword() const{return ecs;}

    void printInfo() const;
    void printResult(bool win) const;
};

class BaseItem{
    public:
    virtual bool canUse(BaseKnight* knight) = 0;
    virtual void use(BaseKnight* knight) = 0;
};

class Events{
    public:
    int count() const;
    int get(int i) const;
};

class KnightAdventure{
    private:
    std::vector<playerTeam> armyKnights;
    std::vector<Events> events;

    public:
    KnightAdventure();
    ~KnightAdventure();

    void loadArmyKnights(const std::string&);
    void loadEvents(const std::string&);
    void run();
};
