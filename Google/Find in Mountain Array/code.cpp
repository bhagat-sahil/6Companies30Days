/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    
    int findPeak( int s, int e, MountainArray &mArray )
    {
        while ( s < e )
        {
            int m = ( s + e )/ 2 ;
            if ( mArray.get(m) > mArray.get(m+1) )    e = m ;
            else s=m+1 ;
        }
        return s ;
    }
    
    int findTargetLeft( int s, int e, MountainArray & mArray, int target )
    {
        while ( s <= e )
        {
            int m = ( s + e )/ 2 ;
            int data = mArray.get(m) ;
            if ( data == target )  return m ; 
            if ( data < target ) s = m + 1 ;
            else e = m - 1 ;
        }
        return -1 ;
    }
    int findTargetRight( int s, int e, MountainArray & mArray, int target )
    {
        while ( s <= e )
        {
            int m = ( s + e )/ 2 ;
            int data = mArray.get(m) ;
            if ( data == target )  return m ; 
            if ( data < target ) e = m - 1 ;
            else s = m + 1 ;
        }
        return -1 ;
    }
    
    
    
    int findInMountainArray(int target, MountainArray &m ) 
    {
        int n = m.length()  ;
        int peakIndex = findPeak( 0, n-1, m ) ;
        
        int ans = findTargetLeft( 0, peakIndex, m , target ) ;
        
        if ( ans != -1 ) return ans ;
        else 
            return findTargetRight( peakIndex, n-1, m, target ) ;
        
    }
};
