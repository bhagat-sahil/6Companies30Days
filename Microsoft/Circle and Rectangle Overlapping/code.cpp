class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) 
    {
        //CALCULATING THE NEAREST x FROM CENTRE OF THE CIRCLE
        int nearestX = max( x1, min( xCenter, x2 )) ;
        ////CALCULATING THE NEAREST y FROM CENTRE OF THE CIRCLE
        int nearestY = max( y1, min( yCenter, y2 )) ;
        
        //CLOSEST COORDINATE IN RECTANGLE FROM THE CENTER OF CIRCLE
        
        int x = nearestX - xCenter ;
        int y = nearestY - yCenter ;
        
        
        float distance = x*x + y*y ;
      
        if ( distance <= radius* radius )   return true ;
        return false ;
        
        
    }
};
