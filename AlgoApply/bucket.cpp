#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <deque>


#define BUCKETS_COUNT   (3)

struct BucketState
{
    int bucket_s[BUCKETS_COUNT];
};


using namespace std;
int bucket_init_state[BUCKETS_COUNT]  = {8, 0, 0};
int bucket_final_state[BUCKETS_COUNT] = {4, 4, 0};
int bucket_capicity[BUCKETS_COUNT] = {8, 5, 3};

void PrintStates(BucketState& cur_state)
{
    for(int i = 0; i < BUCKETS_COUNT; ++i)
    {
        cout << cur_state.bucket_s[i] << " ";
    }
    cout << endl;
}
void print_result(deque<BucketState>& state)
{
    deque<BucketState>::iterator *pIter = new deque<BucketState>::iterator;
    cout << "Find Result : " << endl;
    for (*pIter = state.begin(); *pIter != state.end(); (*pIter)++)
    {
        PrintStates(**pIter);
    }

    cout << endl << endl;
    return;
}

int is_same_bucket_state(BucketState& state1, BucketState& state2)
{
    int i = 0;
    for (i = 0; i < BUCKETS_COUNT; i++)
    {
        if (state1.bucket_s[i] != state2.bucket_s[i])
        {
            return 0;
        }
    }
    return 1;
}


int is_exist(deque<BucketState>& state, BucketState& cur_state)
{
    deque<BucketState>::iterator *pIter = new deque<BucketState>::iterator;
    for (*pIter = state.begin(); *pIter != state.end(); (*pIter)++)
    {
        if (is_same_bucket_state(**pIter, cur_state))
        {
            return 1;
        }
    }
    return 0;
}


int can_dump_water(BucketState& cur_state, int from, int to, BucketState& next_state)
{
    if ((from != to)&&(cur_state.bucket_s[from] != 0)&&(cur_state.bucket_s[to] != bucket_capicity[to]))
    {
        int i = 0;
        for (i = 0; i < BUCKETS_COUNT; i++)
        {
            next_state.bucket_s[i] = cur_state.bucket_s[i];
        }
        if ((cur_state.bucket_s[from] + cur_state.bucket_s[to]) >= bucket_capicity[to])
        {
            next_state.bucket_s[from] = (cur_state.bucket_s[from] + cur_state.bucket_s[to]) -bucket_capicity[to];
            next_state.bucket_s[to] = bucket_capicity[to];
        }
        else
        {
            next_state.bucket_s[from] = 0;
            next_state.bucket_s[to] = cur_state.bucket_s[from] + cur_state.bucket_s[to];
        }
        return 1;
    }
    return 0;
}

void search_state(deque<BucketState>& state);

void search_action(deque<BucketState>& state, BucketState& cur_state, int from, int to)
{
    BucketState next;
    if (!can_dump_water(cur_state, from, to, next))
    {
        return;
    }
    if (!is_exist(state, next))
    {
        state.push_back(next);
        search_state(state);
        state.pop_back();
    }

    return;
}

int is_final_state(BucketState& cur_state)
{
    int i = 0;
    for (i = 0; i < BUCKETS_COUNT; i++)
    {
        if (cur_state.bucket_s[i] != bucket_final_state[i])
        {
            return 0;
        }
    }
    return 1;
}

void search_state(deque<BucketState>& state)
{
    BucketState current = state.back();
    if (is_final_state(current))
    {
        print_result(state);
    }
    int i = 0;
    int j = 0;
    for (i = 0; i < BUCKETS_COUNT; i++)
    {
        for (j = 0; j < BUCKETS_COUNT; j++)
        {
            search_action(state, current, i, j);
        }
    }
}

int buckets_dump_water_demo()
{
    deque<BucketState> states;
    BucketState init_buckets;
    int i = 0;
    for (i = 0; i < BUCKETS_COUNT; i++)
    {
        init_buckets.bucket_s[i] = bucket_init_state[i];
    }

    states.push_back(init_buckets);
    search_state(states);
    return 0;
}


int main()
{
	buckets_dump_water_demo();
	return 0;
}
