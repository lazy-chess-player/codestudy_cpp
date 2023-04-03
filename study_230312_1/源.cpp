#include <iostream>
#include <map>
#include <vector>
#include <iosfwd>
#include <string>

using namespace std;
    class cmp {
    public:
        bool operator ()(const Interval& a, const Interval& b) const {
            return a.end <= b.end;
        }
    };
    class Solution {
    public:
        /**
         * @param airplanes: An interval array
         * @return: Count of airplanes are in the sky.
         */
        static bool cmpfunc(const Interval& a, const Interval& b)
        {
            if (a.start != b.start)
                return a.start < b.start;
            else
                return a.end < b.end;
        }
        int countOfAirplanes(vector<Interval>& airplanes) {
            // write your code here
            sort(airplanes.begin(), airplanes.end(), cmpfunc);
            set<Interval, cmp> tmp;

            int rt = 0;
            for (auto a : airplanes)
            {
                if (!tmp.empty() && a.start >= tmp.begin()->end)
                    tmp.erase(tmp.begin());
                tmp.insert(a);
                rt = max(rt, (int)tmp.size());
            }
            return rt;
        }
    };