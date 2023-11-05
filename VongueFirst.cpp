#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <math.h>
#include <bitset>
#include <cstring>
#include <unordered_set>
#include <ctime>

typedef long long ll;
typedef unsigned long long ull;

#define eol '\n'
#define FastIO(){ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define INF 1e9 + 7
#define YES cout << "YES" << eol;#define NO cout << "NO" << eol;
#define all(x) x.begin(), x.end()

template <class T> void print(T & g){for (auto el: g){std::cout << el << " ";} std::cout << eol;}

//int gcd (long long a, int b) {return b ? gcd (b, a % b) : a;} // наибольший общий делитель
//int lcm (long long a, int b) {return a / gcd (a, b) * b;} // наименьшее общее кратное

//unsigned long long gcd(ull a, ull b) { return b?gcd(b,a%b):a;}
//unsigned long long lcm(ull a, ull b) { return a/gcd(a,b) * b;}

using namespace std;

//void print(vector <int> gcout) { for (int zout = 0; zout < gcout.size(); zout++) cout << gcout[zout] << " "; }

//int TrunsferNumbers(int x, int k) {int c = 0;while (x > 0) {if (x % k == 0) c++;x /= k;} return c; }

int n;
int maxp = 0;

vector <int> max_route;
vector <vector <int>> g;
vector <long double> points;
vector <vector <int>> times(12, vector <int> (12, -1));



int counter(vector <int> vs) {
    int ans = 0;
    unordered_set <int> set_dots;

    for (auto c:vs) set_dots.insert(c);
    for (auto c:set_dots) ans += points[c];


    return ans;
}

void graph_traversal(int t, int v, vector <int> visited_v, vector <int> dots_cnt) {
    if ((v == 0) and (t <= 180)) {
        int point = counter(visited_v);
        if (point > maxp) {
            maxp = point;
            max_route = visited_v;
            cout << point << eol;
        }
    }

    if (t >= 180) return;
    else {
        for (auto c: g[v]) {
            if (dots_cnt[c] > 10) return;
            dots_cnt[c]++;
            int updated_time = t + times[v][c];
            vector <int> updated_visited;
            updated_visited.push_back(c);
            for (auto x: visited_v) {
                updated_visited.push_back(x);
            }
            graph_traversal(updated_time, c, updated_visited, dots_cnt);

        }

    }


}

int main() {

    n = 12; //n - кол-во КП

    //Представим наш маршрут как граф подвешенный за точку старта, то есть за нулевую вершину. Затем пронумеруем вершины по порядку
    g = {{1}, {0, 2, 3}, {1, 4, 5, 6}, {1, 7}, {2, 8}, {2, 6}, {2, 5}, {3, 9, 10}, {4, 9}, {7, 8}, {7, 11}, {10}};

    points = {0, 1, 3, 1, 3, 1, 1, 2, 3, 2, 6, 1};

    //длина ребра - время
    times[0][1] = 5;
    times[1][2] = 45;
    times[1][3] = 15;
    times[2][4] = 40;
    times[2][5] = 2.5;
    times[2][6] = 2.5;
    times[3][7] = 10;
    times[4][8] = 20;
    times[5][6] = 2.5;
    times[7][10] = 72;
    times[7][9] = 12;
    times[8][9] = 25;
    times[10][11] = 20;

    times[1][0] = 5;
    times[2][1] = 45;
    times[3][1] = 15;
    times[4][2] = 40;
    times[5][2] = 2.5;
    times[6][2] = 2.5;
    times[7][3] = 10;
    times[8][4] = 20;
    times[6][5] = 2.5;
    times[10][7] = 72;
    times[9][7] = 12;
    times[9][8] = 25;
    times[11][10] = 20;


    vector <int> dots_cnt(12);
    vector <int> empt;
    empt.push_back(0);


    graph_traversal(0, 0, empt, dots_cnt);


    cout << "answer: " << maxp << eol;
    print(max_route);

    return 0;

}