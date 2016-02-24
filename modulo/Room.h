//
//  Room.h
//  modulo
//
//  Created by mario on 16/2/24.
//  Copyright © 2016年 mario. All rights reserved.
//
#ifndef Room_h
#define Room_h
#include "Block.h"

struct Room
{
    void init(vector<vector<int>> data,int modu)
    {
        room = data;
        m = room[0].size();
        n = room.size();
        mod = modu;
    }
    bool isFit(const Block& block)
    {
        if(m >= block.w && n >= block.h)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isZeroAt(int x,int y)
    {
        //tryTimes++;
        return (room[y][x] % mod) == 0;
    }
    bool canRight(const Block& block)
    {
        return block.x + block.w + 1 <= m;
    }
    bool canDown(const Block& block)
    {
        return block.y + block.h + 1 <= n;
    }
    bool canRightWithLimitArea(const Block& block,pair<int,int> area)
    {
        bool ret = block.x + block.w + 1 <= m;
        ret &= (block.y < area.second ? block.x <= m : block.x <= area.first);
        return ret;
    }
    bool canDownWithLimitArea(const Block& block,pair<int,int> area)
    {
        bool ret = block.y + block.h + 1 <= n;
        ret &= (block.y < area.second ? block.x <= m : block.x <= area.first);
        
        return ret;
    }
    void add(const Block& block)
    {
        for(int i = 0; i < block.w; ++i)
        {
            for(int j = 0; j < block.h;++j)
            {
                room[j + block.y][i + block.x] += block.block[j][i];
            }
        }
    }
    void remove(const Block& block)
    {
        for(int i = 0; i < block.w; ++i)
        {
            for(int j = 0; j < block.h;++j)
            {
                room[j + block.y][i + block.x] -= block.block[j][i];
            }
        }
    }
    
    bool isZero()
    {
        bool ret = true;
        for(int j = 0;j < n;++j)
        {
            if(ret == false)
                break;
            for(int i = 0;i < m;++i)
            {
                if((room[j][i] % mod) != 0)
                {
                    ret = false;
                    break;
                }
            }
        }
        //tryTimes++;
#ifdef PrintProgess
        //        double currPercent = (double)tryTimes * 100 / possibility;
        //        if(currPercent >= percent +  1.0)
        //        {
        //            cout << (int)currPercent << "%," << tryTimes << " / " << possibility << endl;
        //            percent = currPercent;
        //        }
#endif
        return ret;
    };
    bool isZeroWithLimitArea(pair<int,int> area)
    {
        bool ret = true;
        if(area.second == 0)
        {
            for(int i = 0;i < area.first;++i)
            {
                if((room[0][i] % mod) != 0)
                {
                    ret =false;
                    break;
                }
            }
        }
        else
        {
            for(int i = 0;i <= area.second && ret;++i)
            {
                int len = (i == area.second ? area.first : m);
                for(int j = 0;j < len;++j)
                {
                    if((room[i][j] % mod) != 0)
                    {
                        ret =false;
                        break;
                    }
                }
            }
        }
        //tryTimes++;
        return ret;
    }
    void print()
    {
        cout << "room" << endl;
        for(int i = 0;i < room.size();++i)
        {
            cout << "[";
            for(int j = 0;j < room[0].size();++j)
            {
                cout << room[i][j];
                if(j != room.size())
                {
                    cout << ",";
                }
            }
            cout << "]" <<endl;
        }
    }
    
    int m;
    int n;
    int mod;
    vector<vector<int>> room;
};


#endif /* Room_h */
