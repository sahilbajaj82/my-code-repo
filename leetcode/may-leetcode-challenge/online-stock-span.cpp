class StockSpanner {
    stack<pair<int,int>>s;
    int index;
public:
    StockSpanner() {
        index=-1;
    }
    
    int next(int price) {
        index++;
        while(!s.empty()) {
            if(s.top().first>price) {
                int x=s.top().second;
                s.push(make_pair(price,index));
                return index-x;
            }
            else {
                s.pop();
            }
        }
        s.push(make_pair(price,index));
        return index+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
