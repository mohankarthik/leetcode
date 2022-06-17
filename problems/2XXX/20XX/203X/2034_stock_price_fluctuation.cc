#include "../../../../common/Includes.h"

class StockPrice {
private:
    map<int, int> ticker;
    multiset<int> store;
    
public:
    StockPrice() {}
    
    void update(int timestamp, int price) {
        if (ticker.count(timestamp))
            store.erase(store.find(ticker[timestamp]));
        ticker[timestamp] = price;
        store.insert(price);
    }
    
    int current() {
        return ticker.rbegin()->second;
    }
    
    int maximum() {
        return *store.rbegin();
    }
    
    int minimum() {
        return *store.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */