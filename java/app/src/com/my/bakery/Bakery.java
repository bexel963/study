package com.my.bakery;
 
import java.time.OffsetDateTime;
  
import java.util.ArrayList;
import java.time.OffsetDateTime;
 
public class Bakery {
	
    ArrayList<Bread> breads = new ArrayList<>();
    
    public void addBread(Bread bread) {
        this.breads.add(bread);
    }
    
    void removeExpiredBread() {
        for (Bread bread : this.breads) {
            if (!bread.isFresh()) {
                this.breads.remove(bread);
                return;
            }
        }
    }
    
    void recycleBreads() {
        for (Bread bread : this.breads) {
            bread.expiryDate = OffsetDateTime.now().plusDays(3);
        }
    }
}
 
