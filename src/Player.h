#pragma once

class Player
{
public:
    int lengthScore;
    int growScore;
    int poisonScore;
    int gateScore;
    int totalScore;

    Player()
    {
        lengthScore = 0;
        growScore = 0;
        poisonScore = 0;
        gateScore = 0;
        totalScore = 0;
    }
    ~Player() {}
    void SetLengthScore(int value)
    {
        lengthScore = value;
    }
    void SetGrowScore(int value)
    {
        growScore = value;
    }
    void SetPoisonScore(int value)
    {
        poisonScore = value;
    }
    void SetGateScore(int value)
    {
        gateScore = value;
    }
    void SetTotalScore(int value)
    {
        totalScore = growScore * 10 - poisonScore * 5 + gateScore * 10 + value * 50 + 100;
    }
};
