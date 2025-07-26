class StockSpanner {
private:
    stack<pair<int,int>>box;
public:
    StockSpanner() {//no need to impliment
    }
    
    int next(int price) {
        int x = 1;

        while(!box.empty()&&box.top().second <= price ){
            x += box.top().first;
            box.pop();
        }

        //jo abhi call ayi h use puch krna h
        box.push({x,price});

        return x;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */