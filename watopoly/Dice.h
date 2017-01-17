#ifndef WATOPOLY_DICE_H
#define WATOPOLY_DICE_H

class Dice {
    bool doubleRoll;
    int value;
public:
    Dice();
    void setValue();
    int getValue();
    bool getDoubleRoll();
    void setDoubleRoll(bool b);
    virtual ~Dice();
};


#endif //WATOPOLY_DICE_H
