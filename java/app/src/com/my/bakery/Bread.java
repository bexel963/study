package com.my.bakery;

import java.time.OffsetDateTime;

public class Bread {

	public OffsetDateTime expiryDate = OffsetDateTime.now().plusDays(3);
    
    boolean isFresh() {
        return OffsetDateTime.now().isBefore(expiryDate);
    }
}
