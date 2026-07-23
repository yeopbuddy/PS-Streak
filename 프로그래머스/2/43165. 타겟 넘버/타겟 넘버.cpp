#include <string>
#include <vector>

using namespace std;

vector<int> ga32_numbers;

int gs32_answer = 0;
int gs32_target, gs32_vectorsize;


void dfs(int s32_curidx, int s32_curval, int s32_leftval)
{
    // 가지치기: 남은 숫자들을 다 더하거나 다 빼도 목표 숫자보다 작거나 클 경우 -> break
    if(s32_curidx == gs32_vectorsize)
    {
        if(s32_curval == gs32_target)
        {
            ++gs32_answer;
        }
        return;
    }
    
    if(s32_curval + s32_leftval < gs32_target || s32_curval - s32_leftval > gs32_target)
    {
        return;
    }
    dfs(s32_curidx + 1, s32_curval + ga32_numbers[s32_curidx], s32_leftval - ga32_numbers[s32_curidx]);
    dfs(s32_curidx + 1, s32_curval - ga32_numbers[s32_curidx], s32_leftval - ga32_numbers[s32_curidx]);
}

int solution(vector<int> numbers, int target) {
    
    int s32_vectorsum = 0;
    
    ga32_numbers = numbers;
    gs32_target = target;
    gs32_vectorsize = numbers.size();
    
    for(int s32_number : numbers)
    {
        s32_vectorsum += s32_number;
    }
    
    dfs(0, 0, s32_vectorsum);
    
    return gs32_answer;
}