package com.my.entity;

import java.time.OffsetDateTime;
import java.util.UUID;

public class BaseEntity {

	private UUID id;
	private OffsetDateTime createdDateTime;
	private OffsetDateTime modifiedDateTime;
	
	BaseEntity(UUID id, OffsetDateTime createdDateTime, OffsetDateTime modifiedDateTime){
		this.id = id;
		this.createdDateTime = createdDateTime;
		this.modifiedDateTime = modifiedDateTime;
	}
	
	public UUID getID() {
		return this.id;
	}
	
	public OffsetDateTime getCreatedDateTime() {
		return this.createdDateTime;
	}
	public OffsetDateTime getModifiedDateTime() {
		return this.modifiedDateTime;
	}
	public void setModifiedDateTime(OffsetDateTime modifiedDateTime) {
		this.modifiedDateTime = modifiedDateTime;
	}
}
