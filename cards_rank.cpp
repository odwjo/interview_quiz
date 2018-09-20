#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;
using Card = pair<int, int>;
using Lc = deque<Card>;
const int n = 5;

template<typename T>
void link(deque<T> &li){
    if(li.empty())
        return ;
    auto temp = li.front();
    li.pop_front();
    li.push_back(temp);
}

int main(){
    deque<int> cards(n);
    vector<Card> mem;
    mem.reserve(n);

    for(int i = 0;i != n;++ i){
        cards[i] = i;
    }

    int cardnum = n;
    while(cardnum){
        mem.push_back(Card(cards.front(), cardnum --));
        cards.pop_front();
        link(cards);
    }

    sort(mem.begin(), mem.end(),
         [](const Card& c1, const Card& c2){return c1.first < c2.first;});
    for(int i = 0; i != n; ++ i){
        cout << mem[i].first << " : " << mem[i].second << '\n';
    }
    return 0;
}
