#ifndef C_MONSTER_H
#define C_MONSTER_H

#include <cmath>
#include <QObject>
#include <QString>
#include <QList>
#include "pq7_config.h"
#include <iostream>
#include <fstream>

class c_Monster : public QObject
{
    Q_OBJECT
public:
    explicit c_Monster(QObject *parent = 0);

    QString Discription();
    QString Level();

    QStringList Drops();

    bool makeByLevel(int level);
    bool makeLevelRange(int lowest_level, int highest_level);
    bool makeMounted(int level);
    bool makeMountedRange(int lowest_level, int highest_level);
    bool makeGroup(int level);

    qulonglong winXP();

    void makeSpecial(int level);

    void addHealth();
    void addAge();
    void addCast();
    void addSize();

    bool isMounted;
    bool isGroup;
    bool isSpecial;

    void clear();
    QJsonObject save();
    void load(QJsonObject monsterRoot);

signals:
    
public slots:

private:

    // base information
    QString monster_race;
    int monster_level;

    // modifer adjustments
    QStringList mods;
    QList<int> mod_values;

    QStringList drops;

    QString discription;
    QString level;
    qulonglong awardXP;

    bool dropsFormatted;

    void makeRandMonster();
    QStringList pickSpcByLevel(int level);

    // save / load helpers
    QJsonArray modListToArray(QStringList &mList, QList<int> &vList);
    QJsonArray dropListToArray(QStringList &list);
    void arrayToModList(QJsonArray array, QStringList &mList, QList<int> &vList);
    QStringList arrayToDropList(QJsonArray array);

};

#endif // C_MONSTER_H
