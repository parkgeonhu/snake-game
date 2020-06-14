#pragma once

class Player {
public:
    
    
    int lengthScore;
    int growScore;
    int poisonScore;
    int gateScore;
    
    Player(){
        
        lengthScore=0;
        growScore=0;
        poisonScore=0;
        gateScore=0;
    }
    ~Player() {}
    void SetLengthScore(int value) : lengthScore(value){}
    void SetGrowScore(int value) : growScore(value){}
    void SetPoisonScore(int value) : poisonScore(value){}
    void SetGateScore(int value) : gateScore(value){}
};
