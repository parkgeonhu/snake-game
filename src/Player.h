/**
 * @file Player.h
 * 
 * @brief Player의 헤더 파일입니다.
 * 
 * @author parkgeonhu, mindaein
 */
#pragma once

class Player
{
public:
    int lengthScore = 0;
    int growScore = 0;
    int poisonScore = 0;
    int gateScore = 0;
    int totalScore = 0;

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
