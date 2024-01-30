//bruteforce
class LRUCache {
public:
    
    
    vector<pair<int,int>>cache ;
    int s ;
    
    LRUCache(int c) {
        s = c ;
    }
    
    int get(int key) {
        
        for ( int i = 0 ; i < size(cache) ; i++ )
        {
            if ( cache[i].first == key )
            {
                int val = cache[i].second ;
                cache.erase(begin(cache)+i) ;
                cache.push_back({key,val}) ;
                return val ;
            }
        }
        return -1 ;
    }
    
    void put(int key, int value) 
    {
        for( int i = 0 ; i < size(cache) ; i++ ) 
        {
            if( cache[i].first == key ) 
            {
                cache.erase(begin(cache)+i) ;
                cache.push_back({key, value}) ;
                return ;
            }
        }
        
        if( size(cache) == s ) 
        {
            cache.erase(cache.begin()) ;
            cache.push_back({key, value}) ;
            
        }
        else 
            cache.push_back({key, value});   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


//USING DLL APPROACH 2
class LRUCache {
public:
    
    list<int>dll ;
    int n ;
    map<int, pair<list<int>::iterator, int>> cache;
    
    
    void shiftRecentlyUsed( int key )
    {
        dll.erase( cache[key].first ) ;
        dll.push_front( key ) ;
        cache[key].first = begin(dll) ;
        
    }
    
    LRUCache(int c) {
        n = c ;
    }
    
    int get(int key) {
        
        if ( cache.find(key) == end(cache) )
                return -1 ;
        
        shiftRecentlyUsed( key ) ;
        return cache[key].second ;
    }
    
    void put(int key, int value) 
    {
        if ( cache.find(key) == end(cache))
        {
            dll.push_front(key) ;
            cache[key] = { begin(dll), value } ;
            n-- ;
        }
        else
        {
            cache[key].second = value ;
            shiftRecentlyUsed(key) ;
        }
        if( n < 0) 
        {
            cache.erase(dll.back()) ;
            dll.pop_back() ;
            n++ ;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
