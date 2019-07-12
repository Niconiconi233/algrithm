//
// Created by soft01 on 19-7-12.
//

#include "tools.h"

#include <vector>
#include <stack>

/*
 * 深度遍历
 */

class dsf
{
public:
    dsf()
        :vector_(map_.size(), std::vector<info>(map_[0].size())){}

    using position = std::pair<size_t, size_t>;

    bool path(size_t begx, size_t begy, size_t endx, size_t endy)
    {
        std::stack<position> stack_;
        if(!map_[begx][begy])
            return false;
        stack_.emplace(begx, begy);
        vector_[begx][begy] = info(begx, begy, 0, 0, true, 0);
        while(!stack_.empty())
        {
            auto pos = stack_.top();
            auto oldpos = pos;//存储节点
            while(up(pos.first, pos.second) && !vector_[pos.first - 1][pos.second].visited)
            {
                stack_.emplace(pos.first - 1, pos.second);
                vector_[pos.first - 1][pos.second] = info(pos.first - 1, pos.second, pos.first, pos.second, true, vector_[pos.first][pos.second].len + 1);
                if(up(pos.first, pos.second))
                    pos.first = pos.first - 1;
            }
            while(down(pos.first, pos.second) && !vector_[pos.first + 1][pos.second].visited)
            {

                stack_.emplace(pos.first + 1, pos.second);
                vector_[pos.first + 1][pos.second] = info(pos.first + 1, pos.second, pos.first, pos.second, true, vector_[pos.first][pos.second].len + 1);
                if(down(pos.first, pos.second))
                    pos.first = pos.first + 1;
            }
            while(right(pos.first, pos.second) && !vector_[pos.first][pos.second + 1].visited)
            {

                stack_.emplace(pos.first, pos.second + 1);
                vector_[pos.first][pos.second + 1] = info(pos.first, pos.second + 1, pos.first, pos.second, true, vector_[pos.first][pos.second].len + 1);
                if(right(pos.first, pos.second))
                    pos.second = pos.second + 1;
            }
            while(left(pos.first, pos.second) && !vector_[pos.first][pos.second - 1].visited)
            {

                stack_.emplace(pos.first, pos.second - 1);
                vector_[pos.first][pos.second - 1] = info(pos.first, pos.second - 1, pos.first, pos.second, true, vector_[pos.first][pos.second].len + 1);
                if(left(pos.first, pos.second))
                    pos.second -= 1;
            }
            if(oldpos == stack_.top())//如果方向没有改变 则为死路 回退
                stack_.pop();
        };
        return true;
    }

    /*
     * 获取某节点路径
     */
    void getPath(size_t endx, size_t endy)
    {
        int len = vector_[endx][endy].len;
        while(len >= 0)
        {
            cout<<"<"<<vector_[endx][endy].cur.first<<","<<vector_[endx][endy].cur.second<<">";
            if(--len >= 0) {
                cout<<" <- ";
                size_t x = endx;
                endx = vector_[endx][endy].pre.first;
                endy = vector_[x][endy].pre.second;
            }

        }
    }

    /*
     * 打印地图
     */
    void pv()
    {
        for(size_t i = 0; i < map_.size(); ++i)
        {
            for(size_t j = 0; j < map_[i].size(); ++j)
                cout<<"<"<<vector_[i][j].pre.first<<","<<vector_[i][j].pre.second<<"> "<<vector_[i][j].visited<<" "<<vector_[i][j].len<<" ";
            cout<<endl;
        }
    }

private:
    struct info
    {
        std::pair<size_t, size_t> cur;
        std::pair<size_t, size_t> pre;
        bool visited;
        size_t len;
        info(size_t curx, size_t cury, size_t prex, size_t prey, bool visited, size_t len)
                :cur(curx, cury),
                 pre(prex, prey),
                 visited(visited),
                 len(len)
        {}
        info()
                :cur(0, 0),
                 pre(0, 0),
                 visited(false),
                 len(0)
        {}
    };

    std::vector<std::vector<int> > map_{
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 1, 1, 1, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 1, 1, 1, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1}};

    std::vector<std::vector<info> > vector_;

    bool up(int r, int l)
    {
        assert(r >= 0 && r < static_cast<int>(map_.size()));
        assert(l >= 0 && l < static_cast<int>(map_[r].size()));
        if((r - 1) < 0)
            return false;
        else
            return map_[r - 1][l];

    }

    bool down(int r, int l)
    {
        assert(r >= 0 && r < static_cast<int>(map_.size()));
        assert(l >= 0 && l < static_cast<int>(map_[r].size()));
        if((r + 1) >= static_cast<int>(map_.size()))
            return false;
        else
            return map_[r + 1][l];
    }

    bool right(int r, int l)
    {
        assert(r >= 0 && r < static_cast<int>(map_.size()));
        assert(l >= 0 && l < static_cast<int>(map_[r].size()));
        if((l + 1) >= static_cast<int>(map_[r].size()))
            return false;
        else
            return map_[r][l + 1];
    }

    bool left(int r, int l)
    {
        assert(r >= 0 && r < static_cast<int>(map_.size()));
        assert(l >= 0 && l < static_cast<int>(map_[r].size()));
        if((l - 1) < 0)
            return false;
        else
            return map_[r][l - 1];
    }

};

int main()
{
    dsf ds;
    ds.path(0,0,9,9);
    ds.pv();
    cout<<endl;
    ds.getPath(9, 9);
    return 0;
}

