#include <iostream>
#include <vector>
using namespace std;

int SkillCnt;
int MonsterHP;

vector<pair<int, int>> SkillStatus;
vector<pair<int, int>> SkillInfo;

int Answer = 128;


void KillMonster(int LeftHP, int CurrentTime)
{
    if(CurrentTime >= Answer || LeftHP <= 0)
    {
        Answer = min(Answer, CurrentTime);
        return;
    }
    
    int CurrentMinCoolTime = 16;
    
    for(int i = 0; i < SkillCnt; i++)
        CurrentMinCoolTime = min(CurrentMinCoolTime, SkillStatus[i].first);
    
    if(CurrentMinCoolTime > 0)
    {
        vector<pair<int,int>> saved = SkillStatus;
        
        for(int i = 0; i < SkillCnt; i++)
        {
            SkillStatus[i].first -= CurrentMinCoolTime;
        }
            
        KillMonster(LeftHP, CurrentTime + CurrentMinCoolTime);
        SkillStatus = saved;
    }
    else
    {
        for(int i = 0; i < SkillCnt; i++)
        {
            if(SkillStatus[i].first == 0)
            {
                vector<pair<int,int>> saved = SkillStatus;
                
                for(int j = 0; j < SkillCnt; j++)
                {
                    SkillStatus[j].first = max(0, SkillStatus[j].first - 1);
                }
                
                SkillStatus[i].first = SkillInfo[i].first - 1; // 사용 시작 시점부터 C초
                KillMonster(LeftHP - SkillInfo[i].second, CurrentTime + 1);
                SkillStatus = saved;
            }
        }
    }
}

int main(){
    cin >> SkillCnt >> MonsterHP;
    SkillStatus.resize(SkillCnt);
    SkillInfo.resize(SkillCnt);
    
    for(int i = 0; i < SkillCnt; i++)
    {
        cin >> SkillInfo[i].first >> SkillInfo[i].second;
        SkillStatus[i].first = 0;
        SkillStatus[i].second = SkillInfo[i].second;
    }
    
    KillMonster(MonsterHP, 0);
    
    cout << Answer;
    
    return 0;
}