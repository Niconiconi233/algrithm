#include "tools.h"

#include <vector>
#include <queue>


class Graph
{
public:
    Graph(size_t NodeSize):graph_(NodeSize){}

    void addNode(int node1, int node2)
    {
        graph_[node1].emplace_back(node2);
        graph_[node2].emplace_back(node1);
    }

    const std::vector<int>& get(int i)
    {
        return graph_[i];
    }

    int size()
    {
        return graph_.size();
    }

private:
    std::vector<std::vector<int>> graph_;

};

/*
 * 基于邻接表的广度遍历
 */
class bsf
{
public:
    bsf(int NodeSize):graph_(NodeSize), info_(NodeSize){}

    void addNode(int node1, int node2)
    {
        graph_.addNode(node1, node2);
    }


    bool path(int beg, int end)
    {
        std::queue<int> queue_;
        if(beg > graph_.size())
            return false;
        queue_.push(beg);
        info_[beg] = nodeInfo(beg, 0, true, 0);
        while(!queue_.empty())
        {
            auto pos = queue_.front();
            queue_.pop();
            auto next = graph_.get(pos);
            for(auto& i : next)
                if(!info_[i].visited)
                {
                    info_[i] = nodeInfo(i, pos, true, info_[pos].len + 1);
                    queue_.push(i);
                }
        }
        return true;
    }

    void getPath(int end)
    {
        int len = info_[end].len;
        int cur = end;
        while(len >= 0)
        {
            cout<<info_[cur].pos;
            if(--len >= 0)
            {
                cout<<"<-";
                cur = info_[cur].prev;
            }
        }

    }

private:
    struct nodeInfo
    {
        int pos;//当前节点位置
        int prev;//前置节点位置
        bool visited;
        size_t len;//长度
        nodeInfo()
            :pos(0),
            prev(0),
            visited(false),
            len(0)
            {}
        nodeInfo(int pos, int prev, bool visited, int len)
            :pos(pos),
            prev(prev),
            visited(visited),
            len(len)
        {}
    };

    Graph graph_;
    std::vector<nodeInfo> info_;

};


/*
 * 基于邻接矩阵的广度遍历
 */

class bsf2
{
public:
    bsf2()
        :vector_(map_.size(), std::vector<info>(map_[0].size()))
    {}

    using position = std::pair<size_t, size_t>;
    bool path(size_t begx, size_t begy, size_t endx, size_t endy)
    {
        std::queue<position> queue_;
        if(!map_[begx][begy])
            return false;
        queue_.emplace(begx, begy);
        vector_[begx][begy] = info(begx, begy, 0, 0, true, 0);
        while(!queue_.empty())
        {
            auto pos = queue_.front();
            queue_.pop();
            if(up(pos.first, pos.second))
            {
                if(!vector_[pos.first - 1][pos.second].visited)
                {
                    queue_.emplace(pos.first - 1, pos.second);
                    vector_[pos.first - 1][pos.second] = info(pos.first - 1, pos.second, pos.first, pos.second, true, vector_[pos.first][pos.second].len + 1);
                }
            }
            if(down(pos.first, pos.second))
            {
                if(!vector_[pos.first + 1][pos.second].visited)
                {
                    queue_.emplace(pos.first + 1, pos.second);
                    vector_[pos.first + 1][pos.second] = info(pos.first + 1, pos.second, pos.first, pos.second, true, vector_[pos.first][pos.second].len + 1);
                }
            }
            if(left(pos.first, pos.second))
            {
                if(!vector_[pos.first][pos.second - 1].visited)
                {
                    queue_.emplace(pos.first, pos.second - 1);
                    vector_[pos.first][pos.second - 1] = info(pos.first, pos.second - 1, pos.first, pos.second, true, vector_[pos.first][pos.second].len + 1);
                }
            }
            if(right(pos.first, pos.second))
            {
                if(!vector_[pos.first][pos.second + 1].visited)
                {
                    queue_.emplace(pos.first, pos.second + 1);
                    vector_[pos.first][pos.second + 1] = info(pos.first, pos.second + 1, pos.first, pos.second, true, vector_[pos.first][pos.second].len + 1);
                }
            }
        }
        return true;

    }

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

    std::vector<std::vector<int>> map_{
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 1, 1, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 1, 1, 1, 1},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 1}};

    std::vector<std::vector<info>> vector_;

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
    /*bsf bsf_(7);
    bsf_.addNode(0, 1);
    bsf_.addNode(0, 2);
    bsf_.addNode(0, 6);
    bsf_.addNode(0, 5);
    bsf_.addNode(5, 3);
    bsf_.addNode(5, 4);
    bsf_.addNode(3, 4);
    bsf_.addNode(4, 6);

    cout<< std::boolalpha << bsf_.path(3, 2) << std::noboolalpha<<endl;

    bsf_.getPath(1);*/

    bsf2 bs;
    cout<< std::boolalpha << bs.path(0, 0, 9, 9) << std::noboolalpha<<endl;
    bs.getPath(9, 9);
    cout<<endl;
    bs.getPath(0, 3);
    cout<<endl;
    bs.getPath(9, 1);

    return 0;

}

